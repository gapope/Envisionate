#ifndef NECKLACE_H
#define NECKLACE_

// ========================== Function Prototypes =============================

//  main_algorithm
int locate();             // Sends trig, waits for echo, and outputs which buzzer

// sensors
float distance_test();               // test the front distance to objects


// =============================== Pins =======================================

extern const short Trig; // output trigger pin for ultrasound (sends sound)
extern const short Echo; // input echo pin for ultrasound(echo from sound sent)

extern const short trig_C = ;//
extern const short echo_C = ;//
extern const short trig_L = ;//
extern const short echo_L = ;//
extern const short trig_R = ;//
extern const short echo_R = ;//

extern const short buzzer_C = A2;
extern const short buzzer_L1 = A3;
extern const short buzzer_L2 = A4;
extern const short buzzer_R1 = A5;
extern const short buzzer_R2= A6;

#endif