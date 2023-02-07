const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int led = 2;
long interval = 200;

void setup() {
  // Open up a serial port.
  Serial.begin(19200);
  // Declare switchpin as an input.
  pinMode(switchPin, INPUT);
}

void loop() {
  // Make pin 2-7 output pins.
  for(int i = 2;i<8;i++){
    pinMode(i, OUTPUT);
  // Make variable currentTime and make it use the millis-function.
  unsigned long currentTime = millis();
  if(digitalRead(switchPin) == 1){
  // Print out the status of the Tilt switch in the monitor, for troubleshooting.
  Serial.print("Tilt switch : \t");
  Serial.println(digitalRead(switchPin));
  Serial.print("LED: \t \t");
  Serial.println(led);
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led, HIGH);
    led++;
    if(led > 7){
      led = 7;
    }
    if(led < 2) {
      led = 1;
    }
  }
  }
  else {
      // Print out the status of the Tilt switch and value of LED, for troubleshooting
  Serial.print("Tilt switch : \t");
  Serial.println(digitalRead(switchPin));
  Serial.print("LED: \t \t");
  Serial.println(led);
  if(currentTime - previousTime > interval){
    previousTime = currentTime;
    digitalWrite(led, LOW);
    led--;
    if(led > 7){
      led = 8;
    }
    if(led < 2) {
      led = 1;
  }

  }
}
}
}