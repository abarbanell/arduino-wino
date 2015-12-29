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
    SerialUSB.println(getIP(true)); // short version of output, cached
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
  SerialUSB.println(getIP(true)); // short version of output, cached
  
  delay(5000); 
}

/* get local IP address. The wifi library gives a strig result like this: 
 *  
 *  +CIFSR:APIP,"xxx.xxx.xxx.xxx"
 *  +CIFSR:APMAC,"xx:xx:xx:xx:xx:xx"
 *  +CIFSR:STAIP,"xxx.xxx.xxx.xxx"
 *  +CIFSR:STAMAC,"xx:xx:xx:xx:xx:xx"
 * 
 * we need to cut out the value from the STAIP line (Station IP)
 *
 */

String getIP(bool cache) {
  static String ip = "";
  if (ip.length() && cache) {
     return ip;
  }
  String pattern = "STAIP,\"";
  String answer = wifi.getLocalIP().c_str();
  int starti = answer.indexOf(pattern) + pattern.length();
  ip = answer.substring(starti, answer.length() -1);  
  int stopi = ip.indexOf("\"");
  ip = ip.substring(0,stopi);
  return ip;
}


