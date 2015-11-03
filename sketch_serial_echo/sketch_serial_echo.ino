byte byte1Read;
byte byte2Read;
 
void setup() {
  SerialUSB.begin(115200);  //Serial connection to Serial Monitor
  //Serial.begin(115200);  //Serial connection to WIFI module
  delay(5000);  //This delays the start of the module so all information can be captured in the Serial monitor
  //pinMode(WIFI_EN_PIN, OUTPUT);
  //digitalWrite(WIFI_EN_PIN, HIGH); // Turns WIFI module on
}
 
void loop() {
 
    if (SerialUSB.available()) {
        SerialUSB.write(SerialUSB.read()); //Reads data from Serialmonitor and sends it back as echo
    }
}
