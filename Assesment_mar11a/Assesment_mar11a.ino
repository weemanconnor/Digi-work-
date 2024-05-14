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

 launch(false); // false= debug/true = launch
 delay(5000);
}

void launch (bool launch){
 if (launch){

    sdCard.println("current preassure: ");
  sdCard.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
    sdCard.print(",");  
  sdCard.println(Sensor.getTemperature_degC()); // geting the tempature in degrees 
  sdCard.syncFile();
  delay(400); // waiting 40 miliseconds so that we can goet a good reading like 16, 14, 11, 9 insted of 16, 16, 16, 16, 14, 14, 14, 14, 14, 14, 
}

 else {

 //TEACHER COMMENTS what does this chunk of code do?
  Serial.print("current preassure: ");
  Serial.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
  Serial.print(", Current tempature (°C):");
  Serial.print(Sensor.getTemperature_degC()); // geting the tempature in degrees 
}
}




