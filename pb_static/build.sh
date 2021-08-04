#!/bin/bash

g++ -std=c++11 -o pb_writer -I../msgs -I../protobuf-3.12.2/installed/include -L ../protobuf-3.12.2/installed/lib pb_writer.cc ../msgs/test/topmessage.pb.cc ../msgs/crestmessage.pb.cc -lprotobuf -lpthread
g++ -std=c++11 -o pb_reader -I../msgs -I../protobuf-3.12.2/installed/include -L ../protobuf-3.12.2/installed/lib pb_reader.cc ../msgs/test/topmessage.pb.cc ../msgs/crestmessage.pb.cc -lprotobuf -lpthread
