# arduino-wino
Arduino sketches for use with the Wino Board (www.wino-board.com)

here are  the following sketches: 

- [sketch_echo](./sketch_echo) - just a minimal program to test upload of
sketches and serial communication. Status: it should blink the LED and echo each character (one short and 
one long blink for each char) . 

- [sketch_serial_wifi](./sketch_serial_wifi) - example from
[http://www.wino-board.com/index.php/en/code/102-code/wino-examples/serial-wifi](http://www.wino-board.com/index.php/en/code/102-code/wino-examples/serial-wifi)
but with small correction

- [sketch_serial_echo](./sketch_serial_echo) - just a serialUSB connection
with echo - same as sketch_echo but without any LED blinking.

- [sketch_soil](./sketch_soil( - read a soil humidity sensor via analog pin. only supply power during measurement (to save 
power and reduce sensor corrosion). read one time for each byte sent via the USB serial connection.

# status: working on Linux 15.10

Linux x86_64 Ubuntu 15:10: can be uploaded with the toolset from [Wino Board Quickstart Linux])http://www.wino-board.com/index.php/de/wino-board/quickstart/linux) from 4-Nov-2015 or later.



## todo

- sketch to connect WiFi and read IP address
- sketch to POST a message to a web address
- sketch to GET a message from a web address
- combine these to read commands from the web, read sensors, and log results online
