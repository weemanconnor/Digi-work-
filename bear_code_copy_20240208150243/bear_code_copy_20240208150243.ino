const byte LEDPIN = 13; 
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;
// telling system what components are called and what they are attached to on the circut 
void setup() { 
  
  pinMode(13, INPUT);
  pinMode(PAWPIN1, OUTPUT);
  pinMode(PAWPIN2, OUTPUT);
  pinMode(PAWPIN3, OUTPUT);
  pinMode(PAWPIN4, OUTPUT);
  // telling the code that the components connected to these pins are a outpot and not an imput 
 }

void loop() {
  // if the paw1 is pressed/High then the led on the pet will turn on and change the led value to high 
  if(digitalRead(PAWPIN1) == HIGH){
   digitalWrite (LEDPIN, HIGH);
 }

{
  // if the paw2 is pressed/High then the led on the pet will turn on and change the led value to high 
  if(digitalRead(PAWPIN2) == HIGH){
   digitalWrite (LEDPIN, HIGH);
 }

{
  // if the paw3 is pressed/High then the led on the pet will turn on and change the led value to high 
  if(digitalRead(PAWPIN3) == HIGH){
   digitalWrite (LEDPIN, HIGH);
   void playMusic ();
 }

{
  // if the paw4 is pressed/High then the led on the pet will turn on and change the led value to high 
  if(digitalRead(PAWPIN4) == HIGH){
   digitalWrite (LEDPIN, HIGH);
   int score = PlayGame();
 }
}

void playMusic(){
}

int playGame(){
  byte score = 99;
  // play simon says game 


return score;
}
}
