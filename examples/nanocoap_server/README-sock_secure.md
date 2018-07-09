# Using nanocoap_server with sock_secure

This document describes how to set up the nanocoap_server example to work with
sock_secure in a native environment. We follow the basic outline of the main
README for nanocoap_server, including use of libcoap as the client.

## Building nanocoap_server

### Example Makefile

To activate sock_secure, first uncomment the snippet below in the server
Makefile. Notice that it uses the keys already defined in the sock_secure module.

```
USEMODULE += sock_secure

ifneq (,$(filter sock_secure,$(USEMODULE)))
  USEPKG += tinydtls
  INCLUDES += -I$(APPDIR)/../sock_secure/keys
  CFLAGS += -DTHREAD_STACKSIZE_MAIN=\(3*THREAD_STACKSIZE_DEFAULT\)
  #CFLAGS += -DTINYDTLS_DEBUG

  #Just for parsing when ENABLE_DEBUG is used
  USEMODULE += od
endif
```
Enable the tinydtls debug flag above if the example isn't working or just to
learn more. Also see the dtls-echo example Makefile for more diagnostic flags.

Build nanocoap_server from its example directory with
```
$ make
```

## Building libcoap client

[libcoap](https://libcoap.net/) builds with autotools, and the instructions
below work as of July 2018, on commit 9299403 in the develop branch. The
recursive clone brings in tinydtls.

Somewhere outside the RIOT source hierarchy, execute these commands:
```
$ git clone https://github.com/obgm/libcoap.git --recursive
$ cd libcoap
$ ./autogen.sh 
$ ./configure --with-tinydtls --disable-shared
$ make
```

## Testing the server

### Startup the server
Follow the instructions for setup of the tap interface in the main README.
Continue on to start RIOT in a native terminal and view the generated link
local address.

### Run a query from libcoap
In the example query below, we use the user identity and pre-shared key provided
by sock_secure in the `keys` directory referenced above. If all goes as expected,
you see the returned value of the resource.

From the libcoap build above, execute these commands:
```
$ cd examples
$ ./coap-client -u Client_identity -k secretPSK -m get coaps://[fe80::200:bbff:febb:2%tap0]/riot/board

native
```
