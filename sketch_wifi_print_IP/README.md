# sketch_wifi_print_IP

This is an example from the [wino-board website](http://www.wino-board.com) how to get the IP from your wino-board.

It uses the wifi library which is in early stage. 

WIFI passwords will be injected via a local file config.h - see below.


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

Of course you want to have your own values in here. 

Then you can compile and upload the sketch to your arduino as usual and
you should see after a while the IP address printed on the serial monitor
every 5 sec or so.

