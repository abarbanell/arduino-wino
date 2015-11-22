---
layout: post
title: "Arduino -  how to keep configuration values and credentials out of git"
date:   2015-11-21 21:42:30
description: "How to keep configuration values out of git with Arduino sketches"
category: Arduino
tags: [Arduino, IoT]
---

In the last days I have been googling unsuccessfully to find the best way how to 
share arduino sketches on [github](https://github.com/abarbanell/arduino-wino) 
without letting the world know private data like the WIFI SSID and password or 
other configuration data.

In "big" programming you would typically inject these at runtime from a configuration
file or (better) from environment variables. However, the arduino does not 
have a way how you could do this at runtime, unless you build some maintenance functions
into your sketch and additional logic to save the values in EEPROM. Too complicated for me.

So here is my suggestion:

Read your configuration from a file "config.h" at compile time, but exclude this file from the 
git repo via .gitignore - of course that makes sharing a bit more difficult because everyone 
has to create their own config.h file after cloning your repository. 

# How to

I tried to distill this into a small example
[sketch_config](https://github.com/abarbanell/arduino-wino/tree/master/sketch_config)
to illustrate the idea.

You only need the following in your repo: 

- a .gitignore file with this entry: 

```
config.h
```

- a [README.md](https://github.com/abarbanell/arduino-wino/blob/master/sketch_config/README.md) 
file with the user instruction - not strictly required, but nice to have.  

- your own private "config.h" file with the real values, looking somewhat like this: 

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

- your normal Arduino sketch which should have this line somewhere in the beginning: 

```
#include "config.h"
```

The full example is in a [folder in my github
repository](https://github.com/abarbanell/arduino-wino/tree/master/sketch_config)
[wino-boards](http://wino-board.com).

If you follow these instructions and flash this sketch to your Arduino. In my case it is a 
[wino-board](http://wino-board.com) which has a 32bit SAMD CPU and an ESP8266 WiFi chip all 
on board already. 

Then you open the serial monitor and type something. it does not matter what, each byte will make this 
sketch print the WIFI_SSID value from your config.h file once.

![config values Picture]({{ site.baseurl }}/img/sketch_config.png)

# Alternatives

If you use an AVR based Arduino (Uno or similar) then you can also 
use a [makefile](https://github.com/sudar/Arduino-Makefile) and inject 
your config values from the Linux (or MacOS) shell environment into the
compile process - in this file my config.h would pick up the command line 
values because the #ifndef clauses will override the values in the code if 
values are already set from command line (or from code in the sketch before the #include "config.h").

However, I use a SAMD processor (Atmel ATSAMD21 in the
[wino-board](http://www.wino-board.com) ) so I could not find a working
Makefile and had to stay with the rather limited functionality of the
Arduino IDE.

# Conclusion

I hope this approach is helpful, and look forward to any comments or better proposals. 


