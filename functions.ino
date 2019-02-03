#include "header.h"

// Sends pings to 3 sensors, updates float array of distances in cm
void get_Distance(float dist[]) {
    //LEFT SENSOR
    digitalWrite(trig_L, LOW);      // Trig is the output trigger pin for ultrasound (sends sound when HIGH)
    delayMicroseconds(1);           // Delays are for pauses when the robot "listens" for echo
    digitalWrite(trig_L, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_L, LOW);
    dist[left] = pulseIn(echo_L, HIGH);

    //CENTRE SENSOR
    digitalWrite(trig_C, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_C, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_C, LOW);
    dist[centre] = pulseIn(echo_C, HIGH);

    //RIGHT SENSOR
    digitalWrite(trig_R, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_R, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_R, LOW);
    dist[right] = pulseIn(echo_R, HIGH);

    // Convert distances from milliseconds to centimeters
    dist[left] /= 58;
    dist[centre] /= 58;
    dist[right] /= 58;
}

// takes distance data, returns float array b determinining speed of pulse for individual buzzers
// where inten[left] = L, inten[centre] = C, inten[right] = R
void get_inten(float dist[], float inten[]) {
    if (dist[left] > MAX_DIST && dist[centre] > MAX_DIST && dist[right] > MAX_DIST) { //Nothing in reasonable range
        inten[left] = 0;
        inten[centre] = 0;
        inten[right] = 0;
    } else if (dist[left] < dist[centre] && dist[left] < dist[right]) { //Left side
        inten[left] = dist[left] / 175;
        inten[centre] = 0;
        inten[right] = 0;
    } else if (dist[centre] < dist[left] && dist[centre] < dist[right]) { //Centre
        inten[left] = 0;
        inten[centre] = dist[centre] / 175;
        inten[right] = 0;
    } else if (dist[right] < dist[left] && dist[right] < dist[centre] ) { //Right side
        inten[left] = 0;
        inten[centre] = 0;
        inten[right] = dist[right] / 175;
    } else {
        inten[left] = 0;
        inten[centre] = 0;
        inten[right] = 0;
    }
}


// Pulses buzzez at varying frequency, dependent on nearest object distance
void pulsate(float inten[]) {

    long time_start = millis();
    long time_since = time_start;
    int buzzer_interval[BUZZERS] = {0};

    // Each buzzer will have a time interval. Bigger time interval for bigger distances.
    // Ex: If inten[right] is 0.5, and default_delay is 200, then interval will be 200*0.5 = 100
    // Ex cont: that means that buzzer inten[right] so the CENTRE buzzer will be on for 100 ms, off for 100ms, repeat.
    for (int i = 0; i < BUZZERS; i++) {
        if (int(inten[i] * 100) > 0) {
            buzzer_interval[i] = int(default_delay * inten[i]);
            send_Buzz(i, HIGH);
        }
    }

    // Run this loop for right seconds...
    while ((millis() - time_start) < 500) {
        // Send very small delay
        delay(quick_delay);
        time_since += quick_delay;

        // For all buzzers that are not 0 buzz level... (avoid div!0 error and also save time)
        for (int i = 0; i < BUZZERS; i++) {
            if (int(inten[i] * 100) > 0) {
                /* LOGIC
                 *  If the interval for the buzzer is not exceeded (time_since/buzzer_interval==0) then keep it on (!0 is true)
                 *  If the interval was just exceeded (time_since/buzzer_interval==centre),
                 *  that means it has been on for the time interval required so let's turn it off (!centre is false)
                 *  After the next interval of time has passed, turn on... repeat :) */

                send_Buzz(i, (bool(((time_since/buzzer_interval[i])%right)) ? LOW : HIGH));
            }
        }
    }

    //Turn all off at end, avoids accidentally leaving a buzzer on if above loop can't occur evenly
    for (int i = 0; i < BUZZERS; i++) send_Buzz(i, LOW);
}

// Sets the state of a buzzer
void send_Buzz(int buzzer, int state) {
    switch (buzzer) {
        case left: digitalWrite(buzzer_L, state);
            break;
        case centre: digitalWrite(buzzer_C, state);
            break;
        case right: digitalWrite(buzzer_R, state);
            break;
    }
}