const int lightPin = 13;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(lightPin, OUTPUT);
  Serial.begin(9600);
}

void switchOn() {
  return digitalWrite(lightPin, HIGH);
}

void switchOff() {
  return digitalWrite(lightPin, LOW);
}

void toggleMister() {
  //do something
}

void checkAtInterval(int timeInterval, void (&callMethod)(void)) {
  long timeSet = millis() + timeInterval;

  while(true) {
    if(timeSet == millis()) {
      callMethod();
      break;
    }  
  }
}

// the loop function runs over and over again forever
void loop() {
  checkAtInterval(1000, switchOn); // turn on after 1 sec
  checkAtInterval(2000, switchOff); // turn off after 2 secs
}
