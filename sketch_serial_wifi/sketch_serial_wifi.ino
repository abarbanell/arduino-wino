int ledPin = 2;
 
void setup() {
  SerialUSB.begin(115200);  //Serial connection to Serial Monitor
  Serial.begin(115200);  //Serial connection to WIFI module
  delay(5000);  //This delays the start of the module so all information can be captured in the Serial monitor
  pinMode(WIFI_EN_PIN, OUTPUT);
  digitalWrite(WIFI_EN_PIN, HIGH); // Turns WIFI module on
  pinMode(ledPin, OUTPUT);  // LED when transferring bytes
}
 
void loop() {
 
    while (SerialUSB.available()) {
        Serial.write(SerialUSB.read()); //Reads data from Serialmonitor and sends it to WIFI module
        blinkLed(100);
    }
    while (Serial.available()) {
        SerialUSB.write(Serial.read());   //Reads WIFI module data from  and sends it to Serialmonitor
        blinkLed(50);
    }
}

void blinkLed(int ms) {
  digitalWrite(ledPin, HIGH);
  delay(ms);
  digitalWrite(ledPin, LOW);
  delay(ms);
}
