#include <wino.h>

/* measure soil humidity ad send via UDP package to statsd.*/

// how to keep these out of github - we will later inject them via compile time from environment vars

#ifndef SSID
#define SSID        "MY-SSID"
#endif

#ifndef PASSWORD
#define PASSWORD    "12345678"
#endif

#ifndef HOST_NAME
#define HOST_NAME   "127.0.0.1"
#endif

#ifndef HOST_PORT
#define HOST_PORT   (80)
#endif


int powerPin = 12;
int ledPin = 2; // digital 2

void setup(void) {
  pinMode(powerPin, OUTPUT);  // Sensor Power
  pinMode(ledPin, OUTPUT);  // LED when measuring
  SerialUSB.begin(115200);  //Serial connection to Serial Monitor
  SerialUSB.print("setup begin\r\n");
  delay(5000);  //This delays the start of the module so all information can be captured in the Serial monitor
}



void loop() {
  if (SerialUSB.available()) {
      SerialUSB.read(); //don't care what we read

      measure();
  }
  blinkLed(200);
}

void blinkLed(int ms) {
  digitalWrite(ledPin, HIGH);
  delay(ms);
  digitalWrite(ledPin, LOW);
  delay(ms);
}

void measure() {
  int val;

  digitalWrite(ledPin, HIGH);
  digitalWrite(powerPin, HIGH);
  delay(1000);
  val = analogRead(A2);
  digitalWrite(powerPin, LOW);
  digitalWrite(ledPin, LOW);
  sendmessage(val);
}

void sendmessage(int v) {
  SerialUSB.println(v);
}
