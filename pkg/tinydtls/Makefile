PKG_NAME=tinydtls
PKG_URL=git://github.com/rfuentess/TinyDTLS.git
# PKG_VERSION=RIOT-OS
PKG_VERSION=643d1b932e9a956ee4d5bb0e0d9770a96c2056c0 
PKG_BUILDDIR ?= $(BINDIRBASE)/pkg/$(BOARD)/$(PKG_NAME)

.PHONY: all

all: git-download
	$(MAKE) -C $(PKG_BUILDDIR)

include $(RIOTBASE)/pkg/pkg.mk