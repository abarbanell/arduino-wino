
/*
 * how to keep credentials out of source control:
 * the file config.h is not stored in source control because 
 * the .gitignore file excludes it.
 */

#include "config.h"

void setup(void) {
  SerialUSB.begin(115200);  //Serial connection to Serial Monitor
  delay(5000);  // delay the start so all information can be 
                // captured in the Serial monitor
  show();
}

void loop() {
  if (SerialUSB.available()) {
      SerialUSB.read(); //don't care what we read
      show();
  }
}

void show() {

  SerialUSB.print("WIFI SSID: ");
  SerialUSB.println(WIFI_SSID);

}
