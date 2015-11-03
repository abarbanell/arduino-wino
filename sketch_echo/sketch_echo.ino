void setup() {
  pinMode(2, OUTPUT);  // LED is connecte to Pin 2
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);
  digitalWrite(2, HIGH);
  delay(200);
  digitalWrite(2, LOW);
  delay(1000);
  digitalWrite(2, HIGH);
  delay(1000);
  digitalWrite(2, LOW); 

}
