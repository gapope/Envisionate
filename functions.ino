// WRITE ALL MINI FUNCTIONS HERE, REMEMBER TO PROTOTYPE IN HEADER.H :)))




// NOTE WE GON' HAVE TO CHANGE THIS BECAUSE THIS IS FOR ONE ULTRASOUND NOT THREE
float distance_test() {
  float distance; // holds front distance value

  // send out sonic pulses, once they hit an object they should bounce back (echo)
  digitalWrite(trig, LOW); // Trig is the output trigger pin for ultrasound (sends sound when HIGH)
  delayMicroseconds(2);    // Delays are for pauses when the robot "listens" for echo
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Get the echo. Sensors determine distance based on strength and speed of return
  // Echo is input echo pin for ultrasound, HIGH means detected.

  distance = pulseIn(Echo, HIGH);

  // Calculate, display, and return distance, 58 is the calibrated conversion from ms to cm
  distance = distance / 58;
  return distance;
}



// Miasya is figuring this part out teehee, feel free to collab (as always!)
bool start_buzz(){



    return true; // If successful
    
}