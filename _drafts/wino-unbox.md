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

Before that I had a [Raspberry Pi](https://www.raspberrypi.org/)
connected to the internet and an
Arduino for reading the analog sensors, now my plan is to have all
of the internet logic on the Wino-Board.

![Wino Board Picture](http://wino-board.com/images/Wino_layout.PNG) 

# Getting the hardware

I have got m couple of board via the 
[kickstarter](https://www.kickstarter.com/projects/krom/wino-board-the-tiny-10-arduino-with-wifi)
campaign, but there should be a [shop](http://wino-board.com/index.php/en/store)
 opening soon where you should be able to buy. 

# Dev Environment: Linux in my case

Support for development tools is currently best for Windows, folowed by Linux (Intel only). 
MacOS and ARM Linux are not yet supported.

I have a linux box as development box for this project, runnning
Ubuntu 15.10. There have been some limitations
in the Wino-Board toolchain in the first versions, so make sure to get the latest, following the 
[Linux Quickstart Guid](http://wino-board.com/index.php/en/wino-board/quickstart/linux)
:nd follow the updates on the [Wino Forum](http://wino-board.com/index.php/en/forum/index).

Just follow the steps from the [Wino-Board Quickstart guide for
Linux](http://www.wino-board.com/index.php/en/wino-board/quickstart/linux) and you are all set.

