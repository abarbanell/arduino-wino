String answer;
String ip = "";
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(WIFI_EN_PIN, OUTPUT);
 
  Serial.begin(115200); //Opens serial connection to WIFI module
  SerialUSB.begin(115200); //Opens USB-Serial connection for terminal
 
 
 //Preparing Wifi-module
 digitalWrite(WIFI_EN_PIN, LOW); //turns WIFI module off
 digitalWrite(13, HIGH); //set module to normal mode
 delay(100);              // wait a short time
 digitalWrite(WIFI_EN_PIN, HIGH); //turns WIFI module on
 
 
    //wait until the module is ready
    while (!Serial.find("ready\r\n")) {}
    SerialUSB.write("Module is ready\r\n");
  
    //Set module to Station mode and wait for reply
    Serial.println("AT+CWMODE=1");
    while (!Serial.find("OK\r\n")) {}
    SerialUSB.println("Module changing to Station mode");
    //delay(100);
 
    //Waiting for IP-Address
    while (!Serial.find("WIFI GOT IP")) {SerialUSB.println("Waiting for IP-Address"); delay(200);}
    SerialUSB.println("got IP-Address");
 
    //Reading IP-Address
    Serial.println("AT+CIFSR");
    
  
}
 
void loop() {
 
while (Serial.available() > 0)
    {
        char received = Serial.read();
        answer.concat(received);
        if (answer.indexOf("\r\n") > -1 ){
 
          if (answer.indexOf("STAIP") > -1) {
            int starti = answer.indexOf('IP,"') + 1;
            ip = answer.substring(starti,answer.length() - 3);
          } 
         answer=""; 
        }
        // Process message when new line character is recieved
       
    }
 
if (ip != "") {SerialUSB.println(ip); delay(1000);}
 
 
}

