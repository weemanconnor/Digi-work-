#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
OpenLog sdCard; // create instance 
const String Bottle_rocket_reading = "SD.sensor_reading_storage";

void setup() {
 Wire.begin();
 sdCard.begin(); //Open connection to OpenLog (no pun intended)
 Serial.begin(9600); //9600bps is used for debug statements

sdCard.append(Bottle_rocket_reading);
sdCard.println("bottle rocket readings");
sdCard.syncFile(); 
}

void loop() {
  // put your main code here, to run repeatedly:

}
