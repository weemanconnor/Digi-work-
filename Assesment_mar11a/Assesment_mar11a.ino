#include <Wire.h>                                    // setting up the wire.h library
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>  // setting up the sparkfun openlog library
#include <SPI.h>                                     // setting up the SPI.h library
#include <SD.h>                                      // setting up the SD.h library
#include <SparkFun_LPS25HB_Arduino_Library.h>        // setting up the LPS25HB library

LPS25HB Sensor;  // this code is creating an instance linking the LPS25HB to the Sensor
OpenLog sdCard;  // this code links the Openlog instance to sdCard
const int DELAYCG = 1000;
const String FILENAME = "sensorLogCG.txt";  // stringing the file name to "sensorLogcg.txt" so if i call FILENAME it will Make the file that name

void setup()  // setup code not in the loop this code runs once
{
  Serial.begin(9600);
  Sensor.begin();
  sdCard.begin();
  Wire.begin();

  //Serial.println("run Mylog/sdCard append file testing");
  byte status = sdCard.getStatus();
  sdCard.append(FILENAME);
  sdCard.syncFile();
  Serial.println("Serial monitor testing check");
  sdCard.println("pressure , tempature");


  //TEACHER COMMENTS what does this chunk of code do? adjust its error message to something you would say
  if (Sensor.isConnected() == false)  // if tyhe sensor is not connected desplay this error message in the serial monitor
  {
    Serial.println("Sensor is disconnected plug in and restart.");
    while (1)
      ;
  } else {
    Serial.println("Sensor has been plugged in printing values.");
  }
  if (status == 0xFF) {
    Serial.println("sdCard is disconnected plug in and restart.");
    while (1)
      ;
  } else {
    Serial.println("sdCard has been plugged in saving values");
  }
}


void loop() {
  launch(false);  // false= debug/true = launch
}

//
void launch(bool launch) {
  if (launch == true) {
    sdCard.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
    sdCard.print(",");
    sdCard.println(Sensor.getTemperature_degC());  // geting the tempature in degrees
    delay(DELAYCG);
    sdCard.syncFile();
  } else {
    //TEACHER COMMENTS what does this chunk of code do?
    Serial.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
    Serial.print(",");
    Serial.println(Sensor.getTemperature_degC());  // geting the tempature in degrees
  }
}