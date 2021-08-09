const protobuf = require("protobufjs");
const fs = require("fs");
const util = require('util');
const { toNamespacedPath } = require("path");


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

		// create a promise version of fs.read()
		fs.readAsync = util.promisify(fs.read);

		// a function that reads the size of message (4 bytes)
		async function read_size () {
			var sizeBuffer = new Buffer.alloc(4);
			var size = 0;
			await fs.readAsync(fd, sizeBuffer, 0, 4, pos).then(data => {
        size = data['buffer'].readInt32LE(0);
				pos += 4;
			});

			return size;
		}

		// a function that reads the message
		async function read_message (size) {
			var buffer = new Buffer.alloc(size);
			await fs.readAsync(fd, buffer, 0, size, pos).then(data => {
				pos += size;
				i += 1;

				// keep track of time and bytes taken by decoding the array to message and converting it to json object
				var hrstart = process.hrtime();
				let msg = message.decode(buffer);

				// print out the deserialized message
				let object = message.toObject(msg, {
					longs: String,
					enums: String,
					bytes: String,
				});
				
				var hrend = process.hrtime(hrstart);
				totalTime += (hrend[0] + hrend[1] / 1000000000);
				totalBytes += size;
			});
		}

		// a function that reads the size and then the content of the message
		async function read_whole () {
			message_size = await read_size();
			await read_message(message_size);
		}

		// repeat reading for the given number of times
		const message = root.lookupType(message_name);
    repeats = await read_size();
    console.log("total " + repeats + " messages in file " + file_path);
		for (let i = 0; i < repeats; i ++) {
			await read_whole();
		}

		// print results
		console.log("Performance of Nodejs dynamic reader: " + totalTime + "s");
		console.log("Number of messages processed per second: " + repeats / totalTime);
		console.log("Number of bytes processed per second: " + totalBytes / totalTime);
	});
});
