/**
 * @file  fabo-pcal6408.cpp
 * @brief fabo libtary of PCAl6408
 * @author Akira Sasaki
 * @date 2,10, 2016
 */
#include "fabo-pcal6408.h"

/**
 * @brief set config
 */
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

/**
 * @brief Set Digital Data
 * @param [in] port   : set IO port
 * @param [in] output : set value
 */
void FaBoGPIO::setDigital(int port, int output)
{

  if (output == HIGH) {
    gpio_output |= port;
  } else if (output == LOW){
    gpio_output &= ~port;
  }
  writeI2c(PCAL6408_OUTPUT_REG, gpio_output);

}

/**
 * @brief Clear All Port
 */
void FaBoGPIO::setAllClear()
{
  writeI2c(PCAL6408_OUTPUT_REG, 0x00);
  gpio_output = 0x00;
}

/**
 * @brief Set GPIO
 * @param [in] output : set value
 */
void FaBoGPIO::setGPIO(byte output){
  writeI2c(PCAL6408_OUTPUT_REG, output);
}

/**
 * @brief Write I2C Data
 * @param [in] address : Write Register Address
 * @param [in] data    : Write Data
 */
void FaBoGPIO::writeI2c(byte register_addr, byte value) {
  Wire.begin();
  Wire.beginTransmission(PCAL6408_SLAVE_ADDRESS);
  Wire.write(register_addr);
  Wire.write(value);
  Wire.endTransmission();
}

/**
 * @brief Read I2C Data
 * @param [in] register_addr : register address
 * @param [in] num       : Data Length
 * @param [out] buffer[] : Read Data
 */
void FaBoGPIO::readI2c(byte register_addr, int num, byte buffer[]) {
  Wire.begin();
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
