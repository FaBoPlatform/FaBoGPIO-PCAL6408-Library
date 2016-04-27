/**
 @file FaBoGPIO_PCAL6408.cpp
 @brief This is a library for the FaBo GPIO I2C Brick.

   http://fabo.io/210.html

   Released under APACHE LICENSE, VERSION 2.0

   http://www.apache.org/licenses/

 @author FaBo<info@fabo.io>
*/

#include "FaBoGPIO_PCAL6408.h"

/**
 @brief Constructor
*/
FaBoGPIO::FaBoGPIO(uint8_t addr) {
  _i2caddr = addr;
  _output = 0x00;
  Wire.begin();
}

/**
 @brief Configure Device
*/
void FaBoGPIO::configuration() {
  uint8_t conf = PCAL6408_IO0_OUTPUT;
  conf |= PCAL6408_IO1_OUTPUT;
  conf |= PCAL6408_IO2_OUTPUT;
  conf |= PCAL6408_IO3_OUTPUT;
  conf |= PCAL6408_IO4_OUTPUT;
  conf |= PCAL6408_IO5_OUTPUT;
  conf |= PCAL6408_IO6_OUTPUT;
  conf |= PCAL6408_IO7_OUTPUT;
  writeI2c(PCAL6408_CONFIGURATION_REG, conf);
}

/**
 @brief set Port to Digital
 @param [in] port Port
 @param [in] output output
*/
void FaBoGPIO::setDigital(uint8_t port, uint8_t output) {
  if (output == HIGH) {
    _output |= port;
  } else if (output == LOW){
    _output &= ~port;
  }
  writeI2c(PCAL6408_OUTPUT_REG, _output);
}

/**
 @brief All Port to LOW
*/
void FaBoGPIO::setAllClear() {
  writeI2c(PCAL6408_OUTPUT_REG, 0x00);
  _output = 0x00;
}

/**
 @brief set Port to GPIO
 @param [in] output output
*/
void FaBoGPIO::setGPIO(uint8_t output){
  writeI2c(PCAL6408_OUTPUT_REG, output);
}

/**
 @brief Write I2C
 @param [in] address register address
 @param [in] data write data
*/
void FaBoGPIO::writeI2c(uint8_t address, uint8_t data) {
  Wire.beginTransmission(_i2caddr);
  Wire.write(address);
  Wire.write(data);
  Wire.endTransmission();
}

