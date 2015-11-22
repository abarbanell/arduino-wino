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

- [sketch_soil](./sketch_soil) - read a soil humidity sensor via analog pin. only supply power during measurement (to save 
power and reduce sensor corrosion). read one time for each byte sent via the USB serial connection.

- [sketch_config](./sketch_config) - example how to keep config values
and credentials out of souce control.

# Status

This works in my environemnt on Ubuntu 25.10 but has not been tested elsewhere. 

```
$ uname -a 
Linux tux03 4.2.0-16-generic #19-Ubuntu SMP Thu Oct 8 15:35:06 UTC 2015 x86_64 x86_64 x86_64 GNU/Linux
```
