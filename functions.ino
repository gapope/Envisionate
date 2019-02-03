// WRITE ALL MINI FUNCTIONS HERE, REMEMBER TO PROTOTYPE IN HEADER.H :)))
#include "header.h"

// Sends pings to 3 sensors, returns float array of distances in cm where a[0] = dist[0], a[1] = dist[1], a[2] = dist[2].
void get_Distance (float dist[]) {

    // LEFT SENSOR
    digitalWrite(trig_L, LOW);      // Trig is the output trigger pin for ultrasound (sends sound when HIGH)
    delayMicroseconds(2);           // Delays are for pauses when the robot "listens" for echo
    digitalWrite(trig_L, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_L, LOW);
    dist[0] = pulseIn(echo_L, HIGH);

    //Output for testing
    Serial.print("Left sensor: "); Serial.println(dist[0]);

    // CENTER SENSOR
    digitalWrite(trig_C, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_C, HIGH);
    delayMicroseconds(20);
    digitalWrite(trig_C, LOW);
    dist[1] = pulseIn(echo_C, HIGH);

    //Output for testing
    Serial.print("Centre sensor: "); Serial.println(dist[1]);

    // RIGHT SENSOR
    digitalWrite(trig_R, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_R, HIGH);
    delayMicroseconds(20);
    digitalWrite(trig_R, LOW);
    dist[2] = pulseIn(echo_R, HIGH);

    //Output for testing
    Serial.print("Right sensor: "); Serial.println(dist[2]);

    // Convert distances from milliseconds to centimeters
    dist[0] /= 58;
    dist[1] /= 58;
    dist[2] /= 58;

    //Output for testing
    Serial.print("Now in centimeters!!! L: "); Serial.print(dist[0]);
    Serial.print(" C: "); Serial.print(dist[1]);
    Serial.print(" R: "); Serial.println(dist[2]);
}

// takes distance data, returns float array b determinining speed of pulse for individual buzzers
// where intensity[0] = LL, intensity[1] = L, intensity[2] = C, intensity[3] = R, intensity[4] = RR
void get_Intensity (float dist[], float intensity[]) {

    if (dist[0] < dist[1] || dist[0] < dist[2]) {
        //buzzer closest to dist[0] = 1, and the rest are given by the ratio of the closest distance to their distance
        intensity[0] = 1;
        intensity[1] = 1;
        intensity[2] = dist[0]/((dist[1] != 0) ? dist[1] : 1);
        intensity[3] = dist[0]/((dist[1] != 0) ? dist[1] : 1);
        intensity[4] = dist[0]/((dist[2] != 0) ? dist[2] : 1);
    } else if (dist[1] < dist[0] || dist[1] < dist[2]) {
        //buzzer closest to dist[1] = 1;
        intensity[0] = dist[1]/dist[0];
        intensity[1] = dist[1]/dist[0];
        intensity[2] = 1;
        intensity[3] = dist[1]/((dist[2] != 0) ? dist[2] : 1);
        intensity[4] = dist[1]/((dist[2] != 0) ? dist[2] : 1);
    } else if (dist[2] < dist[0] || dist[2] > dist[1] ) {
        //buzzer closest to dist[2] = 1;
        intensity[0] = dist[2]/dist[0];
        intensity[1] = dist[2]/((dist[1] != 0) ? dist[1] : 1);
        intensity[2] = dist[2]/((dist[1] != 0) ? dist[1] : 1);
        intensity[3] = 1;
        intensity[4] = 1;
    } else {
        intensity[0] = 0;
        intensity[1] = 0;
        intensity[2] = 0;
        intensity[3] = 0;
        intensity[4] = 0;
    }
}


// Pulses buzzes
// where intensity[0] = LL, intensity[1] = L, intensity[2] = C, intensity[3] = R, intensity[4] = RR
void pulsate (float intensity[]) {

    long time_start = millis();
    long time_since = time_start;
    int buzzer_interval[5] = {0};

    // Each buzzer will have a time interval. Bigger time interval for bigger distances.
    // Ex: If intensity[2] is 0.5, and default_delay is 100, then interval will be 100/0.5 = 200
    // Ex cont: that means that buzzer intensity[2] so the CENTER buzzer will be on for 200 ms, off for 200ms, repeat.
    for (int i = 0; i < 5; i++) {
        if (intensity[i] != 0) {
            buzzer_interval[i] = int(default_delay/intensity[i]);
            send_Buzz(i, true);
        }
    }

    // Run this loop for 2 seconds...
    while ((millis() - time_start) < 5000) {
        // Send very small delay
        delay(quick_delay);
        time_since += quick_delay;
        // For all buzzers that are not 0 buzz level... (avoid div!0 error and also save time)
        for (int i = 0; i < 5; i++) {
            Serial.print("Intensity ");Serial.print(i);Serial.print(" is ");Serial.println(intensity[i]);
            if (int(intensity[i]) > 0) {
                /* LOGIC
                 *  If the interval for the buzzer is not exceeded (time_since/buzzer_interval==0) then keep it on (!0 is true)
                 *  If the interval was just exceeded (time_since/buzzer_interval==1),
                 *  that means it has been on for the time interval required so let's turn it off (!1 is false)
                 *  After the next interval of time has passed, turn on... repeat :) */
                Serial.print("DECIDING BUZZ: "); Serial.println(!bool(((time_since/buzzer_interval[i])%2)));
                send_Buzz(i, !bool(((time_since/buzzer_interval[i])%2)));        //TEST DIS BITCHH
            }
        }
    }
}

// Takes int which indicates which buzzer, and bool to turn on or off
void send_Buzz (int buzzer, bool turn_on) {
    Serial.println("TRYING TO BUZZ");
    if (turn_on) {
        switch (buzzer) {
            case 0: digitalWrite(buzzer_L2, HIGH);
                Serial.println("L2-ON");
                break;
            case 1: digitalWrite(buzzer_L1, HIGH);
                Serial.println("L1-ON");
                break;
            case 2: digitalWrite(buzzer_C, HIGH);
                Serial.println("C-ON");
                break;
            case 3: digitalWrite(buzzer_R1, HIGH);
                Serial.println("R1-ON");
                break;
            case 4: digitalWrite(buzzer_R2, HIGH);
                Serial.println("R2-ON");
                break;
        }
    } else {
        switch (buzzer) {
            case 0: digitalWrite(buzzer_L2, LOW);
                Serial.println("L2-OFF");
                break;
            case 1: digitalWrite(buzzer_L1, LOW);
                Serial.println("L1-OFF");
                break;
            case 2: digitalWrite(buzzer_C, LOW);
                Serial.println("C-OFF");
                break;
            case 3: digitalWrite(buzzer_R1, LOW);
                Serial.println("R1-OFF");
                break;
            case 4: digitalWrite(buzzer_R2, LOW);
                Serial.println("R2-OFF");
                break;
        }
    }
}
