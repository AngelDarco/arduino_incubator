#include <DHT.h>
#include <EEPROM.h> // Include the EEPROM library
#include <TM1637Display.h>

#define DHTPIN 2      // Pin connected to the DHT22 data pin
#define DHTTYPE DHT22 // DHT 22 (AM2302)
DHT dht(DHTPIN, DHTTYPE);

#define CLK 3 // TM1637 display clock pin
#define DIO 4 // TM1637 display data pin
TM1637Display display(CLK, DIO);

int relayPin = 8; // Relay control pin
float tempHigh = 38;
float tempLow = 36;

unsigned long lastDisplayChange = 0;
int currentDisplay = 0;
int dayCounter = 1;

const uint8_t DEGREE_C[] = {0x63, 0x39}; // °C for Temperature
const uint8_t HUMIDITY_H[] = {0x76};     // H for Humidity
const uint8_t DAY_D[] = {0x5E};          // D for Day Counter

void setup() {
  Serial.begin(9600);
  dht.begin();
  display.setBrightness(0x0f); // Set display brightness
  pinMode(relayPin, OUTPUT);

  // Load the day counter from EEPROM
  dayCounter = EEPROM.read(0); // Assuming we store the counter in address 0
}

void loop() {
  float temperature = dht.readTemperature(); // Read temperature in Celsius
  float humidity = dht.readHumidity();       // Read humidity

  // Check if readings failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    displayError(0x78); // ErrT
    return;
  }

  // Switch display every 20 seconds
  unsigned long currentMillis = millis();
  if (currentMillis - lastDisplayChange >= 20000) {
    currentDisplay =
        (currentDisplay + 1) % 4; // Cycle through 3 displays + 1 for temp hold
    lastDisplayChange = currentMillis;
  }

  // Show the appropriate display based on the value of currentDisplay
  switch (currentDisplay) {
  case 0: // Display temperature as "25°C"
    display.showNumberDec((int)temperature, false, 2,
                          0);            // Show temp in the first two digits
    display.setSegments(DEGREE_C, 2, 2); // Display "°C" in the last two digits
    break;
  case 1: // Display humidity as "75H"
    display.showNumberDec((int)humidity, false, 2,
                          0); // Show humidity in the first two digits
    display.setSegments(HUMIDITY_H, 1, 3); // Display "H" in the last digit
    break;
  case 2: // Display day count as "01D"
    display.showNumberDec(dayCounter, true, 2,
                          0);         // Show day count in the first two digits
    display.setSegments(DAY_D, 1, 3); // Display "D" in the last digit
    break;
  case 3: // Hold temperature display for 1 minute
    if (currentMillis - lastDisplayChange >= 60000) {
      lastDisplayChange = currentMillis; // Reset timer for next cycle
      currentDisplay = 0;                // Restart cycle
    }
    display.showNumberDec((int)temperature, false, 2,
                          0); // Static "25°C" for 1 minute
    display.setSegments(DEGREE_C, 2, 2);
    break;
  }

  // Control relay based on temperature threshold
  // the reverse check cause, the relay is active-low
  if (temperature > tempHigh) {
    digitalWrite(relayPin, HIGH); // Turn on relay if temp is below threshold
  } else if (temperature < tempLow) {
    digitalWrite(relayPin, LOW); // Turn off relay if temp is above threshold
  }

  // Increment dayCounter every 24 hours
  incrementDayCounter(); // Call function to check and increment day counter

  delay(500); // Short delay to stabilize display
}

// Show presonalized error messages
void displayError(uint8_t errorNumber) {
  const uint8_t errorMessages[] = {0x79, 0x50, 0x50,
                                   errorNumber}; // "E", "r", "r", (param...)
  display.setSegments(errorMessages, 4, 0);
}

// Increment dayCounter every 24 hours
void incrementDayCounter() {
  static unsigned long lastIncrement = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - lastIncrement >= 86400000) { // 24 hours in milliseconds
    dayCounter++;
    EEPROM.update(0, dayCounter); // Save dayCounter to EEPROM address 0
    lastIncrement = currentMillis;
  }
}
