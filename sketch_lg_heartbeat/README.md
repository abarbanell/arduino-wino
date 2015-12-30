# sketch_lg_heartbeat

This is an example for the  [wino-board](http://www.wino-board.com)
how to connect to the WIFI network and send a REST post to the
[limitless-garden](https://github.com/abarbanell/limitless-garden)
backend.

It uses the wino-board wifi library which is still in early stage.


WIFI passwords and configuration parameters will be injected via a local
file config.h - see below.


# Usage

First you can 

```
$ git clone git@github.com:abarbanell/arduino-wino.git
$ cd arduino-wino/sketch_lg_heartbeat
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

#ifndef LG_HOST
#define LG_HOST "my.lg.host.com"
#endif

#ifndef LG_PORT
#define LG_PORT 80
#endif

#ifndef LG_API_KEY
#define LG_API_KEY "your-api-key"
#endif

```

Of course you want to have your own values in here. 

Then you can compile and upload the sketch to your arduino as usual and
you should see after a while the IP address printed on the serial monitor
every 200 ms or so. 

# TODO

the functionality to actually send a post request is yet to be implemented.

