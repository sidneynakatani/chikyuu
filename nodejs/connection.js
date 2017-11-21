'use strict';

// Use a Readline parser

const SerialPort = require('serialport');
const parsers = SerialPort.parsers;

// Use a `\r\n` as a line terminator
const parser = new parsers.Readline({
  delimiter: '\r\n'
});

const port = new SerialPort('/dev/ttyUSB0', {
  baudRate: 115200
});

port.pipe(parser);

port.on('open', () => console.log('Port open'));

parser.on('data', console.log);

port.write('ROBOT PLEASE RESPOND\n');
