// Show personalized error messages
void handler_errors(uint8_t errorNumber) {
  // "E", "r", "r", (param...)
  const uint8_t errorMessages[] = {0x79, 0x50, 0x50, errorNumber};
  display.setSegments(errorMessages, 4, 0);
}