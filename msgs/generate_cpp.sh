#!/bin/bash

cd "${0%/*}"
pwd=`pwd`

${pwd}/../protobuf-3.12.2/installed/bin/protoc -I=${pwd}/../protobuf-3.12.2/installed/include --proto_path=${pwd}/../msgs --cpp_out=${pwd}/../msgs crestmessage.proto
${pwd}/../protobuf-3.12.2/installed/bin/protoc -I=${pwd}/../protobuf-3.12.2/installed/include --proto_path=${pwd}/../msgs --cpp_out=${pwd}/../msgs test/topmessage.proto
