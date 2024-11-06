void handler_day_counter() {
  static unsigned long lastIncrement = 0;

  // Check if 5 minutes (300,000 ms) have passed for EEPROM write
  if (currentMillis - lastElapsedWrite >= 300000) {
    unsigned long elapsedMinutes = (currentMillis - startMillis) / 60000;

    // Write elapsed time to EEPROM with rotating cell address
    EEPROM.put(eepromStartAddress + currentCell * sizeof(unsigned long),
               elapsedMinutes);
    currentCell = (currentCell + 1) % numCells; // Cycle to the next cell

    Serial.print("Stored elapsed time (minutes): ");
    Serial.println(elapsedMinutes);

    lastElapsedWrite = currentMillis; // Update the last write time
  }

  // Check if 24 hours (86,400,000 ms) have passed
  if (currentMillis - lastIncrement >= 86400000) {
    dayCounter++;
    EEPROM.update(0, dayCounter); // Save dayCounter to EEPROM address 0

    // Reset EEPROM cells for concurred time
    for (int i = 0; i < numCells; i++) {
      EEPROM.put(eepromStartAddress + i * sizeof(unsigned long),
                 0UL); // Reset each cell to 0
    }

    Serial.println("Day counter saved and EEPROM reset.");
    lastIncrement = currentMillis;

    // Restart the Arduino board every 24 hours
    wdt_enable(WDTO_2S);
    delay(1000);
    wdt_reset(); // Reset watchdog timer
  }
}
