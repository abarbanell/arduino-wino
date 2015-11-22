# sketch_config - show how to keep config out of source control

in many Arduino sketches you have credentials to include in the 
sketch for things like WiFi SSID and password, API Keys, etc. 

These should not show up in source control so here is an example
how to keep your git repo clean and still have config values 
flashed to your Arduino.

# Usage

First you can 

```
$ git clone git@github.com:abarbanell/arduino-wino.git
$ cd arduino-wino/sketch_config
```

However, before you compile this sketch you need to create a file 
"config.h" with your own config values like this: 

```
/*
 * config variables - this file should not be in source control as it 
 * will show your live credentials.
 */

#ifndef WIFI_SSID
#define WIFI_SSID "MY-SSID"
#endif

#ifndef WIFI_PASSWORD
#define WIFI_PASSWORD "MY-WIFI-PASSWORD"
#endif
```

Of course you want to have your own values in here. 

Then you can compile and upload the sketch to your arduino as usual and 

you should see one of the config values printed over the serial monitor
whenever you send any byte down to your arduino.

# Alternatives 

If you use an AVR based Arduino (Uno or similar) then you can also 
use a [makefile](https://github.com/sudar/Arduino-Makefile) and inject 
your config values from the Linux (or MacOS) shell environment into the
compile process - in this file my config.h would pick up the command line 
values because the #ifndef clauses will override the values in the code if 
values are already set.

However, I use a SAMD processor (Atmel ATSAMD21 in the
[wino-board](http://www.wino-board.com) ) so I could not find a working
Makefile and had to stay with the rather limited functionality of the
Arduino IDE.
