---
layout: post
title: "Arduino -  bringing a Wino Board to life"
description: ""
category: Arduino
tags: [Arduino, IoT, Linux]
---

I just got a set of [wino-boards](http://wino-board.com) from a
[kickstarter](https://www.kickstarter.com/projects/krom/wino-board-the-tiny-10-arduino-with-wifi)
campaign and wanted to bring them up and running.

The Wino-Board is a very small, but also powerful board with and
32bit ARM Cortex M0+ CPU instead of the traditional 8-bit CPU in most
[Arduino](www.arduino.cc) boards. But the real treat is the WiFi
module on board. Which would make my set up of monitoring my 
[home garden](http://blog.abarbanell.de/raspberry/2015/08/16/raspberry-arduino/)
 much easier.

Until now I have  a [Raspberry Pi](https://www.raspberrypi.org/)
connected to the internet and an
Arduino for reading the analog sensors, now my plan is to have all
of the internet logic on the Wino-Board.

![Wino Board Picture](http://wino-board.com/images/Wino_layout.PNG) 

# Getting the hardware

I have got a couple of board via the 
[kickstarter](https://www.kickstarter.com/projects/krom/wino-board-the-tiny-10-arduino-with-wifi)
campaign, but there should be a [shop](http://wino-board.com/index.php/en/store)
 opening soon where you should be able to buy. 

# Dev Environment: Linux in my case

I have a development environment on a Linux 15.10 system and could upload the sketches to check 
everything was working.

Just follow the steps from the [Wino-Board Quickstart guide for
Linux](http://www.wino-board.com/index.php/en/wino-board/quickstart/linux) and you are all set.

The code for my first trial sketches is [here](https://github.com/abarbanell/arduino-wino), I will add more 
sketches for this board soon.

# Still to do

The dev environment for MacOS is [confirmed](http://www.wino-board.com/index.php/de/forum/software/9-howto-install-the-wino-board-addin-at-linux?start=18) to work as well now - will try this next.


