#include <Arduino.h>
#include <HCSR04.h>
#include <M5Atom.h>
#include <FastLED.h>
#include <stack>
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <relevants.h>

//
int counter = 0;
bool isFree = true;
bool isAway = false;

//
DynamicJsonDocument doc(256);
char buffer_Free[64];
char buffer_Away[64];
char buffer_Unavailable[64];

//
WiFiClient espClient;
PubSubClient client(BROKER, PORT, espClient);

// Initialize sensor that uses digital pins 22 and 19.
const byte triggerPin = 22;
const byte echoPin = 19;
UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);


//
void setupBuffer() {
    doc["desk"] = TABLE_NUMBER;
    doc["sensor"]   = "Away";
    serializeJson(doc, buffer_Away);
    doc["sensor"]   = "Free";
    serializeJson(doc, buffer_Free);
    doc["sensor"]   = "Unavailable";
    serializeJson(doc, buffer_Unavailable);
}


//
void publish(int op) {
    switch (op) {
        case AWAY:
        client.publish("feup/dei/secretaria", buffer_Away);
        break;

        case FREE:
        client.publish("feup/dei/secretaria", buffer_Free);
        break;

        case UNAVAILABLE:
        client.publish("feup/dei/secretaria", buffer_Unavailable);
        break;
    }
}


//Connection with WIFI
void setupWifi() { 

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASS);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(1000);
    }
    Serial.println(WiFi.localIP());

}


//Reconnection with broker
void reconnect() { 

    uint64_t chipid=ESP.getEfuseMac();
    Serial.printf("ESP32 Chip ID = %04X\n",(uint16_t)(chipid>>32));//print High 2 bytes
    Serial.println((uint16_t)(chipid>>32),HEX);
    uint16_t chip = (uint16_t)(chipid>>32);
    Serial.println(chip);
    String up = (String)chip;
    Serial.println(up);

    while (!client.connected()) {
        Serial.print("\nConnecting to ");
        Serial.println(BROKER);

        if (client.connect(up.c_str())) {

            Serial.print("\nConnected to ");
            Serial.println(BROKER);

        } else {

            Serial.println("\nTrying connect again");
            delay(5000);

        }
    }
}



//
void setup () {
  M5.begin(false, false, true);
  M5.dis.drawpix(0, WHITE_COLOR);
  Serial.begin(9600); 
  Serial1.begin(115200);
  setupWifi();
  client.setServer(BROKER, PORT);
  
  setupBuffer();
}


//
void loop () {

    if (!client.connected()) {
        reconnect();
    }
    client.loop(); 

    if (M5.Btn.wasPressed() && !isAway) {
        M5.dis.drawpix(0, AWAY_COLOR);
        isAway = true;
        publish(AWAY);

    } else if (M5.Btn.wasPressed() && isAway) {
        M5.dis.drawpix(0, UNAVAILABLE_COLOR);
        isAway = false;
        publish(UNAVAILABLE);
    }

    
    if (!isAway) {
        int distance = distanceSensor.measureDistanceCm();
        Serial.print("Distancia: ");
        Serial.print(distance);
        Serial.println("cm");
        int trigger = 0;

        if (distance > MIN_VALUE && distance < MAX_VALUE) {
        trigger = 1;
        }

        if (trigger == 1 && counter < 5) {
            counter++;
        } else if (trigger == 0 && counter > 0) {
            counter--;
        }

        if (counter == 5 && isFree) {

        M5.dis.drawpix(0, UNAVAILABLE_COLOR);
        Serial.println("ocupado");

        publish(UNAVAILABLE);

        isFree = false;

        } else if (counter == 0 && !isFree) {

        M5.dis.drawpix(0, FREE_COLOR);
        Serial.println("livre");
        publish(FREE);
        isFree = true;

        }
    }
    
    M5.update();
    delay(1000);
}

