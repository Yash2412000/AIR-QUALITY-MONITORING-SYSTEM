#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>


//----------- Channel Details -------------//
unsigned long Channel_ID = 1246991; // Channel ID
const char * WriteAPIKey = "1565W434E21D4VX2"; // Your write API Key
char ssid[] =  "Rai jio5G";     // replace with your wifi ssid and wpa2 key
const char* pass =  "raivtr@145";

const int Field_number = 1;
float t=0;
float value;
int raw;
WiFiClient  client;

int mq2A0 = A0;

// Your threshold value. You might need to change it.
int sensorThres = 600;

void setup() { 
   pinMode(mq2A0, INPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin("", "");
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(200);
    Serial.print("..");
  }
  Serial.println();
  Serial.println("NodeMCU is connected!");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() 
{
 t = analogRead(A0);  // Read sensor value and stores in a variable t
 
  Serial.print("Airquality = ");

  Serial.println(t);

   if (t<=50)
   {
   Serial.print("Fresh Air ");
   }
  else if( t>=100 && t<=300 )
   {  
   Serial.print("Poor Air");
   }
  else if (t>=300 )
  {
  Serial.print("Very Poor");
  }
  
  ThingSpeak.writeField(Channel_ID, Field_number, 1,WriteAPIKey);
  delay(2000);
}
