#include "header.h"

//Declaring arrays
float dist[3];
float inten[BUZZERS];

//Pin prep
void setup() {
  pinMode(trig_L, OUTPUT);
  pinMode(echo_L, INPUT);
  pinMode(trig_C, OUTPUT);
  pinMode(echo_C, INPUT);
  pinMode(trig_R, OUTPUT);
  pinMode(echo_R, INPUT);

  pinMode(buzzer_L, OUTPUT);
  pinMode(buzzer_C, OUTPUT);
  pinMode(buzzer_R, OUTPUT);
}

//Main function calls
void loop() {
  get_Distance(dist);
  get_inten(dist, inten);
  pulsate(inten);
}