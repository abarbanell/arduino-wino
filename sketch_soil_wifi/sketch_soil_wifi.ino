// Sketch to connect wino-board to wifi and read out the assigned IP address.
// this will be the basis for more functionality later.
// all the SerialUSB output is just for debugging and not needed if this logic
// is used in other sketches.

#include <wino.h>
#include "config.h" 

int loopcnt = 0;
int errcnt = 0;

int powerPin = 12;
int ledPin = 2; // digital 2

void setup(void) {
  serial_setup();
  wifi_setup();
  sensor_setup();
}

void serial_setup(void) {
  SerialUSB.begin(9600); //Opens USB-Serial connection for terminal
  delay(5000);
  SerialUSB.print("Serial interface is ready\r\n");
}

void wifi_setup(void) {
  wifi.on();
  if(wifi.kick()) {
    SerialUSB.print("ESP8266 turned on \r\n");
  } else {
    SerialUSB.print("ESP8266 still offline\r\n");
    errcnt++; 
  }

  SerialUSB.print("FW version: ");
  SerialUSB.println(wifi.getVersion().c_str());
  delay(5000);

  if (wifi.setOprToStationSoftAP()) {
    SerialUSB.print("to station + soft AP ok\r\n");
  } else {
    SerialUSB.print("to station + soft ap error\r\n");
    errcnt++;
  }

  if (wifi.joinAP(WIFI_SSID, WIFI_PASSWORD)) {
    SerialUSB.print("Join AP success\r\n");
    SerialUSB.print("IP: ");
    SerialUSB.println(getIP(true)); // short version of IP, cached
    SerialUSB.print("MAC: ");
    SerialUSB.println(gethostname(true)); // short version of hostname, cached
  } else {
    SerialUSB.println("Join AP error");
    errcnt++;
  }  

  if (wifi.disableMUX()) {
    SerialUSB.println("MUX disabled");
  } else {
    SerialUSB.println("MUX disabling failed");
    errcnt++;
  }
}

void sensor_setup(void) {
  pinMode(powerPin, OUTPUT);  // Sensor Power
  pinMode(ledPin, OUTPUT);  // LED when measuring
}
  


void loop() {
  SerialUSB.print("loops (minutes) since restart: ");
  SerialUSB.println(loopcnt);
    
  loopcnt++;
  if ((loopcnt % 5) == 0) lg_heartbeat(); // every 5 loops
  if ((loopcnt % 5) == 0) lg_sensor(soil_measure());    // every 5 minutes
  blinkLed(200);

  delay(60000); // one loop per minute 
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

/*
 * build hostname from MAC address 
 */
String gethostname(bool cache) {
  static String mac = "";
  if (mac.length() && cache) {
     return mac;
  }
  String pattern = "STAMAC,\"";
  String answer = wifi.getLocalIP().c_str();
  int starti = answer.indexOf(pattern) + pattern.length();
  mac = answer.substring(starti, answer.length() -1);  
  int stopi = mac.indexOf("\"");
  mac = String("wino-") + mac.substring(0,stopi);
  mac.replace(":", "");
  return mac;
}
/*
 * lg_heartbeat - send a json message with some data to lg server
 */

 void lg_heartbeat(void) {
  String payload = "{ \"host\": \"" + gethostname(true) + "\", \"loopcount\": " + loopcnt + ", \"errcount\": " + errcnt + " }"; 
  String request = "POST /api/collections/heartbeat?user_key=" + String(LG_API_KEY) + " HTTP/1.1\r\n"
    + "Host: " + LG_HOST + "\r\n"
    + "User-Agent: arduino-wino/1.0 \r\n"
    + "Connection: close \r\n"
    + "Content-Length: " + payload.length() + "\r\n"
    + "\r\n"
    + payload + "\r\n";
  http_post(request, payload);
 }
 
 void lg_sensor(int val) {
  String payload = "{ \"host\": \"" + gethostname(true) + "\", \"soil\": " + val + " }"; 
  String request = "POST /api/collections/sensor?user_key=" + String(LG_API_KEY) + " HTTP/1.1\r\n"
    + "Host: " + LG_HOST + "\r\n"
    + "User-Agent: arduino-wino/1.0 \r\n"
    + "Content-Type: application/json \r\n"
    + "Connection: close \r\n"
    + "Content-Length: " + payload.length() + "\r\n"
    + "\r\n"
    + payload + "\r\n";
  http_post(request, payload);
 }

 void http_post(String url, String payload) {
    uint8_t buffer[1024] = {0};

  SerialUSB.print("host: ");
  SerialUSB.print(LG_HOST);
  SerialUSB.print(" - port: ");
  SerialUSB.println(LG_PORT);
  SerialUSB.print("url: ");
  SerialUSB.println(url);

  
  if (wifi.createTCP(LG_HOST, LG_PORT)) {
    SerialUSB.println("tcp connection created");
  } else {
    SerialUSB.println("tcp connection failed");
  }

  wifi.send((const uint8_t*)url.c_str(), url.length());
  uint32_t len = wifi.recv(buffer, sizeof(buffer), 10000);
  if (len > 0) {
    SerialUSB.print("Received: [");
    for (uint32_t i=0; i<len; i++) {
      SerialUSB.print((char)buffer[i]);  
    }
    SerialUSB.println("]");
  }
  if (wifi.releaseTCP()) {
    SerialUSB.println("tcp connection closed");
  } else {
    SerialUSB.println("tcp connection already closed");
  }
}
void blinkLed(int ms) {
  digitalWrite(ledPin, HIGH);
  delay(ms);
  digitalWrite(ledPin, LOW);
  delay(ms);
}

int soil_measure(void) {
  int val;

  digitalWrite(ledPin, HIGH);
  digitalWrite(powerPin, HIGH);
  delay(2000);
  val = analogRead(A2);
  digitalWrite(powerPin, LOW);
  digitalWrite(ledPin, LOW);
  return val;
}


