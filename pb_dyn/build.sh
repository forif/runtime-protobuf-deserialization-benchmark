#!/bin/bash

g++ -std=c++11 -o pb_reader -I../protobuf-3.12.2/installed/include -L ../protobuf-3.12.2/installed/lib pb_reader.cc -lprotobuf -lpthread
