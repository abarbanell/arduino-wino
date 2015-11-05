int powerPin = 12;
int ledPin = 2; // digital 2

void setup() {
  pinMode(powerPin, OUTPUT);  // Sensor Power
  pinMode(ledPin, OUTPUT);  // LED when measuring
  SerialUSB.begin(115200);  //Serial connection to Serial Monitor
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
