---
layout: post
title: "Arduino -  power supply for the  Wino Board "
date:   2015-11-14 21:42:30
description: "How to get enough power to a wino-board"
category: Arduino
tags: [Arduino, IoT, Linux]
---

In this post I will look at the power supply for the 
[wino-boards](http://wino-board.com).

The Wino-Board is a very small, but also powerful board with and
32bit ARM Cortex M0+ CPU instead of the traditional 8-bit CPU in most
[Arduino](www.arduino.cc) boards. But the real treat is the WiFi
module on board, thanks to the ESP8266 chip on the board. 

![Wino Board Picture](http://wino-board.com/images/Wino_layout.PNG) 

# Connecting Power

Usually the idea is to connect the piggy-back a Wino USB-upgrade board on top of the Wino-Board and spupply 
power via the USB. In my experience this has worked well enough to feed the CPU but apparently the WiFi chip
i drawing some peak current which may not be available via USB (remember that USB is usually limited to 
500mA but may be also less depending on your power source, especially if you use the USB coming from your laptop).

Another point is that I have multiple wino-boards but only one USB-upgrade so that I can only feed one Wino-Board via USB.

So here we go: 

My solution is mainly based on what I found in my drawers, so yours may look a little different.

Parts list:

- 1 mid-szed breadboard (400 points)
- 1 [MB-102 power
supply](http://www.petervis.com/Raspberry_PI/Breadboard_Power_Supply/YwRobot_Breadboard_Power_Supply.html)
converting 6-9V DC input to the desired 3.3V output
- 1 wall adapter AC/DC power supply delivering up to 1000mA of 6V DC
- 2 short breadboard cables (male/male)
- 1 capacitor of 10uF (although I would have used more if I could, but this was the only size available) 

Picture: 

![Wino Power]({{ site.baseurl }}/img/wino-power.jpg)

# Conclusion

With only the USB power my Wino board was caught in endless reset
loops due to the power peak a startup of the WiFi module, but with
this power supply I could connect the Wifi to my base station at
the end.



