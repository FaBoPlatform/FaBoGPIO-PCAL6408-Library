/**
 @file FaBoGPIO_PCAL6408.h
 @brief This is a library for the FaBo GPIO I2C Brick.

   http://fabo.io/210.html

   Released under APACHE LICENSE, VERSION 2.0

   http://www.apache.org/licenses/

 @author FaBo<info@fabo.io>
*/

#ifndef FABOGPIO_PCAL6408_H
#define FABOGPIO_PCAL6408_H

#include <Arduino.h>
#include <Wire.h>

#define PCAL6408_SLAVE_ADDRESS 0x20 ///< Default I2C Slave Address

/// @name Register Addresses
/// @{
#define PCAL6408_OUTPUT_REG 0x01
#define PCAL6408_CONFIGURATION_REG 0x03
/// @}

/// @name OUTPUT Parameter
/// @{
#define PCAL6408_IO0_OUTPUT 0b00000000
#define PCAL6408_IO0_INPUT  0b00000001
#define PCAL6408_IO1_OUTPUT 0b00000000
#define PCAL6408_IO1_INPUT  0b00000010
#define PCAL6408_IO2_OUTPUT 0b00000000
#define PCAL6408_IO2_INPUT  0b00000100
#define PCAL6408_IO3_OUTPUT 0b00000000
#define PCAL6408_IO3_INPUT  0b00001000
#define PCAL6408_IO4_OUTPUT 0b00000000
#define PCAL6408_IO4_INPUT  0b00010000
#define PCAL6408_IO5_OUTPUT 0b00000000
#define PCAL6408_IO5_INPUT  0b00100000
#define PCAL6408_IO6_OUTPUT 0b00000000
#define PCAL6408_IO6_INPUT  0b01000000
#define PCAL6408_IO7_OUTPUT 0b00000000
#define PCAL6408_IO7_INPUT  0b10000000
#define PCAL6408_IO0 0b00000001
#define PCAL6408_IO1 0b00000010
#define PCAL6408_IO2 0b00000100
#define PCAL6408_IO3 0b00001000
#define PCAL6408_IO4 0b00010000
#define PCAL6408_IO5 0b00100000
#define PCAL6408_IO6 0b01000000
#define PCAL6408_IO7 0b10000000
/// @}

/**
 @class FaBoGPIO
 @brief FaBo GPIO I2C Controll class
*/
class FaBoGPIO {
  public:
    FaBoGPIO(uint8_t addr = PCAL6408_SLAVE_ADDRESS);
    void configuration(void);
    void setDigital(uint8_t port, uint8_t output);
    void setAllClear();
    void setGPIO(uint8_t output);
  private:
    uint8_t _i2caddr;
    uint8_t _output;
    void writeI2c(uint8_t address, uint8_t data);
};

#endif // FABOGPIO_PCAL6408_H
