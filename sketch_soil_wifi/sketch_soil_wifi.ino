// Sketch to connect wino-board to wifi and read out the assigned IP address.
// this will be the basis for more functionality later.
// all the SerialUSB output is just for debugging and not needed if this logic
// is used in other sketches.

#include <wino.h>
#include "config.h" 

#define LOG_OUTPUT_DEBUG            (1)
#define LOG_OUTPUT_DEBUG_PREFIX     (1)

#define logDebug(arg)\
    do {\
        if (LOG_OUTPUT_DEBUG)\
        {\
            if (LOG_OUTPUT_DEBUG_PREFIX)\
            {\
                SerialUSB.print("[LOG Debug: ");\
                SerialUSB.print((const char*)__FILE__);\
                SerialUSB.print(",");\
                SerialUSB.print((unsigned int)__LINE__);\
                SerialUSB.print(",");\
                SerialUSB.print((const char*)__FUNCTION__);\
                SerialUSB.print("] ");\
            }\
            SerialUSB.println(arg);\
        }\
    } while(0)

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
  SerialUSB.begin(115200); //Opens USB-Serial connection for terminal
  delay(5000);
  logDebug("serial interface is ready");
}

void wifi_setup(void) {
  wifi.on(115200);
  if (wifi.wait(15000)) {
    logDebug("wifi_setup(): WIFI module started.");
  } else {
    logDebug("wifi_setup(): could not start WIFI.");
  }
  delay(1000),
  SerialUSB.println(wifi.info());
 
  delay(5000);
  wifi.setMode(0);

  while (! wifi.join(WIFI_SSID, WIFI_PASSWORD)) {
    logDebug('wifi_setup(): connecting to WIFI...');
    delay(2000);
  }
  logDebug("connected to WIFI. IP: ");
  logDebug(wifi.getip());
  logDebug("connected to WIFI. MAC: ");
  logDebug(wifi.getmac());
  logDebug("gethostname(): ");
  logDebug(gethostname(true)); // short version of hostname, cached
  
}

void sensor_setup(void) {
  pinMode(powerPin, OUTPUT);  // Sensor Power
  pinMode(ledPin, OUTPUT);  // LED when measuring
  logDebug("sensor_setup(): done"); 
}
  


void loop() {
  logDebug("loops (minutes) since restart: " + loopcnt);
    
  loopcnt++;
  if ((loopcnt % 1) == 0) lg_heartbeat(); // every 1 loops
  if ((loopcnt % 5) == 0) lg_sensor(soil_measure());    // every 5 minutes
  blinkLed(200);

  delay(60000); // one loop per minute 
}

String getIP(bool cache) {
  static String ip = "";
  if (!(ip.length() && cache)) {
    ip = wifi.getip();
  }
  return ip;
}

/*
 * build hostname from MAC address 
 */
String gethostname(bool cache) {
  static String mac = "";
  if (!(mac.length() && cache)) {
    mac = String("wino-") + wifi.getmac();
    mac.replace(":", "");
  }
  return mac;
}
/*
 * lg_heartbeat - send a json message with some data to lg server
 */

 void lg_heartbeat(void) {
  String payload = "{ \"host\": \"" + gethostname(true) + "\", \"loopcount\": " + loopcnt + ", \"errcount\": " + errcnt + " }"; 
  String url = "/api/collections/heartbeat?user_key=" + String(LG_API_KEY);
  http_post(url, payload);
 }
 
 void lg_sensor(int val) {
  String payload = "{ \"host\": \"" + gethostname(true) + "\", \"soil\": " + val + " }"; 
  String url = "/api/collections/sensor?user_key=" + String(LG_API_KEY);
  http_post(url, payload);
 }

 void http_post(String url, String payload) {
  uint8_t buffer[1024] = {0};

  String request = "POST " + url + " HTTP/1.1\r\n"
    + "Host: " + LG_HOST + "\r\n"
    + "User-Agent: arduino-wino/1.0 \r\n"
    + "Content-Type: application/json \r\n"
    + "Connection: close \r\n"
    + "Content-Length: " + payload.length() + "\r\n"
    + "\r\n"
    + payload + "\r\n";
  
  if (wifi.connect("TCP", LG_HOST, LG_PORT)) {
    logDebug("tcp connection created");
  } else {
    logDebug("tcp connection failed");
  }

  
  if (wifi.writeln(request)) {
    logDebug("request sent with wifi.writeln(String), lrc = true");  
  } else {
    logDebug("request sent with wifi.writeln(String), lrc = false");      
  }
  uint32_t len = wifi.read(buffer, sizeof(buffer), 10000);
  if (len > 0) {
    logDebug((char *)buffer);
  } else {
    logDebug("<empty response>");
  }
  if (wifi.disconnect()) {
    logDebug("tcp connection closed");
  } else {
    logDebug("tcp connection was already closed");
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

  digitalWrite(powerPin, HIGH);
  delay(1000);
  val = analogRead(A2);
  digitalWrite(powerPin, LOW);
  return val;
}


