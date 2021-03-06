# Digi BSP default providers
PREFERRED_PROVIDER_jpeg-native ?= "jpeg-native"
PREFERRED_PROVIDER_u-boot ??= "u-boot-dey"
PREFERRED_PROVIDER_virtual/bootloader ??= "u-boot-dey"
PREFERRED_PROVIDER_virtual/kernel ??= "linux-dey"
PREFERRED_PROVIDER_virtual/xserver = "xserver-xorg"

#
# Linux and U-Boot supported versions:
#
# Platform      Linux              U-Boot
# -------------------------------------------------
# ccardimx28    3.10               2013.01
# ccimx6        3.14               2015.04
# ccimx6ul      4.1                2015.04
#

# Help variables used in recipes
HAVE_WIFI       = "${@bb.utils.contains('MACHINE_FEATURES', 'wifi', '1', '', d)}"
HAVE_SECOND_ETH = "${@bb.utils.contains('MACHINE_FEATURES', 'second-eth', '1', '', d)}"
HAVE_BT         = "${@bb.utils.contains('MACHINE_FEATURES', 'bluetooth', '1', '', d)}"
HAVE_1WIRE      = "${@bb.utils.contains('MACHINE_FEATURES', '1-wire', '1', '', d)}"
HAVE_GUI        = "${@bb.utils.contains('DISTRO_FEATURES', 'x11', '1', '', d)}"
HAVE_EXAMPLE    = "${@bb.utils.contains('IMAGE_FEATURES', 'dey-examples', '1', '', d)}"

#
# Ethernet configuration used in recipes
#
# ETHx_MODE, WLANx_MODE accepted values: 'dhcp' or 'static'
#
ETH0_MODE            ?= "static"
ETH0_STATIC_IP       ?= "192.168.42.30"
ETH0_STATIC_NETMASK  ?= "255.255.255.0"
ETH0_STATIC_GATEWAY  ?= "192.168.42.1"
ETH1_MODE            ?= "static"
ETH1_STATIC_IP       ?= "192.168.44.30"
ETH1_STATIC_NETMASK  ?= "255.255.255.0"
WLAN0_MODE           ?= "static"
WLAN0_STATIC_IP      ?= "192.168.43.30"
WLAN0_STATIC_NETMASK ?= "255.255.255.0"
P2P0_STATIC_IP       ?= "192.168.45.30"
P2P0_STATIC_NETMASK  ?= "255.255.255.0"

# Digi BSP default settings
IMAGE_CLASSES = "image_types_digi"

# Do not enable console on VT (see sysvinit-inittab recipe)
USE_VT = "0"

# Add the machine variant to the valid machine override
MACHINE_VARIANT ?= ""
MACHINEOVERRIDES .= "${@['', ':${MACHINE_VARIANT}']['${MACHINE_VARIANT}' != '']}"
