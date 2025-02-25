// This program stes up timer2 to count the seconds. When 1000ms has
// passed the program updates the flag to indicate that 1 sedcond has
// elapsed. The loop then decreases the countdown each time and
// updates the countdown value. Once the countdown is less than 0 the
// program reset the servo possition and counter.
// Along side this it also prints the time left (countdown).
 #include <Servo.h> // Inlcudes library

#define SERVO_PIN        2            // Pin for the servo
#define COUNTDOWN_START  60           // This is the countdown value in seconds
#define ONE_SEC_MS       1000         // This is the number of milliseconds in one second

// These are volatile since thety are updated inside of the interupt
// service routine
volatile unsigned long msCounter = 0;  // increments each milisecond to track time
// this is set to false and becomes true to signal the main loop
// to update the countdown
volatile bool updateFlag = false;        

int remainingTime = COUNTDOWN_START; // Holds the current countdown value
Servo myServo; // This is the servo object that is being used to send commands to the servo motor

// Set up Timer2 to trigger every 1 ms (CTC mode)
void setupTimer2() {
  cli(); // This function disabls interrupts while configuring Timer2
  // This sets the Timer2 to CTC mode which is Clear Timer on Compare Match
  // Which is used to reset Timer2 when it matches the OCR2A value
  TCCR2A = (1 << WGM21); 
  // This set the compare value as mention above to 249 for a 1ms period
  // This number we got from doing (16,000,000 / 64) / 1000 - 1 = 249
  OCR2A = 249;
  // This enables Timer2 Compare Match which interrupts so that the ISR runs every 1ms
  TIMSK2 |= (1 << OCIE2A);
  // Here we set the Timer2 prescaler to 64 which ensures that the timer
  // Clock runs at 250kHZ which gives us the 1-ms period when using OCR2A = 249
  TCCR2B = (1 << CS22);
  sei(); // Enable the prevoius turned of interrupts
}

// This function utilizes the service interupt routine
ISR(TIMER2_COMPA_vect) {
  msCounter++; // Increments the counter on each milisecond
  if (msCounter >= ONE_SEC_MS) { // if 1000 ms have gone by
    msCounter = 0; // It resets the value
    updateFlag = true; // This sets the flag to true to indicate that the second ha passed
  }
}

void setup() {
  Serial.begin(9600); // Initializes the serial monitor
  myServo.attach(SERVO_PIN); /// Attached the servo the the previously defined pin
  // Initialize servo to the starting position (0° corresponds to full time left)
  myServo.write(0);
  setupTimer2(); // COnfigures Timer2 to start generating the 1-ms interupts
}

void loop() {
  // Check if 1 second has elapsed
  if (updateFlag) {
    updateFlag = false; // Clears the flag
    remainingTime--;  // Decrement the countdown by one second
    if (remainingTime < 0) { // If the countdown is below 0 (finished)
      remainingTime = COUNTDOWN_START;  // Reset when countdown reaches below zero
    }
    
    // Map the remaining time (60 to 0 seconds) to servo angle (0° to 180°)
    int servoAngle = map(remainingTime, COUNTDOWN_START, 0, 0, 180);
    myServo.write(servoAngle); // Updatees servo positions
    
    // Print remaining seconds for feedback
    Serial.print("Time left: "); // Prints
    Serial.print(remainingTime); // Prints the remaining time of the countdown
    Serial.println(" s"); // Prints
  }
}
