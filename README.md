# arduino-wino
Arduino sketches for use with the Wino Board (www.wino-board.com)

We have the following sketches: 

- [sketch_echo](./sketch_echo) - just a minimal program to test upload of
sketches and serial communication. Status: it should blink the LED. Can
be compiled and uploaded, but have not seen it running (i.e. no LED
blinking).

- [sketch_serial_wifi](./sketch_serial_wifi) - example from [http://www.wino-board.com/index.php/en/code/102-code/wino-examples/serial-wifi](http://www.wino-board.com/index.php/en/code/102-code/wino-examples/serial-wifi) but with small correction
- [sketch_serial_echo](./sketch_serial_echo) - just a serialUSB connection with echo

## status: not working yet

still trying to figure out how to run any of these sketches :) 



## todo

- sketch to connect WiFi and read IP address
- sketch to POST a message to a web address
- sketch to GET a message from a web address
- sketch to read a sensor
- combine these to read commands from the web, read sensors, and log results online
