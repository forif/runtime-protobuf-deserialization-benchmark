import subprocess
import os
import sys

dataGen = False
repeats = "100000"

# argv[2] is number of messages, default 100000

if len(sys.argv) > 1:
    repeats = sys.argv[1]
    dataGen = True

dir_path = os.path.dirname(os.path.realpath(__file__))
msg_file_path = os.path.join(dir_path, "msgs.pbbin")
proto_file_path = os.path.join(dir_path, "msgs", "crestmessage.proto")

if dataGen == True:
    p0 = subprocess.Popen(["./pb_static/pb_writer", repeats, msg_file_path], cwd = dir_path)
    p0.wait()

p1 = subprocess.Popen(["./pb_static/pb_reader", msg_file_path], cwd = dir_path)
p1.wait()
p2 = subprocess.Popen(["./pb_dyn/pb_reader", proto_file_path, msg_file_path, "CrestMessage"], cwd = dir_path)
p2.wait()
p3 = subprocess.Popen(["node", "./pb_dyn/nodejs_reader.js", proto_file_path, msg_file_path, "CrestMessage"], cwd = dir_path)
p3.wait()
