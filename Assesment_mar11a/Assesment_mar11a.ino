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
  Serial.begin(9600);// 
  Sensor.begin();// initialising the 1-wire data bus 
  sdCard.begin();// begin the log to store the data 
  Wire.begin();// initilising the wire so that we can  use I2C

  byte status = sdCard.getStatus(); // getting the status of the sdCard to later use to find if its plugged in or not 
  sdCard.append(FILENAME); // grabing the file name from the string sensorLogCG.TXT
  sdCard.syncFile(); // sync everything so far to the sd card 
  Serial.println("Serial monitor testing check"); // print to the serial monitor to test if its working 
  sdCard.println("pressure , tempature"); // print to the sdCard to set up the titles for CSV


  if (Sensor.isConnected() == false)  // if the sensor is not connected desplay this error message in the serial monitor
  {
    Serial.println("Sensor is disconnected plug in and restart."); //print to the serial monitor stating that the sensor is disconnected 
    while (1)
      ;
  } else {
    Serial.println("Sensor has been plugged in printing values."); // if the sensor is connected print snesor plugged in printing values 
  }
  if (status == 0xFF) { // grabing the status and if its this value print the sdCard is disconnected
    Serial.println("sdCard is disconnected plug in and restart.");
    while (1)
      ;
  } else {
    Serial.println("sdCard has been plugged in saving values"); // if the sdCard gets plugged in print been plugged in saving values
  }
}


void loop() {
  launch(false);  // false= debug/true = launch
}

//
void launch(bool launch) {
  if (launch == true) {// if the launch value is set to true then run the sensor readings to the sdCard 
    sdCard.print(Sensor.getPressure_hPa());  // getting the tempature reading in hPa
    sdCard.print(","); //print the , to make sure they are in CSV format 
    sdCard.println(Sensor.getTemperature_degC());  // geting the tempature in degrees
    delay(DELAYCG);// grabing the set delay from the string 
    sdCard.syncFile();// sync the data to the sdCard 
  } else {
    Serial.print(Sensor.getPressure_hPa());  // if the launch value is false then print the sensor values to the serial monitor 
    Serial.print(",");// print the , to make sure its in CSV format 
    Serial.println(Sensor.getTemperature_degC());  // geting the tempature in degrees
  }
}