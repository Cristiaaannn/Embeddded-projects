// Project name: Gas alarm (Just for learning purposes) 
// Description : The set-up is starting an alarm immediately after one pin receives voltage ( pin 2).
// Normally, the pin 2 is tied up to a gas sensor but in order to be able to present it
// i replaced the sensor with a button. This way, I am able to simulate the situation where gas in present.
// Mentions: The code for it is ... basic but it was my first project in Arduino, it was to learn and I also found a potential usage :)
// Mentions 2: The code should have contained a block where after the alarm was started, with a delay, the set-up is shut off (In order to not provoke an explosion).
// Since I am not really using it and this is was just for presentation, I didn't include it here. (Otherwise I should have reset the arduino every time I was pressing the button and the ports would have gone crazy each time)
// Author: Cristian Mirea ; cristianmirea@icloud.com
// ** Thank you for reading through this line :) . 


int switchState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    noTone(8);
  } else {
    tone(8,1500);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  }
}
