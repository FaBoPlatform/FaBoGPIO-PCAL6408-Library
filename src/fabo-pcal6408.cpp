#include "fabo-pcal6408.h"

void FaBoGPIO::configuration()
{

    byte conf = PCAL6408_IO0_OUTPUT;
    conf |= PCAL6408_IO1_OUTPUT;
    conf |= PCAL6408_IO2_OUTPUT;
    conf |= PCAL6408_IO3_OUTPUT;
    conf |= PCAL6408_IO4_OUTPUT;
    conf |= PCAL6408_IO5_OUTPUT;
    conf |= PCAL6408_IO6_OUTPUT;
    conf |= PCAL6408_IO7_OUTPUT;

    writeI2c(PCAL6408_CONFIGURATION_REG, conf);
}

void FaBoGPIO::setDigital(int port, int output)
{

  if (output == HIGH) {
    gpio_output |= port;
  } else if (output == LOW){
    gpio_output &= ~port;
  }
  writeI2c(PCAL6408_OUTPUT_REG, gpio_output);

}

void FaBoGPIO::setGPIO(byte output){
  writeI2c(PCAL6408_OUTPUT_REG, output);
}

void FaBoGPIO::setAllClear()
{
  writeI2c(PCAL6408_OUTPUT_REG, 0x00);
  gpio_output = 0x00;
}

// I2Cへの書き込み
void FaBoGPIO::writeI2c(byte register_addr, byte value) {
  Wire.begin();       // I2Cの開始
  Wire.beginTransmission(PCAL6408_SLAVE_ADDRESS);  
  Wire.write(register_addr);         
  Wire.write(value);                 
  Wire.endTransmission();        
}

// I2Cへの読み込み
void FaBoGPIO::readI2c(byte register_addr, int num, byte buffer[]) {
  Wire.begin();       // I2Cの開始
  Wire.beginTransmission(PCAL6408_SLAVE_ADDRESS); 
  Wire.write(register_addr);           
  Wire.endTransmission();         

  Wire.beginTransmission(PCAL6408_SLAVE_ADDRESS); 
  Wire.requestFrom(PCAL6408_SLAVE_ADDRESS, num);   

  int i = 0;
  while(Wire.available())        
  { 
    buffer[i] = Wire.read();   
    i++;
  }
  Wire.endTransmission();         
}

