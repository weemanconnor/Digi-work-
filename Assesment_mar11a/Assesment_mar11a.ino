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
const String FILENAME = "SD.sensor_reading_storage_CG";
//setting up the 

void setup() 
{
 Serial.begin(9600);
 Sensor.begin(); 
 sdCard.begin();
 Wire.begin();

 Serial.println("run Mylog/sdCard append file testing");
 sdCard.println("run Mylog/sdCard append file testing");
 sdCard.append(FILENAME);
 sdCard.syncFile();
 Serial.println("Done!");

 //TEACHER COMMENTS what does this chunk of code do? adjust its error message to something you would say
  if (Sensor.isConnected() == false) // if tyhe sensor is not connected desplay this error message in the serial monitor
  {
    Serial.println("Sensor is disconnected plug in and restart.");     
    while (1)
      ;
  }

}
void loop()
{


 //TEACHER COMMENTS what does this chunk of code do?
  Serial.println("current preassure: ");
  Serial.println(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
  sdCard.println(", Current tempature (C degrees): ");
  Serial.println(Sensor.getTemperature_degC()); // geting the tempature in degrees 

 //TEACHER COMMENTS what about these? check if they make a file that looks like the csv example on classroom
    sdCard.println("current preassure: ");
  sdCard.println(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
  sdCard.println(", Current tempature (C degrees): ");
  sdCard.println(Sensor.getTemperature_degC()); // geting the tempature in degrees 

delay(40); // waiting 40 miliseconds so that we can goet a good reading like 16, 14, 11, 9 insted of 16, 16, 16, 16, 14, 14, 14, 14, 14, 14, 
}




