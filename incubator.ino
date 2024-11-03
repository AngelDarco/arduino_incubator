#include <DHT.h>           // Include the DHT library
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
float tempHigh = 39;
float tempLow = 37;

unsigned long lastDisplayChange = 0;
int currentDisplay = 0;
int dayCounter = 0;

// Read temperature in Celsius
float temperature = NAN;
// Read humidity
float humidity = NAN;
unsigned long currentMillis = 0;

// °C for Temperature
const uint8_t DEGREE_C[] = {0x63, 0x39};
// H for Humidity
const uint8_t HUMIDITY_H[] = {0x76};
// D for Day Counter
const uint8_t DAY_D[] = {0x5E};

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

// Temperature failure tries counter
int tempFailCounter = 0;

void handler_temperature_failure(); // Forward declaration
void handler_screen_messages();     // Forward declaration
void handler_day_counter();         // Forward declaration

void setup() {
  Serial.begin(9600);
  dht.begin();
  // Set display brightness
  display.setBrightness(0x0f);
  pinMode(relayPin, OUTPUT);

  // Load the day counter from EEPROM
  dayCounter = EEPROM.read(0); // Assuming we store the counter in address 0

  startMillis = millis();

  // Enable watchdog timer with a 2-second timeout
  wdt_enable(WDTO_2S);
}

void loop() {
  currentMillis = millis(); // Update currentMillis

  // Read temperature in Celsius
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // Check for DHT sensor failures
  if ((isnan(temperature) || isnan(humidity)) && tempFailCounter < 10) {
    Serial.println("Failed to read from DHT sensor!");
    displayError(0x78); // ErrT
    delay(3000);
    tempFailCounter++;
    return; // Early exit to prevent further execution
  }

  // Handle temperature failure if the counter exceeds limit
  if (tempFailCounter >= 10) {
    handler_temperature_failure();
  }

  // Reset tempFailCounter if reading is successful
  tempFailCounter = 0;

  // Control relay based on temperature threshold
  controlRelay(); // Abstract relay control to its own function

  // Update day counter and write to EEPROM
  handler_day_counter();

  // Update screen messages
  handler_screen_messages();

  delay(5000); // Short delay to stabilize display
}

// Show personalized error messages
void displayError(uint8_t errorNumber) {
  // "E", "r", "r", (param...)
  const uint8_t errorMessages[] = {0x79, 0x50, 0x50, errorNumber};
  display.setSegments(errorMessages, 4, 0);
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
