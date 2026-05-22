# IPTS Surface Touchscreen Fix for Linux Kernel 7+

Fixes touchscreen input on Microsoft Surface devices running Linux kernel 7+ (e.g. Ubuntu 26.04+) without the [linux-surface](https://github.com/linux-surface/kernel) custom kernel.

## Problem

When running a mainline kernel (7.0+), the IPTS touchscreen driver fails with:
hid-generic: Event data for report 65 was too short (7491 vs 7488)
ipts: Failed to process buffer: -22
This is caused by a mismatch between the HID report buffer size hardcoded in the driver (`7485`) and the actual size sent by certain Surface firmware versions. This patch adjusts the buffer size to `3072` which accommodates the variable-length frames this firmware sends.

## Tested On

- Microsoft Surface Pro (2015, BIOS 239.871.768) — Ubuntu 26.04, kernel 7.0.0-15-generic

## Disclaimer

⚠️ This is an unofficial patch based on reverse engineering the HID report sizes for a specific firmware version. It may not work on all Surface devices or firmware versions. Use at your own risk. Always keep a bootable USB or alternate kernel available.

This patch is not affiliated with the [linux-surface project](https://github.com/linux-surface/kernel) — if your device is supported there, use that instead.

## Prerequisites

- Ubuntu 24.04+ or equivalent
- Linux kernel 7.0+
- `build-essential`, `dkms`, `git`, `linux-headers-$(uname -r)`
- `iommu=pt` kernel boot parameter (add to `GRUB_CMDLINE_LINUX_DEFAULT` in `/etc/default/grub`, then run `sudo update-grub`)

## Installation

```bash
git clone https://github.com/scphyle/ipts-surface-fix
cd ipts-surface-fix
chmod +x install.sh
sudo ./install.sh
```

## What It Does

1. Sparse-clones the IPTS HID driver from the linux-surface kernel tree
2. Applies a patch to fix the HID report buffer size
3. Builds the driver as a kernel module against your running kernel
4. Installs it and configures it to load on boot

## Uninstall

```bash
sudo rmmod ipts
sudo rm /lib/modules/$(uname -r)/kernel/drivers/hid/ipts.ko
sudo depmod -a
sudo rm /etc/modules-load.d/ipts.conf
```

## Contributing

If this works (or doesn't) on your device, please open an issue with your Surface model, firmware version (`sudo dmidecode -s bios-version`), and kernel version. That'll help build a compatibility matrix.

## License

Driver source is GPL-2.0-or-later per the original linux-surface project.
