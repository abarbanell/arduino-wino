// Sketch to connect wino-board to wifi and read out the assigned IP address.
// this will be the basis for more functionality later.
// all the SerialUSB output is just for debugging and not needed if this logic
// is used in other sketches.

#include <wino.h>
#include "config.h" 

void setup() {
  SerialUSB.begin(9600); //Opens USB-Serial connection for terminal
  delay(5000);
  SerialUSB.print("Serial interface is ready\r\n");

  wifi.on();
  if(wifi.kick()) {
    SerialUSB.print("ESP8266 turned on \r\n");
  } else {
    SerialUSB.print("ESP8266 still offline\r\n"); 
  }

  SerialUSB.print("FW version: ");
  SerialUSB.println(wifi.getVersion().c_str());
  delay(5000);

  if (wifi.setOprToStationSoftAP()) {
    SerialUSB.print("to station + soft AP ok\r\n");
  } else {
    SerialUSB.print("to station + soft ap error\r\n");
  }

  if (wifi.joinAP(WIFI_SSID, WIFI_PASSWORD)) {
    SerialUSB.print("Join AP success\r\n");
    SerialUSB.print("IP: ");
    SerialUSB.println(wifi.getLocalIP().c_str());
  } else {
    SerialUSB.println("Join AP error");
  }  
  
}

int counter = 0; 

void loop() {
  counter++;
  SerialUSB.println("--"); 
  SerialUSB.println(counter);
  SerialUSB.print("IP: ");
  SerialUSB.println(wifi.getLocalIP().c_str());
  
  delay(5000); 
}

