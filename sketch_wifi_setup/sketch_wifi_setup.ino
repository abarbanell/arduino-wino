
// example code from http://wino-board.com/index.php/en/code/104-code/wino-examples/apmode


void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(WIFI_EN_PIN, OUTPUT);
 
  Serial.begin(115200); //Opens serial connection to WIFI module
  SerialUSB.begin(115200); //Opens USB-Serial connection for terminal
 
 
 // switch wifi into setup mode
 //Preparing Wifi-module
 digitalWrite(WIFI_EN_PIN, LOW); //turns WIFI module off
 digitalWrite(13, HIGH); //set module to normal mode
 delay(100);              // wait a short time
 digitalWrite(WIFI_EN_PIN, HIGH); //turns WIFI module on
 
 
    //wait until the module is ready
    while (!Serial.find("ready\r\n")) {}
    SerialUSB.write("Module is ready\r\n");
  
    //Set module to Station&AP mode to enable WIFI Setup
    Serial.println("AT+CWMODE=3");
    while (!Serial.find("OK\r\n")) {}
    SerialUSB.println("Module changing to AP&Station mode");
 
   
}
 
void loop() {
 
}
