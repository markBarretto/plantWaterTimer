void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void lightOn() {
  return digitalWrite(LED_BUILTIN, HIGH);
}

void lightOff() {
  return digitalWrite(LED_BUILTIN, LOW);
}

void toggleMister() {
  //do something
}

void checkAtInterval(int timeInterval, void (&callMethod)(void), boolean recurring) {
  int timeSet = millis() + timeInterval;

 printf('test');
  while(true) {
    if(timeSet == millis()) {
      if(recurring) {
        checkAtInterval(timeInterval, callMethod, true);
      }
      callMethod();
      break;
    }  
  }
}

// the loop function runs over and over again forever
void loop() {
  lightOn();
  checkAtInterval(0, lightOff, false);
}
