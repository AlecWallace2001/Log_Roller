#include <WiFi.h>

// WiFi network name and password:
String tempString = "temp";
byte mac[6];

// Internet domain to request from: 1 2 3 4 5 3 3 4 6 
const char * hostDomain11 = "http://Were.nostrangersto.love";
const char * hostDomain12 = "http://You.knowtherulesandsodo.I";
const char * hostDomain13 = "http://A.fullcommitmentswhatImthinking.of";
const char * hostDomain14 = "http://You.wouldntgetthisfromanyother.guy";

const char * hostDomain21 = "http://I.justwanttotellyouhowIm.feeling";
const char * hostDomain22 = "http://Gotta.makeyou.understand";

const char * hostDomain31 = "http://Never.gonnagiveyouupnevergonnaletyou.down";
const char * hostDomain32 = "http://Never.gonnarunaroundanddesert.you";
const char * hostDomain33 = "http://Never.gonnamakeyoucrynevergonnasay.goodbye";
const char * hostDomain34 = "http://Never.gonnatellalieandhurt.you";

const char * hostDomain41 = "http://Weve.knowneachotherforso.long";
const char * hostDomain42 = "http://Your.heartsbeenachingbutyouretooshytosay.it";
const char * hostDomain43 = "http://Inside.webothknowwhatsbeengoing.on";
const char * hostDomain44 = "http://We.knowthegameandweregonnaplay.it";

const char * hostDomain51 = "http://And.ifyouaskmehowIm.feeling";
const char * hostDomain52 = "http://Dont.tellmeyouretooblindto.see";

const char * hostDomain61 = "http://I.justwanttotellyouhowIm.feeling";
const char * hostDomain62 = "http://Gotta.makeyou.understand";
const int hostPort = 80;

const int BUTTON_PIN = 0;
const int LED_PIN = 5;

void setup()
{
  // Initilize hardware:
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  digitalWrite(LED_PIN, LOW); // LED off
}

void loop()
{
  Serial.println("scan start");

    // WiFi.scanNetworks will return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
      if (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) {
        tempString = WiFi.SSID(i);
        char networkSSID[50];
        tempString.toCharArray(networkSSID, 50);
        connectToWiFi(networkSSID);
        if (WiFi.status() == WL_CONNECTED) {
          Serial.println("Connected");
          partOne();
          partTwo();
          partThree();
          partFour();
          partFive();
          partThree();
          partThree();
          partFour();
          partSix();
          WiFi.disconnect();
        }
      }
      delay(10);
      }
   }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}

void connectToWiFi(char * ssid)
{
  int ledState = 0;

  printLine();
  Serial.println("Connecting to WiFi network: " + String(ssid));

  WiFi.begin(ssid);

  unsigned long timeout = millis();
  while (WiFi.status() != WL_CONNECTED) 
  {
    // Blink LED while we're connecting:
    digitalWrite(LED_PIN, ledState);
    ledState = (ledState + 1) % 2; // Flip ledState
    delay(1000);
    Serial.print(".");
    if (millis() - timeout > 10000) 
    {
      Serial.println(">>> Connection Timeout");
      WiFi.disconnect();
      return;
    }
  }
  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  WiFi.macAddress(mac);
  Serial.print("MAC: ");
  Serial.print(mac[5],HEX);
  Serial.print(":");
  Serial.print(mac[4],HEX);
  Serial.print(":");
  Serial.print(mac[3],HEX);
  Serial.print(":");
  Serial.print(mac[2],HEX);
  Serial.print(":");
  Serial.print(mac[1],HEX);
  Serial.print(":");
  Serial.println(mac[0],HEX);
}

void requestURL(const char * host, uint8_t port)
{
  printLine();
  Serial.println("Connecting to domain: " + String(host));

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  client.setTimeout(50);
  if (!client.connect(host, port))
  {
    Serial.println("connection failed");
    return;
  }
  Serial.println("Connected!");
  printLine();

  // This will send the request to the server
  //client.print((String)"GET / HTTP/1.1\r\n" +
  //             "Host: " + String(host) + "\r\n" +
  //             "Connection: close\r\n\r\n");
  //unsigned long timeout = millis();
  //while (client.available() == 0) 
  //{
  //  if (millis() - timeout > 500) 
  // {
  //    Serial.println(">>> Client Timeout !");
  //    client.stop();
  //    return;
  //  }
  //}

  // Read all the lines of the reply from server and print them to Serial
  //while (client.available()) 
  //{
  //  String line = client.readStringUntil('\r');
  //  Serial.print(line);
  //}

  Serial.println();
  Serial.println("closing connection");
  client.stop();
}

void partOne()
{
  requestURL(hostDomain11, hostPort);
  requestURL(hostDomain12, hostPort);
  requestURL(hostDomain13, hostPort);
  requestURL(hostDomain14, hostPort);
}

void partTwo()
{
  requestURL(hostDomain21, hostPort);
  requestURL(hostDomain22, hostPort);
}
void partThree()
{
  requestURL(hostDomain31, hostPort);
  requestURL(hostDomain32, hostPort);
  requestURL(hostDomain33, hostPort);
  requestURL(hostDomain34, hostPort);
}

void partFour()
{
  requestURL(hostDomain41, hostPort);
  requestURL(hostDomain42, hostPort);
  requestURL(hostDomain43, hostPort);
  requestURL(hostDomain44, hostPort);
}
void partFive()
{
  requestURL(hostDomain51, hostPort);
  requestURL(hostDomain52, hostPort);
}

void partSix()
{
  requestURL(hostDomain61, hostPort);
  requestURL(hostDomain62, hostPort);
}

void printLine()
{
  Serial.println();
  for (int i=0; i<30; i++)
    Serial.print("-");
  Serial.println();
}
