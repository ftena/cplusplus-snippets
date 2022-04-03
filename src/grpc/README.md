# Quickstart

More info @ https://grpc.io/docs/languages/cpp/quickstart/

## Build and install gRPC and Protocol Buffers

It's important to choose a directory to hold locally installed packages.

    $ export MY_INSTALL_DIR=$HOME/.local
    $ mkdir -p $MY_INSTALL_DIR
    $ export PATH="$MY_INSTALL_DIR/bin:$PATH"

While not mandatory, gRPC applications usually leverage Protocol Buffers for service definitions and data serialization, and the example code uses proto3.



