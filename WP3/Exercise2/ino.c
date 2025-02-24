

const int TEMP_PIN = A4;

// LDR connected to analog pin A0.
const int LDR_PIN   = A5;

// LED pins:
const int GREEN_LED = 13;  // Normal dependency indicator
const int RED_LED   = 12;  // Indicates temperature is too high for given light level
const int BLUE_LED= 11;  // Indicates temperature is too low for given light level

// ----- Periodicity Setting -----
// Set the period (in seconds) for sensor readings (adjust as needed).
unsigned long periodSeconds = 2; // e.g., 2 seconds
unsigned long periodMs = periodSeconds * 1000;

void setup() {
  Serial.begin(9600);
  
  // Set LED pins as outputs.
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  

}

void loop() {
  
     // --- LED Indications ---
  // Turn off all LEDs initially.
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  // --- Read Temperature from TMP36 ---
  // Read the analog value from the TMP36 sensor.
  int tempValue = analogRead(TEMP_PIN);
  // Convert the analog reading (0-1023) to voltage (0-5V)
  float voltage = tempValue * (5.0 / 1023.0);
  // Calculate temperature in Celsius.
  // (TMP36 outputs 0.5V at 0°C and increases 10mV per °C)
  float temperature = (voltage - 0.5) * 100;
  
  // --- Read Light Intensity from LDR ---
  int ldrValue = analogRead(LDR_PIN);
  // Convert the analog value to a percentage (0% to 100%).
  // (0 maps to 0%, 310 maps to 100%)
  int lightIntensity = map(ldrValue, 0, 310, 0, 100);

  // Display sensor readings.
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" deg C, Light Intensity: ");
  Serial.print(lightIntensity);
  Serial.println(" %");

  // --- Determine Expected Light Intensity Range ---
  int lowerBound = 0;
  int upperBound = 0;
  
  if (temperature < -12) {
    lowerBound = upperBound = 0;
  }
  else if (temperature >= -12 && temperature <= 0) {
    lowerBound = 1;
    upperBound = 20;
  }
  else if (temperature > 0 && temperature < 21) {
    lowerBound = 21;
    upperBound = 60;
  }
  else if (temperature >= 21) {
    lowerBound = 61;
    upperBound = 100;
  }
  
  
  // Check if measured light intensity is within the expected range.
  if (lightIntensity >= lowerBound && lightIntensity <= upperBound) {
    // Normal dependency: light intensity is within the expected range.
    digitalWrite(GREEN_LED, HIGH);
    Serial.println("Status: Normal dependency.");
  }
  else if (lightIntensity < lowerBound) {
    // Light intensity is lower than expected.
    // Interpretation: The temperature might be too high for the available light.
    digitalWrite(RED_LED, HIGH);
    Serial.println("Warning: Temperature is too high for the measured light intensity.");
  }
  else if (lightIntensity > upperBound) {
    // Light intensity is higher than expected.
    // Interpretation: The temperature might be too low for the available light.
    digitalWrite(BLUE_LED, HIGH);
    Serial.println("Warning: Temperature is too low for the measured light intensity.");
  }
  
  // Wait for the defined period before the next reading.
  delay(periodMs);
}