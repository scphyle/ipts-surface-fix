#!/bin/bash
set -e

echo "=== IPTS Surface Touchscreen Fix ==="
echo ""

# Check we're running as root
if [ "$EUID" -ne 0 ]; then
    echo "Please run as root (sudo ./install.sh)"
    exit 1
fi

KERNEL=$(uname -r)
BUILD_DIR=/tmp/ipts-build
MODULE_DIR=/lib/modules/$KERNEL/kernel/drivers/hid

echo "[1/6] Installing dependencies..."
apt install -y git build-essential linux-headers-$KERNEL

echo "[2/6] Fetching IPTS driver source from linux-surface..."
rm -rf $BUILD_DIR
git clone https://github.com/linux-surface/kernel.git --depth=1 --filter=blob:none --sparse $BUILD_DIR
cd $BUILD_DIR
git sparse-checkout disable

echo "[3/6] Locating IPTS driver..."
IPTS_DIR=$(find $BUILD_DIR -path "*/drivers/hid/ipts" -type d)
if [ -z "$IPTS_DIR" ]; then
    echo "ERROR: Could not find IPTS driver in linux-surface kernel tree"
    exit 1
fi
cd $IPTS_DIR

echo "[4/6] Applying patch..."
SCRIPT_DIR=$(dirname $(realpath $0))
patch -p5 < $SCRIPT_DIR/0001-fix-ipts-report-size-for-surface-pro-firmware.patch

echo "[5/6] Building module..."
make -C /lib/modules/$KERNEL/build M=$IPTS_DIR \
    "obj-m=ipts.o" \
    "ipts-objs=cmd.o control.o eds1.o eds2.o hid.o main.o mei.o receiver.o resources.o thread.o" \
    modules

echo "[6/6] Installing..."
cp $IPTS_DIR/ipts.ko $MODULE_DIR/
depmod -a
echo 'ipts' > /etc/modules-load.d/ipts.conf
update-initramfs -u

echo ""
echo "Done! Please reboot to load the module."
echo "If touchscreen doesn't work after reboot, make sure iommu=pt is set in your kernel boot parameters."
