#include <AdaFruit_LiquidCrystal.h>
const byte BTNPIN = 1;
const byte POTPIN = A1;
const byte POTPIN = A1;

AdaFruit_LiquidCrystal screen(0);
void setup() {
  pinMode(BTNPIN, INPUT);
  pinMode(POTPIN, INPUT);

  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
if (digitalRead(BTNPIN) == HIGH) {
  Serial.println("Rolling, dice");
  int diceNum = random(1, 6);
  Serial.println(diceNum);

  int diceType = analogRead(POTPIN);
  diceType = map(diceType, 0, 1023, 1, 6);
  
}
}
//HAN COMMENT remember that we have model answer code to finish this code if you find you need it later
