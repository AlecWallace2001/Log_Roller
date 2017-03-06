#include <WiFi.h>


String tempString = "temp";
byte mac[6];
const uint32_t cTimeout = 1;
const char* hGoogle = "www.google.com";
String BCode = "";

//Payloads
const char* hostDomain1 = "WerenostrangerstoloveYouknowtherulesandsodoIAfullcommitmentswhatImthinkingofYouwouldntgetthisfromanyotherguyIjustwanttotellyouhowImfeelingGottamakeyouunderstandNevergonnagiveyouupnevergonnaletyoudownNevergonnarunaroundanddesertyouNevergonnamakeyoucrynevergonnasaygoodbyeNevergonnatellalieandhurtyouWeveknowneachotherforsolongYourheartsbeenachingbutyouretooshytosayitInsidewebothknowwhatsbeengoingonWeknowthegameandweregonnaplayitAndifyouaskmehowImfeelingDonttellmeyouretooblindtoseeNevergonnagiveyouupnevergonnaletyoudownNevergonnarunaroundanddesertyouNevergonnamakeyoucrynevergonnasaygoodbyeNevergonnatellalieandhurtyouNevergonnagiveyouupnevergonnaletyoudownNevergonnarunaroundanddesertyouNevergonnamakeyoucrynevergonnasaygoodbyeNevergonnatellalieandhurtyouWeveknowneachotherforsolongYourheartsbeenachingbutyouretooshytosayitInsidewebothknowwhatsbeengoingonWeknowthegameandweregonnaplayitIjustwanttotellyouhowImfeelingGottamakeyouunderstandNevergonnagiveyouupnevergonnaletyoudownNevergonnarunaroundanddesertyouNevergonnamakeyoucrynevergonnasaygoodbyeNevergonnatellalieandhurtyou";
const char* hostDomain2 = "<iframe width='560' height='315' src='https://www.youtube.com/embed/dQw4w9WgXcQ' frameborder='0' allowfullscreen></iframe>";
const char* hostDomain3 = "ShepackedmybagslastnightpreflightZerohournineAMAndImgonnabehighasakitebythenImisstheearthsomuchImissmywifeItslonelyoutinspaceOnsuchatimelessflightAndIthinkitsgonnabealonglongtimeTilltouchdownbringsmeroundagaintofindImnotthemantheythinkIamathomeOhnononoImarocketmanRocketmanburningouthisfuseupherealoneAndIthinkitsgonnabealonglongtimeTilltouchdownbringsmeroundagaintofindImnotthemantheythinkIamathomeOhnononoImarocketmanRocketmanburningouthisfuseupherealoneMarsaintthekindofplacetoraiseyourkidsInfactitscoldashellAndtheresnoonetheretoraisethemifyoudidAndallthisscienceIdontunderstandItsjustmyjobfivedaysaweekArocketmanarocketmanAndIthinkitsgonnabealonglongtimeTilltouchdownbringsmeroundagaintofindImnotthemantheythinkIamathomeOhnononoImarocketmanRocketmanburningouthisfuseupherealoneAndIthinkitsgonnabealonglongtimeTilltouchdownbringsmeroundagaintofindImnotthemantheythinkIamathomeOhnononoImarocketmanRocketmanburningouthisfuseupherealoneAndIthinkitsgonnabealonglongtimeAndIthinkitsgonnabealonglongtimeAndIthinkitsgonnabealonglongtimeAndIthinkitsgonnabealonglongtimeAndIthinkitsgonnabealonglongtimeAndIthinkitsgonnabealonglongtimeAndIthinkitsgonnabealonglongtimeAndIthinkitsgonnabealonglongtime";
const char* hostDomain4 = "It'sasmallworld,it'sasmallworldIt'sasmallworld,it'sasmallworldIt'saworldoflaughter,aworldoftearsIt'saworldofhopeandaworldoffearsThere'ssomuchthatweshare,thatit'stimewe'reawareIt'sasmallworldafterallIt'sasmallworldafterall,it'sasmallworldafterallIt'sasmallworldafterall,it'sasmall,small,small,smallworldThereisjustonemoonandonegoldensunAndasmilemeansfriendshiptoeveryoneThoughthemountainsbewideandtheoceansarewideIt'sasmallworldafterallIt'sasmallworldafterall,it'sasmallworldafterallIt'sasmallworldafterall,it'sasmall,smallworldIt'sasmallworldafterall,nomatterifyou'rebigorsmallComeoneverybodylet'sbouncetothisLet'splaysomelovewithalittletwistIt'sasmallworld,it'sasmallworldIt'saworldoflaughter,aworldoftearsIt'saworldofhopeandaworldoffearsThere'ssomuchthatweshare,thatit'stimewe'reawareIt'sasmallworldafterall,it'sasmallworldIt'sasmallworldafterall(Afterall,everybodynow)It'sasmallworldafterall(Afterall,canyouhearmenow?)It'sasmallworldafterall(Comeon,comeon)It'sasmall,small,small,smallworldIt'sasmallworld,afterall(Afterall,everybodynow)It'sasmallworldafterall(Afterall)It'sasmallworldafterallIt'sasmall,small,small,smallworldIt'sasmallworldafterall,it'sasmallworldafterallIt'sasmallworldafterall,it'sasmall,small,small,smallworldIt'sasmallworldafterall,it'sasmallworldafterallIt'sasmallworldafterall,it'sasmall,small,small,smallworld";
const char* hostDomain5 = "<iframe width='560' height='315' src='https://www.youtube.com/embed/CbIhYhrOJAg' frameborder='0' allowfullscreen></iframe>";
const char* hostDomain6 = "Travelinginafried-outcombieOnahippietrailheadfullofzombieImetastrangeladyshemademenervousShetookmeinandgavemebreakfastAndshesaidDoyoucomefromalanddownunder?Wherewomenglowandmenplunder?Cantyouhearcantyouhearthethunder?YoubetterrunyoubettertakecoverBuyingbreadfromamaninBrusselsHewassix-foot-fourandfullofmusclesIsaiddoyouspeak-amylanguage?HejustsmiledandgavemeavegemitesandwichAndhesaidIcomefromalanddownunderWherebeerdoesflowandmenchunderCantyouhearcantyouhearthethunder?YoubetterrunyoubettertakecoveryeahLyininadeninBombayWithaslackjawandnotmuchtosayIsaidtothemanareyoutryingtotemptmeBecauseIcomefromthelandofplenty?AndhesaidDoyoucomefromalanddownunder?(ohyeahyeah)Wherewomenglowandmenplunder?Cantyouhearcantyouhearthethunder?YoubetterrunyoubettertakecoverLivinginalanddownunderWherewomenglowandmenplunderCantyouhearcantyouhearthethunder?YoubetterrunyoubettertakecoverLivinginalanddownunderWherewomenglowandmenplunderCantyouhearcantyouhearthethunder?YoubetterrunyoubettertakecoverLivinginalanddownunderWherewomenglowandmenplunderCantyouhearcantyouhearthethunder?YoubetterrunyoubettertakecoverLivinginalanddownunderWherewomenglowandmenplunderCantyouhearcantyouhearthethunder?";
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
  Serial.setTimeout(500);
  digitalWrite(LED_PIN, LOW); // LED off
}

void loop()
{
  Serial.println("scan start");

  // WiFi.scanNetworks will return the number of networks found
  BCode = "SC";
  blinkCode(BCode);
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
        BCode = "CT";
        blinkCode(BCode);
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
        }
        WiFi.disconnect();
        delay(5000);
      }
    }
  }
  BCode = "BS";
  blinkCode(BCode);
  delay(5000);
  Serial.println("");
}

void connectToWiFi(char * ssid)
{
  int ledState = 0;

  printLine();
  Serial.println("Connecting to this WiFi network: " + String(ssid));
  //WiFi.begin(networkName, networkPswd);
  WiFi.begin(ssid);
  unsigned long timeout = millis();
  while (WiFi.status() != WL_CONNECTED) 
  {
    // Blink LED while we're connecting:
    digitalWrite(LED_PIN, ledState);
    ledState = (ledState + 1) % 2; // Flip ledState
    delay(1000);
    Serial.print(".");
    if (millis() - timeout > 20000) 
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

void requestURL(const char * host)
{
  //Serial.setTimeout(1);
  printLine();
  Serial.println("Connecting to Google");

  // Use WiFiClient class to create TCP connections
  WiFiClient client;  
  BCode = "CU";
  blinkCode(BCode);
  unsigned long urlStartTime = millis();
  if (!client.connect(hGoogle, hostPort))
  {
    Serial.println("connection failed");
    return;
  }
  Serial.println("Connected!");
  printLine();
  Serial.println("Delivering Payload");
  printLine();
  
  BCode = "DP";
  blinkCode(BCode);
  // This will send the request to the server
  client.print((String)"GET / HTTP/1.1\r\n" +
               "Host: " + String(host) + "\r\n" +
               "Connection: close\r\n\r\n");
  unsigned long timeout = millis();
  while (client.available() == 0) 
  {
    if (millis() - timeout > 5000) 
   {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) 
  {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
  Serial.print("Process time for ");
  Serial.print(host);
  Serial.print(": ");
  Serial.println(millis()-urlStartTime);
  client.stop();
}

void partOne()
{
  requestURL(hostDomain1);
}

void partTwo()
{
  requestURL(hostDomain2);
}
void partThree()
{
  requestURL(hostDomain3);
}

void partFour()
{
  requestURL(hostDomain4);
}
void partFive()
{
  requestURL(hostDomain5);
}

void partSix()
{
  requestURL(hostDomain6);
}

void printLine()
{
  Serial.println();
  for (int i=0; i<30; i++)
    Serial.print("-");
  Serial.println();
}

void blinkCode(String code)
{
  if (code == "SC"){
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
  } else if (code == "CT"){
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
  } else if (code == "CU"){
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
  } else if (code == "DP"){
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
  } else if (code == "DP"){
    digitalWrite(LED_PIN, HIGH);
    delay(150);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
    digitalWrite(LED_PIN, HIGH);
    delay(50);
    digitalWrite(LED_PIN, LOW);
    delay(50);
  }
}    
