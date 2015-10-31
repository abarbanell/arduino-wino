---
layout: post
title:  "Reset Button for the Wino Board"
date:   2015-10-31 14:22:30
categories: Wino Arduino 
---

This is the first of quick tips for the [Wino Board](http://www.wino-board.com), a small Arduino board 
with integrated WiFi.

A frequently asked question is: "Where is the reset button?" - The answer is: Well, hmmm....

- There is a button on the USB-Upgrade board but not on the main board
- the button is a generic button, not really a reset button.

But it is really easy to do this and also mentioned in a few places but I was just missing a picture 
to make everything clear, so here it is: 

- The button is connected to Pin D8, just next to the RESET pin
- you need to bridge the two pins with a short cable and
- voilá, you have a reset button: 

![Resetting the Wino]({{ site.baseurl }}/img/reset.jpeg)

press it once for a normal reset (restarting the sketch loaded in the flash), or press it twice (quickly) 
to go back into the boot loader mode.

Complete Pin layout is [here](http://wino-board.com/index.php/en/wino-board/technical)


