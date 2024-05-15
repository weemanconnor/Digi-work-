// setting up library's for the code 
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SPI.h>
#include <SD.h>
#include <SparkFun_LPS25HB_Arduino_Library.h> 

//These lines of code create an instance.
LPS25HB Sensor; 
Sd2Card card;
SdVolume volume;
SdFile root;
OpenLog sdCard;  

const byte tempaturesensor = 3;
const byte chipinput = 5;
//TEACHER COMMENTS what about this one?
const String FILENAME = "sensorLogCG.txt";
//setting up the 

void setup() 
{
 Serial.begin(9600);
 Sensor.begin(); 
 sdCard.begin();
 Wire.begin();

 //Serial.println("run Mylog/sdCard append file testing");

 sdCard.append(FILENAME);
 sdCard.syncFile();
 Serial.println("Done!");
 sdCard.println("pressure , tempature");
 sdCard.syncFile();


 //TEACHER COMMENTS what does this chunk of code do? adjust its error message to something you would say
  if (Sensor.isConnected() == false) // if tyhe sensor is not connected desplay this error message in the serial monitor
  {
    Serial.println("Sensor is disconnected plug in and restart.");     
    while (1);
  }
}
void loop()
{
 launch(true); // false= debug/true = launch
}

void launch (bool launch){
 if (launch == true){

  sdCard.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
    sdCard.print(",");  
  sdCard.println(Sensor.getTemperature_degC()); // geting the tempature in degrees 
  sdCard.syncFile();

}else {
 //TEACHER COMMENTS what does this chunk of code do?
  Serial.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
  Serial.print(",");
  Serial.println(Sensor.getTemperature_degC()); // geting the tempature in degrees  
}
}




