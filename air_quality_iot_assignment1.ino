#define MQ2_PIN A1   // MQ-2 gas sensor is connected to analog pin A1
#define TMP36_PIN A2 // TMP36 temperature sensor is connected to analog pin A2

int buzzer = 5;     // Buzzer for bad air quality warning

void setup() {
  Serial.begin(9600);

  // Setup Buzzer as output
  pinMode(buzzer, OUTPUT);
}

void loop() {
  float mq2_value = analogRead(MQ2_PIN);  // Read MQ-2 sensor value
  float temp_voltage = analogRead(TMP36_PIN); // Read TMP36 sensor voltage
  float temperature = (temp_voltage * 5.0 * 100.0) / 1024.0; // Convert voltage to Celsius

  // Print readings to Serial Monitor
  Serial.print("Gas Level: ");
  Serial.print(mq2_value);
  Serial.print(" | Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");

  // Define air quality threshold based on MQ-2 sensor value
if (mq2_value > 400) {  // Adjusted threshold for poor air quality
    digitalWrite(buzzer, HIGH);  // Turn on the buzzer
    Serial.println("Air Quality: Poor - Take Action!");
} else {
    digitalWrite(buzzer, LOW);  // Turn off the buzzer
    Serial.println("Air Quality: Good");
}

  delay(2000); // Wait for 2 seconds before the next reading
}
