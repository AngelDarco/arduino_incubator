# Arduino Temperature and Humidity Monitoring System with Error Display

![Arduino Logo](/assets/arduino.png)

This project is a temperature and humidity monitoring system using Arduino, DHT22 sensor, and TM1637 display. It controls a relay based on temperature thresholds and displays real-time temperature, humidity, and day counter values. In case of sensor failure, an error message is shown on the display.

## Components and Connections

1. **Arduino Uno** - Microcontroller
2. **DHT22 Sensor** - Measures temperature and humidity
3. **TM1637 4-Digit Display** - Displays temperature, humidity, and day counter
4. **Relay Module** - Controls external device based on temperature
5. **Wiring Connections**:
   - **DHT22 Sensor**:
     - VCC to Arduino 5V
     - GND to Arduino GND
     - DATA to Arduino digital pin 2
   - **TM1637 Display**:
     - CLK to Arduino digital pin 3
     - DIO to Arduino digital pin 4
   - **Relay Module**:
     - Control signal to Arduino digital pin 8
     - Connect the relay’s load side to the external device as needed.

## Libraries Used

To use this project, install the following Arduino libraries:

1. **DHT Sensor Library** - For DHT22 sensor data reading
   - Install via Arduino Library Manager: `Sketch` > `Include Library` > `Manage Libraries...`, search for `DHT sensor library`.
2. **TM1637Display Library** - Controls the TM1637 4-digit display
   - Install via Arduino Library Manager: `Sketch` > `Include Library` > `Manage Libraries...`, search for `TM1637Display`.
3. **EEPROM Library** - Used for saving and loading persistent data (included by default in Arduino IDE).

## Code Explanation

### Features

- **Real-Time Monitoring**: Reads and displays temperature and humidity from the DHT22 sensor.
- **Relay Control**: Activates relay if temperature falls below or exceeds a threshold.
- **Day Counter**: Shows the number of days the system has been running, stored in EEPROM for persistence.
- **Error Handling**: Displays error messages (`ErrT` for temperature sensor issues) on TM1637 if sensor readings fail.

### Functions and Code Details

#### Setup

```cpp
void setup() {
  Serial.begin(9600);
  dht.begin();
  display.setBrightness(0x0f); // Set display brightness
  pinMode(relayPin, OUTPUT);   // Set relay pin as OUTPUT
  // Load day counter from EEPROM
  dayCounter = EEPROM.read(0);
}
```
