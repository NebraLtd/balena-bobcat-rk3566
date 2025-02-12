IMAGE_FSTYPES:append = " balenaos-img"

# add the dtb, extlinux.conf and u-boot binaries to rootfs /boot directory
IMAGE_INSTALL:append = " \
    kernel-devicetree \
"

# Customize balenaos-img
BALENA_IMAGE_BOOTLOADER = "virtual/bootloader"

IMAGE_CMD:balenaos-img:append () {
    dd if=${DEPLOY_DIR_IMAGE}/idbloader.bin of=${BALENA_RAW_IMG} conv=notrunc bs=512 seek=64
    dd if=${DEPLOY_DIR_IMAGE}/uboot.img of=${BALENA_RAW_IMG} conv=notrunc bs=512 seek=16384
}

# We need some space before the boot partition in order to write the boot binaries, as per http://rockchip.wikidot.com/partitions
# (we do not use GPT though and we only write idbloader.bin, u-boot.img and trust.img as opposed to the above wiki)
DEVICE_SPECIFIC_SPACE = "40960"

IMAGE_ROOTFS_MAXSIZE = "2621440"
IMAGE_ROOTFS_EXTRA_SPACE = "262144"
