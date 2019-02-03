#ifndef NECKLACE_H
#define NECKLACE_

// ========================== Function Prototypes =============================

// Sends pings to 3 sensors, returns float array of distances in cm where a[0] = dist_L, a[1] = dist_C, a[2] = dist_R.
float[] get_Distance ();

// takes distance data, returns float array b determinining speed of pulse for individual buzzers
// where b[0] = LL, b[1] = L, b[2] = C, b[3] = R, b[4] = RR
float[] get_Intensity(float d[]);
void pulsate (float f[]);
void send_buzz (int buzzer, bool turn_on);

// =============================== Pins =======================================

//Ultrasonics TEMP VALS
#define trig_C 8
#define echo_C 9
#define trig_L 10
#define echo_L 11
#define trig_R 12
#define echo_R 13

//Buzzers TEMP VALS
#define buzzer_C 2
#define buzzer_L1 3
#define buzzer_L2 4
#define buzzer_R1 5
#define buzzer_R2 6

#endif