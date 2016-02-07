#include "fabo-pcal6408.h"
#include "Wire.h"

FaBoGPIO faboGPIO;
int i = 0;

void setup() {
  faboGPIO.configuration();
  Serial.begin(9600);
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
