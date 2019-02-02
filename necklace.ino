#include "header.h"

void setup() {
  // put your setup code here, to run once:

  pinMode(buzzer_1, OUTPUT);

  // Initialize pins here later 
}



void loop() {
  // put your main code here, to run repeatedly:

  buzzer_1 = HIGH; //?? or something like this. plz fix ittt
  delay(200);
  buzzer_1 = LOW;
  delay (200);

  
  // Scan around us
  // Take the distances and feed them to a start_buzz() function??


}
