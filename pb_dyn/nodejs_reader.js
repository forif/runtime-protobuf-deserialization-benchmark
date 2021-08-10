const protobuf = require("protobufjs");
const fs = require("fs");
const { PerformanceObserver, performance } = require('perf_hooks');


// argv[2] is the path of given .proto file that contains the protobuf definition
// argv[3] is the path of serialized file that will needs to be deserialized
// argv[4] is the name of the message in the serialized file
var proto_path = "../msgs/crestmessage.proto";
var file_path = "../msgs.pbbin";
var message_name = "CrestMessage";

if (process.argv.length > 2) proto_path = process.argv[2];
if (process.argv.length > 3) file_path = process.argv[3];
if (process.argv.length > 4) message_name = process.argv[4];


protobuf.load(proto_path, function (err, root) {
	if (err) throw err;

	// open the file
	fs.open(file_path, 'r+', async function (err, fd) {
		if (err) {
			return console.error(err);
		}

		// read the file
		// set up variables, i is index of messages, pos is current position in the file
		var pos = 0;
		var i = 0;
		var totalTime = 0;
		var totalBytes = 0;

		// a function that reads the size of message (4 bytes)
		function read_size () {
			var sizeBuffer = new Buffer.alloc(4);
			var size = 0;
			fs.readSync(fd, sizeBuffer, 0, 4, pos);
      size = sizeBuffer.readInt32LE(0);
			pos += 4;
			return size;
		}

		// a function that reads the message
		function read_message (size) {
			var buffer = new Buffer.alloc(size);
			fs.readSync(fd, buffer, 0, size, pos);
			pos += size;
			i += 1;

			// keep track of time and bytes taken by decoding the array to message and converting it to json object
      let mstart = performance.now();
			let msg = message.decode(buffer);

			// print out the deserialized message
			let object = message.toObject(msg, {
				longs: String,
				enums: String,
				bytes: String,
			});
			
      let mend = performance.now();
      totalTime += (mend - mstart) / 1000;
			totalBytes += size;
		}

		// a function that reads the size and then the content of the message
		function read_whole () {
			message_size = read_size();
			read_message(message_size);
		}

		// repeat reading for the given number of times
		const message = root.lookupType(message_name);
    repeats = read_size();
    console.log("total " + repeats + " messages in file " + file_path);
    let start = performance.now();
		for (let i = 0; i < repeats; i ++) {
			read_whole();
		}

		// print results
		console.log("Performance of Nodejs dynamic reader: " + totalTime + "s " + ((performance.now() - start) / 1000) + "s");
		console.log("Number of messages processed per second: " + repeats / totalTime);
		console.log("Number of bytes processed per second: " + totalBytes / totalTime);
	});
});
