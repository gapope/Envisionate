#include "header.h"

//declaring arrays
float intensity[5];
float dist[3];

//Debug prep
void setup() {
  pinMode(trig_L, OUTPUT);
  pinMode(echo_L, INPUT);
  pinMode(trig_C, OUTPUT);
  pinMode(echo_C, INPUT);
  pinMode(trig_R, OUTPUT);
  pinMode(echo_R, INPUT);
  
  //Serial connection for testing, BAUD 9600
  Serial.begin(9600);
  //Serial.print("WOOT LETS DO THIS BITCHHH");

  while(!Serial);
  //pinMode()
}

//Main functions
void loop() {
  Serial.println("Calling pulses");
  get_Distance(dist);
  //delay(3000);
  get_Intensity(dist, intensity);
  //delay(3000);
  pulsate(intensity);
  //delay(5000);

}
