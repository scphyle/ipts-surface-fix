#!/bin/bash
set -e

echo "=== IPTS Surface Touchscreen Fix for Linux kernel 7+ ==="
echo ""

KERNEL=$(uname -r)
SCRIPT_DIR=$(dirname $(realpath $0))

if [ "$EUID" -ne 0 ]; then
    echo "Please run as root (sudo ./install.sh)"
    exit 1
fi

if [ -f "/usr/lib/modules/$KERNEL/kernel/drivers/hid/ipts.ko" ] && \
   [ -f "/lib/modules/$KERNEL/kernel/drivers/hid/ipts.ko" ]; then
    echo "IPTS module already installed for kernel $KERNEL, skipping build."
else
    echo "[1/3] Installing dependencies..."
    apt install -y build-essential linux-headers-$KERNEL

    echo "[2/3] Building IPTS module..."
    cd $SCRIPT_DIR
    make -C /lib/modules/$KERNEL/build M=$SCRIPT_DIR \
        "obj-m=ipts.o" \
        "ipts-objs=cmd.o control.o eds1.o eds2.o hid.o main.o mei.o receiver.o resources.o thread.o" \
        modules

    echo "[3/3] Installing..."
    mkdir -p /usr/lib/modules/$KERNEL/kernel/drivers/hid
    mkdir -p /lib/modules/$KERNEL/kernel/drivers/hid
    cp $SCRIPT_DIR/ipts.ko /usr/lib/modules/$KERNEL/kernel/drivers/hid/
    cp $SCRIPT_DIR/ipts.ko /lib/modules/$KERNEL/kernel/drivers/hid/
    depmod -a
    echo 'ipts' > /etc/modules-load.d/ipts.conf
    update-initramfs -u
fi

# Add iommu=pt if not present
if ! grep -q "iommu=pt" /etc/default/grub; then
    sed -i 's/GRUB_CMDLINE_LINUX_DEFAULT="\(.*\)"/GRUB_CMDLINE_LINUX_DEFAULT="\1 iommu=pt"/' /etc/default/grub
    update-grub
    echo "NOTE: Reboot required for iommu=pt to take effect."
fi

echo ""
echo "Done! Reboot to activate touch support."
systemctl mask iptsd@* 2>/dev/null || true
