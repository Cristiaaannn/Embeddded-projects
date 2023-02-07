// variable to hold sensor value
int sensorValue;

// variable to calibrate low value
int sensorLow = 1023;

// variable to calibrate high value
int sensorHigh = 0;

// Piezo pin
const int piezoPin = 8;

// Photo resistor pin
const int photoResistorPin = A0;

void setup() {
  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }
}

void loop() {
  //read the input from photoResistorPin and store it in a variable
  sensorValue = analogRead(photoResistorPin);

  // map the sensor values to a wide range of pitches
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  // play the tone for 20 ms on piezoPin
  tone(piezoPin, pitch, 20);

  // wait for a moment
  delay(10);
}
