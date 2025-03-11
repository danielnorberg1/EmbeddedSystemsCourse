#define trigPin 8   // Ultrasonic sensor's Trig pin
#define echoPin A5  // Ultrasonic sensor's Echo pin
#define buzzerPin 2 // Passive buzzer pin
#define led1 3      // First LED
#define led2 4      // Second LED
#define led3 5      // Third LED
#define led4 6      // Fourth LED



// Function declarations
// Function to get the duration of the ultrasonic pulse (distance calculation)
long getUltrasonicDuration();
// Function to control the LEDs based on the measured distance
void controlLEDs(long distance);
// Function to control the buzzer's tone based on the measured distance
void controlBuzzer(long distance);

// Setup 
void setup() {
  // Set pin to output (to send the pulse)
  pinMode(trigPin, OUTPUT);
  // Set pin to input (to receive the pulse)
  pinMode(echoPin, INPUT);
  // Set the buzzer to output (to control the sound)
  pinMode(buzzerPin, OUTPUT);
  // Set the LED pins to output (to turn on)
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  Serial.begin(9600);  // For debugging output
}

void loop() {
  // Variable to store duration of the ultrasonic pulse
  long duration;
  // Variable to store calculated distance based on the pulse
  long distance;

  // Get the pulse duration from the ultrasonic sensor
  duration = getUltrasonicDuration();
  
  // Check if the duration is zero
  if (duration == 0) {
    // Outside range
    distance = 30;
  } else {
    // Calculate distance in centimeters
    distance = duration * 0.034 / 2;
  }

  // Debug: Print the measured distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control LEDs and buzzer based on the measured distance
  controlLEDs(distance);
  controlBuzzer(distance);

  delay(200);  // Delay between readings
}

// Function to get the ultrasonic pulse duration
long getUltrasonicDuration() {
  // Set the Trig pin LOW for 2 microseconds to clear the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond HIGH pulse to the Trig pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the pulse duration on the Echo pin (returning the time taken for the pulse to return)
  long duration = pulseIn(echoPin, HIGH, 30000);
  return duration;
}

// Controls the LEDs based on distance 
void controlLEDs(long distance) {
  if (distance >= 25) {
    // If the distance is greater than or equal to 25 cm, turn off all LEDs
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (distance < 25 && distance >= 20) {
    // If the distance is between 15 and 25 cm, turn on LED1 only
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (distance < 20 && distance >= 15) {
    // If the distance is between 5 and 15 cm, turn on LED1 and LED2
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  else if (distance < 15 && distance >= 5) {
    // If the distance is between 0 and 5 cm, turn on LED1, LED2, and LED3
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else {  // distance < 25
    // All four LEDs lit when the object is closer than 5 cm
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
  }
}

// Controls the buzzer tone frequency based on distance.
void controlBuzzer(long distance) {
  // If the distance is less than 25 cm, map the distance to a frequency for the buzzer
  if (distance < 25) {
    // Map the distance to a frequency range (500 Hz to 3000 Hz)
    int freq = map(distance, 5, 25, 3000, 500);
    // Ensure the frequency stays between 500 and 3000 Hz
    freq = constrain(freq, 500, 3000);
    // Play the tone on the buzzer with the calculated frequency
    tone(buzzerPin, freq);
  } else {
    // Turn off the buzzer if the distance is greater than 25 cm
    noTone(buzzerPin);
  }
}