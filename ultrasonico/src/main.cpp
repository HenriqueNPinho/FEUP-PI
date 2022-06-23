#include <Arduino.h>
#include <HCSR04.h>
#include <M5Atom.h>
#include <FastLED.h>
#include <stack>

#define Min_Value 5
#define Max_Value 100

int counter = 0;

//-----------------------CODIGO SANTOS-----------------------------------------

#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

const char *ssid = "tiago"; //substituir pela net
const char *pass = "12345678ti"; //substituir pela pass da net

const char *broker = "broker.mqttdashboard.com";
const int port = 1883;




WiFiClient espClient;
PubSubClient client(broker, port, espClient);

void setupWifi() {

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());

}

void reconnect()
{

    uint64_t chipid=ESP.getEfuseMac();//The chip ID is essentially its MAC address(length: 6 bytes).
    Serial.printf("ESP32 Chip ID = %04X\n",(uint16_t)(chipid>>32));//print High 2 bytes
    //Serial.printf("%08X\n",(uint32_t)chipid);//print Low 4bytes.
     Serial.println((uint16_t)(chipid>>32),HEX);
      uint16_t chip = (uint16_t)(chipid>>32);
      Serial.println(chip);
      String up = (String)chip;
      Serial.println(up);
 
    while (!client.connected())
    {
        Serial.print("\nConnecting to ");
        Serial.println(broker);
        if (client.connect(up.c_str()))
        {
            Serial.print("\nConnected to ");
            Serial.println(broker);
        }
        else
        {
            Serial.println("\nTrying connect again");
            delay(5000);
        }
    }
}


//-----------------------CODIGO SANTOS-----------------------------------------



// Initialize sensor that uses digital pins 22 and 19.
const byte triggerPin = 22;
const byte echoPin = 19;

UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

void setup () {
    
    M5.begin(false, false, true);
    //M5.dis.drawpix(0, 0x00ff00);
    //pinMode(27, OUTPUT);
    
    Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
    Serial1.begin(115200);
    setupWifi();
    client.setServer(broker, port);
   
}

void loop () {

   if (!client.connected())
    {
        reconnect();
    }
    client.loop(); 
    
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    int distance = distanceSensor.measureDistanceCm();
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println("cm");
    int trigger = 0;

    if (distance > Min_Value && distance < Max_Value) {
      //M5.dis.drawpix(0, 0xFF0000);
      //Serial.println(" - Ocupado");
      trigger = 1;

    } else {
      //M5.dis.drawpix(0, 0x00FF00);
      //Serial.println(" - Livre");
      trigger = 0;
    }


    if (trigger == 1 ) {

      if (counter < 5 ) {
        counter++;
      }

    } else {

      if (counter > 0) {
        counter--;
      }

    }

    if (counter == 5) {
      M5.dis.drawpix(0, 0xFF0000);
      Serial.println("ocupado");

      char buffer[256];
      DynamicJsonDocument doc(1024);

      doc["desk"] = 1;
      doc["sensor"]   = "Unavailable";

      serializeJson(doc, buffer);

      client.publish("feup/dei/secretaria", buffer);
    } 

    if (counter == 0) {
      M5.dis.drawpix(0, 0x00FF00);
      Serial.println("livre");

      char buffer[256];
      DynamicJsonDocument doc(1024);

      doc["desk"] = 1;
      doc["sensor"]   = "Free";

      serializeJson(doc, buffer);

      client.publish("feup/dei/secretaria", buffer);
    }

    delay(1000);
}

