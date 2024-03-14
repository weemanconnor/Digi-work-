#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
OpenLog sdCard; // create instance 
const String Bottle_rocket_reading = "SD.sensor_reading_storage";

void setup() {
 Wire.begin();
 sdCard.begin(); //Open connection to OpenLog (no pun intended)
 Serial.begin(9600); //9600bps is used for debug statements

sdCard.append(Bottle_rocket_reading);
sdCard.println("Knock Knock joke");
sdCard.syncFile(); 
}

void loop(){
sdCard.println("Knock Knock");
Serial.println("Knock Knock");

sdCard.println("who's there?");
Serial.println("who's there?");

sdCard.println("Jaydens hairline");
Serial.println("Jaydens hairline");

sdCard.println("Jaydens hairline who");
Serial.println("Jaydens hairline who");

sdCard.println("Jaydens hairline's the same distance from me to you");
sdCard.println("Jaydens hairline's the same distance from me to you");

sdCard.syncFile();

}
