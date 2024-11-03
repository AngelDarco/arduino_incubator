void handler_temperature_failure() {
  unsigned long errorStart = millis();
  unsigned long relayOnTime = 210000;  // 3.5 minutes in milliseconds
  unsigned long relayOffTime = 330000; // 5.5 minutes in milliseconds
  bool isRelayOn = false;

  while (true) { // Loop until the sensor works again
    // Attempt to read temperature and humidity
    temperature = dht.readTemperature();
    humidity = dht.readHumidity();

    // Check if readings are valid
    if (!isnan(temperature) && !isnan(humidity)) {
      // If readings are valid, break out of this handler
      Serial.println("Temperature sensor is back online.");
      tempFailCounter = 0; // Reset the failure counter
      return;              // Exit the function and return to loop
    }

    // Relay control logic
    if (isRelayOn && millis() - errorStart >= relayOnTime) {
      // Turn off relay after 3.5 minutes
      digitalWrite(relayPin, HIGH);
      isRelayOn = false;
      errorStart = millis(); // Reset timer
    } else if (!isRelayOn && millis() - errorStart >= relayOffTime) {
      // Turn on relay after 5.5 minutes
      digitalWrite(relayPin, LOW);
      isRelayOn = true;
      errorStart = millis(); // Reset timer
    }

    // Blink error message on display
    displayError(0x78); // Show "ErrT"
    delay(500);         // Blink delay
    display.clear();    // Turn off display for blinking effect
    delay(500);         // Blink delay
  }
}
