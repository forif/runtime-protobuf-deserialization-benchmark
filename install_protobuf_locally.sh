#!/bin/bash

set -e

cd "${0%/*}"
pwd=`pwd`

wget https://github.com/protocolbuffers/protobuf/releases/download/v3.12.2/protobuf-all-3.12.2.tar.gz
tar -zxf protobuf-all-3.12.2.tar.gz
cd protobuf-3.12.2
mkdir installed
./configure --prefix=${pwd}/protobuf-3.12.2/installed
make -j8
make install
