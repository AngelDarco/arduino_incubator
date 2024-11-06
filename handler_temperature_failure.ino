void handler_temperature_failure() {
  unsigned long errorStart = millis();
  unsigned long relayOnTime = 180000;  // 3 minutes in milliseconds
  unsigned long relayOffTime = 198000; // 3.30 minutes in milliseconds
  bool isRelayOn = false;

  while (true) { // Loop until the sensor works again
    // Attempt to read temperature and humidity
    temperature = (int)dht.readTemperature();
    humidity = (int)dht.readHumidity();

    // Check if readings are valid
    if (!isnan(temperature) && !isnan(humidity) && temperature != 0 &&
        humidity != 0) {
      // If readings are valid, break out of this handler
      Serial.println("Temperature sensor is back online.");
      tempFailCounter = 0; // Reset the failure counter
      return;              // Exit the function and return to the main loop
    }

    // Relay control logic
    if (isRelayOn && millis() - errorStart >= relayOnTime) {
      // Turn off relay after 3 minutes
      digitalWrite(relayPin, HIGH);
      isRelayOn = false;
      errorStart = millis(); // Reset timer
    } else if (!isRelayOn && millis() - errorStart >= relayOffTime) {
      // Turn on relay after 3.30 minutes
      digitalWrite(relayPin, LOW);
      isRelayOn = true;
      errorStart = millis(); // Reset timer
    }

    // Blink error message on display
    handler_errors(0x39); // Show "ErrT"
    delay(500);           // Blink delay
    display.clear();      // Turn off display for blinking effect
    delay(500);           // Blink delay
  }
}
