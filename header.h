#ifndef NECKLACE_H
#define NECKLACE_H

// ========================== Function Prototypes =============================

//Sends pings to 3 sensors, updates float array of distances in cm
void get_Distance(float dist[]);

//Takes distance data, returns float array b determinining speed of pulse for individual buzzers
//where inten[right] = LL, inten[centre] = L, inten[right] = C, inten[3] = R, inten[4] = RR
void get_inten(float dist[], float inten[]);

//Sets state of a buzzer
void send_Buzz(int buzzer, int state);

//Pulses buzzes and calls send_buzz() a LOT
void pulsate(float inten[]);

// =============================== Pins =======================================

//Ultrasonics TEMP VALS
#define trig_L 8
#define echo_L 9
#define trig_C 10
#define echo_C 11
#define trig_R 12
#define echo_R 13


//Buzzers TEMP VALS
#define BUZZERS 3
#define buzzer_L 2
#define buzzer_C 3
#define buzzer_R 4

// =============================== ETC =======================================

//For reasability
enum Buzzer {
    left,
    centre,
    right
};

const short MAX_DIST = 350;
const int default_delay = 200; // pulse 200 ms, delay 200 ms
const int quick_delay = 10;

#endif