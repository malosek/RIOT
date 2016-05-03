# name of your application
APPLICATION = hello-world

# If no BOARD is found in the environment, use this default:
BOARD ?= native

# This has to be the absolute path to the RIOT base directory:
RIOTBASE ?= $(CURDIR)/../..

# Add also the shell, some shell commands
#USEMODULE += shell
#USEMODULE += shell_commands
USEMODULE += ps

#USEMODULE += gnrc_netdev_default
#USEMODULE += auto_init_gnrc_netif
#USEMODULE += gnrc_ipv6
#USEMODULE += gnrc_ndp
#USEMODULE += gnrc_ndp_node
#USEMODULE += gnrc_icmpv6_echo
#USEMODULE += gnrc_sixlowpan_nd_router
#USEMODULE += gnrc_sixlowpan_iphc

USEMODULE += saul_reg
USEMODULE += saul_default
USEMODULE += auto_init_saul

USEMODULE += xtimer

CFLAGS += -DGNRC_IPV6_NETIF_ADDR_NUMOF=4

ifneq (,$(filter native,$(BOARD)))
    CFLAGS += -DGNRC_PKTBUF_SIZE=2048 -DGNRC_IPV6_NC_SIZE=1
else
    CFLAGS += -DGNRC_PKTBUF_SIZE=512 -DGNRC_IPV6_NC_SIZE=0
endif


# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
CFLAGS += -DDEVELHELP

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 0

include $(RIOTBASE)/Makefile.include
