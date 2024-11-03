void handler_screen_messages() {
  // Switch display every 10 seconds
  if (currentMillis - lastDisplayChange >= 8000) {
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
}
