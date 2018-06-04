const int lightPin = 13;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);
}

void switchOn(int pin) {
  return digitalWrite(lightPin, HIGH);
}

void switchOff(int pin) {
  return digitalWrite(lightPin, LOW);
}

void togglePin(int pin) {
  checkAtInterval(1000, switchOn, pin); // turn on after 1 sec
  checkAtInterval(2000, switchOff, pin); // turn off after 2 secs
}

void checkAtInterval(int timeInterval, void (&callMethod)(int), int pin) {
  unsigned long timeSet = millis() + timeInterval;

  while (true) {
    if (timeSet == millis()) {
      callMethod(pin);
      break;
    }
  }
}

// the loop function runs over and over again forever
void loop() {
  togglePin(13);
}
