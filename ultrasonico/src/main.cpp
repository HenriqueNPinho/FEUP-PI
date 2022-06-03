#include <Arduino.h>
#include <HCSR04.h>
#include <M5Atom.h>
#include <FastLED.h>


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
   
}

void loop () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    int distance = distanceSensor.measureDistanceCm();
    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.print("cm");
    if (distance > 5 && distance < 100) {
      M5.dis.drawpix(0, 0xFF0000);
      Serial.println(" - Ocupado");
    } else {
      M5.dis.drawpix(0, 0x00FF00);
      Serial.println(" - Livre");
    }
    //M5.update();
    delay(1000);
}