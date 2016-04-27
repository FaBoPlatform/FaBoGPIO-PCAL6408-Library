/**
 @file LED.ino
 @brief This is an Example for the FaBo GPIO I2C Brick.

   http://fabo.io/210.html

   Released under APACHE LICENSE, VERSION 2.0

   http://www.apache.org/licenses/

 @author FaBo<info@fabo.io>
*/

#include <Wire.h>
#include <FaBoGPIO_PCAL6408.h>

FaBoGPIO faboGPIO;
int i = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("RESET");
  Serial.println();

  faboGPIO.configuration();
}

void loop() {
  Serial.println(i);
  if(i == 0){
    faboGPIO.setDigital(PCAL6408_IO0, HIGH);
  } else if (i == 1){
    faboGPIO.setDigital(PCAL6408_IO1, HIGH);
  } else if (i == 2){
    faboGPIO.setDigital(PCAL6408_IO2, HIGH);
  } else if (i == 3){
    faboGPIO.setDigital(PCAL6408_IO3, HIGH);
  } else if (i == 4){
    faboGPIO.setDigital(PCAL6408_IO4, HIGH);
  } else if (i == 5){
    faboGPIO.setDigital(PCAL6408_IO5, HIGH);
  } else if (i == 6){
    faboGPIO.setDigital(PCAL6408_IO6, HIGH);
  } else if (i == 7){
    faboGPIO.setDigital(PCAL6408_IO7, HIGH);
  } 
  i++;

  if(i > 8){
    i = 0;
    faboGPIO.setAllClear();
  }
  delay(1000);
}
