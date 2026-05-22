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

echo "[1/4] Installing dependencies..."
apt install -y build-essential linux-headers-$KERNEL dkms

echo "[2/4] Setting up DKMS..."
mkdir -p /usr/src/ipts-1.0
cp $SCRIPT_DIR/*.c $SCRIPT_DIR/*.h $SCRIPT_DIR/Makefile $SCRIPT_DIR/dkms.conf /usr/src/ipts-1.0/

echo "[3/4] Building and installing module..."
dkms add -m ipts -v 1.0 2>/dev/null || true
dkms build -m ipts -v 1.0
dkms install -m ipts -v 1.0 --force

echo "[4/4] Configuring..."
echo 'ipts' > /etc/modules-load.d/ipts.conf
systemctl mask iptsd@* 2>/dev/null || true

if ! grep -q "iommu=pt" /etc/default/grub; then
    sed -i 's/GRUB_CMDLINE_LINUX_DEFAULT="\(.*\)"/GRUB_CMDLINE_LINUX_DEFAULT="\1 iommu=pt"/' /etc/default/grub
    update-grub
    echo "NOTE: Reboot required for iommu=pt to take effect."
fi

echo ""
echo "Done! Reboot to activate touch support."
