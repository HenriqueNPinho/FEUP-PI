#include "Arduino.h"
#include <M5Atom.h>

int ir_recv_pin = 32; // set the input pin.  
int ir_send_pin = 26;

int last_recv_value = 0;
int cur_recv_value = 0;

void setup() {
  M5.begin(true, true, true);
  Serial.begin(115200);
  //delay(1000);
  //M5.dis.drawpix(0, 0x00ff00);
  pinMode(ir_recv_pin, INPUT);
  pinMode(ir_send_pin, OUTPUT);
  //send infrared light.  发送红外线

  //now, you can see the infrared light through mobile phone camera. 

  digitalWrite(ir_send_pin, 1);
  Serial.println("Test for IR receiver: ");
}

void loop() {
  //now, once you press the button on a remote controller to send infrared light. 
  //the Serial will display "detected!" 
  cur_recv_value = digitalRead(ir_recv_pin);
  if(last_recv_value != cur_recv_value){
    if(cur_recv_value == 0){  //0: detected 1: not detected 
      Serial.println("detected!");

      M5.dis.drawpix(0, 0x0000f0);
    } else {
      M5.dis.drawpix(0, 0xff0000);
    }
    last_recv_value = cur_recv_value;
  }
  delay(50);
  M5.update();
}
