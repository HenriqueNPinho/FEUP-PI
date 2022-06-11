#include <Arduino.h>
#include <HCSR04.h>
#include <M5Atom.h>
#include <FastLED.h>
#include <stack>


using namespace std;
#define FILLING 0
#define FULL 1
#define Min_Value 5
#define Max_Value 100
#define TRUE 5
#define TRIES 5
#define CHECK_STATE 2

stack<int> pilha;
int state = FILLING;
int test_counter=0;
int tries=TRIES;
int counter = 0;

//-----------------------CODIGO SANTOS-----------------------------------------

#include <WiFi.h>
#include <PubSubClient.h>

const char *ssid = "net"; //substituir pela net
const char *pass = "pass"; //substituir pela pass da net

const char *broker = "broker.mqttdashboard.com";
const int port = 8000;

#define clientId "clientId-1234"


WiFiClient espClient;
PubSubClient client(broker, port, espClient);

void setupWifi()
{
    delay(100);
    Serial.print("\nConnecting to");
    Serial.println(ssid);
    WiFi.begin(ssid, pass);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
        Serial.print("-");
    }
    Serial.print("\nConnected to");
    Serial.println(ssid);
}

void reconnect()
{
    while (!client.connected())
    {
        Serial.print("\nConnecting to ");
        Serial.println(broker);
        if (client.connect(clientId))
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
    int trigger2 = 0;

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
      client.publish("secretaria", "olaolaol");
    } 

    if (counter == 0) {
      M5.dis.drawpix(0, 0x00FF00);
      Serial.println("livre");
      client.publish("secretaria", "adasdasd");
    }

     /* switch (state)
      {
      case FILLING:
        if(trigger==1){
          if(pilha.size()<5){
            pilha.push(1);
          }
          int s = pilha.size();
          //printf("Size: %d\n",s);
          if (s==5){
            state = FULL;
            Serial.println("Ocupado");
          }
          Serial.println("Livre");
        }
        else {
          while(!pilha.empty()) {
            pilha.pop();

          }
          int s = pilha.size();
          
          Serial.println("Livre");
        }
        break;
      
      case FULL:

        if(trigger !=1){
          state = CHECK_STATE;
          test_counter=0;
          tries=TRIES;
        }
         Serial.println("Ocupado");
        break;
      
      case CHECK_STATE :
        
        if(trigger ==1){
          test_counter+=1;
        }
        tries-=1;
        if (tries ==0){
          if (test_counter>=0.75*TRIES){
            state = FULL;
             Serial.println("Ocupado");
          }
          else{
            state = FILLING;
            while(!pilha.empty()) {
              pilha.pop();
            }
            Serial.println("Livre");
          }
        }
         Serial.println("Ocupado");

        break;

      default:
        break;
      } */


    //M5.update();
    delay(1000);
}

