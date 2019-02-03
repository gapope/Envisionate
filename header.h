#ifndef NECKLACE_H
#define NECKLACE_H

// ========================== Function Prototypes =============================

// Sends pings to 3 sensors, returns float array of distances in cm where a[0] = dist[0], a[1] = dist[1], a[2] = dist[2].
void get_Distance(float dist[]);

// takes distance data, returns float array b determinining speed of pulse for individual buzzers
// where intensity[0] = LL, intensity[1] = L, intensity[2] = C, intensity[3] = R, intensity[4] = RR
void get_Intensity(float dist[], float intensity[]);

// Takes int which indicates which buzzer, and bool to turn on or off
void send_Buzz (int buzzer, bool turn_on);

// Pulses buzzes and calls send_buzz() a LOT
// Key: intensity[0] = LL, intensity[1] = L, intensity[2] = C, intensity[3] = R, intensity[4] = RR
void pulsate (float intensity[]);

// =============================== Pins =======================================

//Ultrasonics TEMP VALS
#define trig_L 8
#define echo_L 9
#define trig_C 10
#define echo_C 11
#define trig_R 12
#define echo_R 13


//Buzzers TEMP VALS
#define buzzer_C 0
#define buzzer_L1 1
#define buzzer_L2 4
#define buzzer_R1 5
#define buzzer_R2 6

int default_delay = 100; // pulse 200 ms, delay 200 ms
int quick_delay = 10;

#endif
