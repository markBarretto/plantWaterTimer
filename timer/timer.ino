const int misterPin = 4;
const int fanPin = 5;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(misterPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  Serial.begin(9600);
}

void switchOn(int pin) {
  return digitalWrite(pin, HIGH);
}

void switchOff(int pin) {
  return digitalWrite(pin, LOW);
}

void togglePin(int pin, int durationOn, int durationOff) {
  checkAtInterval(durationOff, switchOn, pin); // turn on after 1 sec
  checkAtInterval(durationOn, switchOff, pin); // turn off after 2 secs
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
  togglePin(misterPin, 1000, 2000);
  togglePin(fanPin, 2000, 1000);
}
