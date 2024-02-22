#include <Servo.h>
const byte LEDPIN = 13;
const byte SERVOPIN = 1;
const byte BTNPIN = 2;
const byte MICROPIN = 3;
const byte LEDPINON = 3; 

const byte LOCK = 0;
const byte UNLOCK = 90;
const byte LOUDENOUGH = 512;


Servo latch;


// telling system what components are called and what they are attached to on the circut
void setup() {

  pinMode(LEDPIN, OUTPUT);
  pinMode(BTNPIN, INPUT);
   pinMode(MICROPIN, INPUT);
  latch.attach(SERVOPIN);
    latch.write(90);

    Serial.begin(9600);
  // telling the code that the components connected to these pins are a outpot and not an imput
}

void loop() {
  // if the paw1 is pressed/High then the led on the pet will turn on and change the led value to high
 if (analogRead(MICROPIN) <= LOUDENOUGH) {
  Serial.print("Heard a knock, unlcoking box");
  digitalWrite(LEDPINON, HIGH);
  latch.write(UNLOCK); 
 }

if (digitalRead(BTNPIN) == HIGH) {
  Serial.print("button pressed, locking box");
  latch.write(LOCK); 
}
}