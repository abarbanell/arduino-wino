void setup() {
  pinMode(2, OUTPUT);  // LED is connecte to Pin 2
  SerialUSB.begin(115200);  //Serial connection to Serial Monitor
  delay(5000);  //This delays the start of the module so all information can be captured in the Serial monitor
}

void loop() {
  if (SerialUSB.available()) {
      SerialUSB.write(SerialUSB.read()); //Reads data from Serialmonitor and sends it back as echo
 
      delay(200);
      digitalWrite(2, HIGH);
      delay(200);
      digitalWrite(2, LOW);
      delay(1000);
      digitalWrite(2, HIGH);
      delay(1000);
      digitalWrite(2, LOW); 
   }
}
