// This system uses Arduino Uno measuring temperature and lighting LEDs via timer interrupts

// Define LED pins (using digital pins; choose colors as desired)
// For example, white (coldest) on pin 7, blue on 6, yellow on 5, orange on 4, red (warmest) on 3.
#define COLDEST 2  
#define COLDER  5   
#define WARM    4   
#define WARMER  3   
#define WARMEST 6   

#define TEMP_SENSOR A0

// ADC and voltage definitions
#define ADC_RESOLUTION 1023.0   // ADC counts range from 0 to 1023
#define MAX_VOLT_MV    5000.0     // 5000 mV reference (5V)

// Timer1 definitions for interrupt timing
#define CLOCK_SPEED      16000000.0  // 16 MHz clock
#define PRESCALER        1024.0      // Using a prescaler of 1024
#define SECONDS_INTERVAL 0.5         // Update every 0.5 seconds (2 Hz)
#define TIMER1_MAX       65535       // Maximum for 16-bit Timer1
#define TIMER1_LOW       257         // Minimum allowed value

// Structure to hold threshold values and associated LED pin.
// The idea is that for each threshold met, the corresponding LED is turned on.
typedef struct {
  float minTemp;  // Minimum temperature (°C) for this LED to turn on
  int   pin;      // LED output pin
} Threshold;

// Define thresholds for cumulative LED display:
// For example, if temp >= 0°C, LED on pin COLDEST lights; if temp >= 11°C, LED on COLDER lights, etc.
Threshold thresholds[] = {
  {  0.0, COLDEST },
  { 11.0, COLDER  },
  { 21.0, WARM    },
  { 31.0, WARMER  },
  { 41.0, WARMEST }
};

// getmV() reads an analog pin and returns the corresponding millivolt value.
// This function remains unchanged regardless of sensor type.
float getmV(int pin) {
  int ADCCount;
  float mV;
  ADCCount = analogRead(pin);  // Read ADC value (0–1023)
  // Convert ADC count to mV: (ADCCount / ADC_RESOLUTION) * MAX_VOLT_MV
  mV = ((float)ADCCount / ADC_RESOLUTION) * MAX_VOLT_MV;
  return mV;
}

// setup_timer_1() configures Timer1 in CTC mode so that an interrupt occurs every 0.5 seconds.
void setup_timer_1() {
  float CMR;  // Compare Match Register value
  
  cli();  // Disable global interrupts
  
  TCCR1A = 0;   // Clear Timer1 control registers
  TCCR1B = 0;
  TCNT1  = 0;   // Reset Timer1 counter
  
  // Calculate CMR using:
  // CMR = (CLOCK_SPEED / (PRESCALER * desired_frequency)) - 1,
  // where desired_frequency = 1/SECONDS_INTERVAL = 2 Hz.
  CMR = (CLOCK_SPEED / (PRESCALER * (1.0 / SECONDS_INTERVAL))) - 1.0;
  
  // Ensure the calculated CMR is within allowed limits.
  if (CMR >= TIMER1_MAX) {
    CMR = TIMER1_MAX;
    Serial.println("CMR was too high; adjusted to maximum.");
  } else if (CMR <= TIMER1_LOW) {
    CMR = TIMER1_LOW;
    Serial.println("CMR was too low; adjusted to minimum.");
  }
  
  OCR1A = (int)CMR;  // Set the Output Compare Register
  
  // Configure Timer1 in CTC mode (Clear Timer on Compare Match)
  TCCR1B |= (1 << WGM12);
  
  // Set prescaler to 1024 by setting CS12 and CS10 bits in TCCR1B
  TCCR1B |= (1 << CS12) | (1 << CS10);
  
  // Enable Timer1 Compare Match A Interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  sei();  // Enable global interrupts
}

void setup() {
  int i;
  // Initialize LED pins as outputs
  for (i = 0; i < (sizeof(thresholds) / sizeof(Threshold)); i++) {
    pinMode(thresholds[i].pin, OUTPUT);
  }
  
  // Set the temperature sensor pin as input
  pinMode(TEMP_SENSOR, INPUT);
  
  Serial.begin(9600);  // Initialize serial communication for debugging
  
  setup_timer_1();     // Set up Timer1 interrupts
}

void loop() {
  // Main loop remains empty.
  // All periodic temperature measurement and LED updating is handled by the Timer1 ISR.
}

// Timer1 Compare Match A Interrupt Service Routine
// This function is called every time Timer1's counter matches OCR1A (every 0.5 seconds).
ISR(TIMER1_COMPA_vect) {
  int temp;  // Temperature in °C (as integer)
  int i;
  
  // For TMP36, the conversion is:
  // Temperature (°C) = (mV - 500) / 10
  // For example, if the sensor reads 750 mV then (750 - 500)/10 = 25°C.
  temp = (int)((getmV(TEMP_SENSOR) - 500.0) / 10.0);
  
  // Cumulative display: loop through each threshold.
  // For each threshold met, the corresponding LED is turned on.
  // For example, if temp is 25°C, LEDs for thresholds 0°C, 11°C, and 21°C are on.
  for (i = 0; i < (sizeof(thresholds) / sizeof(Threshold)); i++) {
    if (temp >= thresholds[i].minTemp) {
      digitalWrite(thresholds[i].pin, HIGH);
    } else {
      digitalWrite(thresholds[i].pin, LOW);
    }
  }
  
}

