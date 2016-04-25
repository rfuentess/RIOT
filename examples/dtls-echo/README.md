# dtls_echo

This example  shows you how to use TinyDTLS with the non-socket approach.

This code  is based on  ../gnrc_networking and ../gnrc_tftp.
Is a good idea to read their README.md's for any doubt of how making the
testings.

## SOCKET vs. Non-socket (GNRC)

This example is configured to use the GNRC instead of  sockets (over GNRC).
At the moment, the configuration must be done manually in the Makefile of
this project.

## Fast configuration (Between RIOT instances):

Preparing the logical interfaces:

    ./../../dist/tools/tapsetup/tapsetup --create 2

For the server instance:

    make all; PORT=tap1 make term
    dtlss start
    ifconfig

Do not forget to copy the IPv6 addresses!

For the client:

    PORT=tap0 make term
    dtlsc <IPv6's server address> "DATA TO DATA TO DATA!"

# Testings
## Boards

Those boards that do not support  the `../gnrc_networking` example are included
in the `BOARD_INSUFFICIENT_MEMORY`, plus the  board `cc2650stk`.

There are certain boards that are having issues with `crypto.c` and
`dtls_time.h` Which for now are in the the `BOARD_BLACKLIST`.

The boards that requires `periph_conf.h` are not tested (Exception
msb-430-common that is in the `BOARD_BLACKLIST`).
