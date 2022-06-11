
#define Min_Value 5
#define Max_Value 100
#define FILLING 0
#define FULL 1
#define CHECK_STATE 2
#define TRIES 5
//#include <HCSR04.h>
//#include <M5Atom.h>
//#include <FastLED.h>
#include <stack>
#include <iostream>
#include <unistd.h> 
using namespace std;


int state = FILLING;
stack<int> pilha;
int test_counter=0;
int tries=TRIES;
const int microToSeconds = 1000000;   
const double delay1 = 1 * microToSeconds;     

/*
void setup () {
      
      M5.begin(false, false, true);
      //M5.dis.drawpix(0, 0x00ff00);
      //pinMode(27, OUTPUT);
      Serial.begin(9600);  // We initialize serial connection so that we could print values from sensor.
      Serial1.begin(115200);
    
  }*/

  //int loop () {
  int loop (int i) {
      // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
      //int distance = distanceSensor.measureDistanceCm();
      //Serial.print("Distancia: ");
      //Serial.print(distance);
      //Serial.print("cm");
      //int trigger =0;
      //if (distance > Min_Value && distance < Max_Value){
      //  trigger=1;
      //}

      //testing
      int trigger=i;


      switch (state)
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
            return 1;
          }
          return -1;
        }
        else {
          while(!pilha.empty()) {
            pilha.pop();

          }
          int s = pilha.size();
          //printf("Size apagado: %d\n",s);
          return -1;
        }
        break;
      
      case FULL:

        if(trigger !=1){
          state = CHECK_STATE;
          test_counter=0;
          tries=TRIES;
        }
        return 1;
        break;
      
      case CHECK_STATE :
        
        if(trigger ==1){
          test_counter+=1;
        }
        tries-=1;
        if (tries ==0){
          if (test_counter>=0.75*TRIES){
            state = FULL;
            return 1;
          }
          else{
            state = FILLING;
            while(!pilha.empty()) {
              pilha.pop();
            }
            return -1;
          }
        }
        return 1;

        break;

      default:
        break;
      }
      
      /*
      if (distance > Min_Value && distance < Max_Value) {
        M5.dis.drawpix(0, 0xFF0000);
        //Serial.println(" - Ocupado");
        pilha.push(1);
      } else {
        M5.dis.drawpix(0, 0x00FF00);
        //Serial.println(" - Livre");
        pilha.push(0);
      }
      
      //M5.update();
      */
      return 1;
  }


void table_state (int curr) {
  if (curr ==1){
    printf("OCUPADO\n");
    //printf("%d\n",state);
  }
  else if (curr ==-1){
    printf("Livre\n");
    //printf("%d\n",state);
  }
}

int main(){
  // Initialize sensor that uses digital pins 22 and 19.
  //const byte triggerPin = 22;
  //const byte echoPin = 19;

  //UltraSonicDistanceSensor distanceSensor(triggerPin, echoPin);

  //setup();

  int array [22]={1,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1,0,0,0,1,1,1};
  
  //while (true) {
  for (int i=0; i<22; i++){
    int current_state=loop(array[i]);  
    //current_state vai ser 1 quando ocupado e 0 quando livre
    //consoante o seu valor dar publish da respetiva mensagem
    //usar current_state como input para a função de publish
    table_state(current_state);
    usleep(delay1); 
  }
  return 1;
}