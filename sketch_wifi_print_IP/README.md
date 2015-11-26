# sketch_wifi_print_IP

This is an example from the [wino-board website](http://www.wino-board.com) how to get the IP from your wino-board.

It uses the ESP8266 AT-commands becauset he wifi library is not yet stable.


WIFI passwords will be injected via a local file config.h - but at this
time they are not yet used.

But anyway here is how to use this sketch: 

# Usage

First you can 

```
$ git clone git@github.com:abarbanell/arduino-wino.git
$ cd arduino-wino/sketch_wifi_print_IP
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

Of course you want to have your own values in here. (Note again: these
values are not yet used, so it actually does not matter which values
you use...)

Then you can compile and upload the sketch to your arduino as usual and
you should see after a while the IP address printed on the serial monitor
every 200 ms or so.

