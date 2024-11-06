#include <DHT.h> // Include the DHT library
#include <DHT_U.h>
#include <EEPROM.h>        // Include the EEPROM library
#include <TM1637Display.h> // Include the TM1637 library
#include <avr/wdt.h>       // Include the Watchdog timer library <avr/wdt.h>

#define DHTPIN 2      // Pin connected to the DHT22 data pin
#define DHTTYPE DHT22 // DHT 22 (AM2302)
DHT dht(DHTPIN, DHTTYPE);

#define CLK 3 // TM1637 display clock pin
#define DIO 4 // TM1637 display data pin
TM1637Display display(CLK, DIO);

int relayPin = 8; // Relay control pin
float tempHigh = 38;
float tempLow = 37;

unsigned long currentMillis = 0;

// Read temperature in Celsius
int temperature = NAN;
// Read humidity
int humidity = NAN;
const int maxTries = 20; // Set this to your desired threshold
// Temperature failure tries counter before enter temperature failure mode
int tempFailCounter = 0;

// Screen messages
unsigned long lastDisplayChange = 0;
int currentDisplay = 0;
int dayCounter = 0;
// °C for Temperature
const uint8_t DEGREE_C[] = {0x63, 0x39};
// H for Humidity
const uint8_t HUMIDITY_H[] = {0x76};
// D for Day Counter
const uint8_t DAY_D[] = {0x5E};

// Write to EEPROM every 5 minutes to store elapsed time
// Tracks last EEPROM write for time
unsigned long lastElapsedWrite = 0;
// Tracks millis since last reset
unsigned long startMillis = 0;
// Start address for time storage
int eepromStartAddress = 10;
// Number of cells to rotate through
int numCells = 10;
// Current EEPROM cell for time storage
int currentCell = 0;

// Declare handler functions
void handler_temperature_failure();       // Forward declaration
void handler_screen_messages();           // Forward declaration
void handler_day_counter();               // Forward declaration
void handler_errors(uint8_t errorNumber); // Forward declaration

void setup() {
  Serial.begin(9600);
  dht.begin();
  // Set display brightness
  display.setBrightness(0x0f);
  pinMode(relayPin, OUTPUT);

  // Load the day counter from EEPROM
  dayCounter = EEPROM.read(0); // Assuming we store the counter in address 0

  startMillis = millis();
}

void loop() {
  currentMillis = millis(); // Update currentMillis

  // Read temperature in Celsius
  temperature = (int)dht.readTemperature();
  humidity = (int)dht.readHumidity();

  // Check for DHT sensor failures
  if ((isnan(temperature) || isnan(humidity) || temperature == 0 ||
       humidity == 0) &&
      tempFailCounter < maxTries) {
    Serial.println("Failed to read from DHT sensor, retrying...");
    handler_errors(0x63); // ErrT
    delay(3000);
    tempFailCounter++;
    return; // Early exit to prevent further execution
  }

  // If the unchanged count exceeds the threshold, trigger the failure handler
  if (tempFailCounter >= maxTries) {
    Serial.println("Temperature sensor failure!");
    handler_errors(0x39);
    delay(3000);
    Serial.println("Entering temperature failure handler...");
    handler_temperature_failure();
    return;
  }

  // Reset tempFailCounter if reading is successful and values have changed
  tempFailCounter = 0;

  // Control relay based on temperature threshold
  controlRelay(); // Abstract relay control to its own function

  // Update day counter and write to EEPROM
  handler_day_counter();

  // Update screen messages
  handler_screen_messages();

  delay(5000); // Short delay to stabilize display
}

// Control relay based on temperature thresholds
void controlRelay() {
  // The relay is active-low
  if (temperature > tempHigh) {
    digitalWrite(relayPin, HIGH); // Turn on relay if temp is below threshold
  } else if (temperature < tempLow) {
    digitalWrite(relayPin, LOW); // Turn off relay if temp is above threshold
  }
}
