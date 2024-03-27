#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SPI.h>
#include <SD.h>
#include <SparkFun_LPS25HB_Arduino_Library.h> // Click here to get the library: http://librarymanager/All#SparkFun_LPS25HB

LPS25HB sensor;
Sd2Card card;
SdVolume volume;
SdFile root;


OpenLog sdCard; // create instance 
const String Bottle_rocket_reading = "SD.sensor_reading_storage";
void setup() {
 Serial.begin(9600);
 
  Serial.println("LPS25HB Sensor Example 1 - Basic Readings");
  Serial.println();

  Wire.begin();
sensor.begin(); // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings

  if (sensor.isConnected() == false) // The library supports some different error codes such as "DISCONNECTED"
  {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");     // Alert the user that the device cannot be reached
    Serial.println("Are you using the right Wire port and I2C address?");      // Suggest possible fixes
    Serial.println("See Example2_I2C_Configuration for how to change these."); // Suggest possible fixes
    Serial.println("");
    while (1)
      ;
  }

}

void loop()
{
  Serial.print("current preassure: ");
  Serial.print(sensor.getPressure_hPa());  // getting the tempature reading in hPa
  sdCard.print(", Current tempature (C degrees): ");
  Serial.println(sensor.getTemperature_degC()); // geting the tempature in degrees 

    sdCard.print("current preassure: ");
  sdCard.print(sensor.getPressure_hPa());  // getting the tempature reading in hPa
  sdCard.print(", Current tempature (C degrees): ");
  sdCard.println(sensor.getTemperature_degC()); // geting the tempature in degrees 

delay(40); // waiting 40 miliseconds so that we can goet a good reading like 16, 14, 11, 9 insted of 16, 16, 16, 16, 14, 14, 14, 14, 14, 14, 
}




