/**
 * @file  fabo-pcal6408.h
 * @brief fabo libtary of PCAl6408
 * @author Akira Sasaki
 * @date 2,10, 2016
 */

#include "Arduino.h"
#include "Wire.h"

/** SLAVE_ADDRESS Register */
#define PCAL6408_SLAVE_ADDRESS (0x20)

/** Output Register */
#define PCAL6408_OUTPUT_REG 0x01
/** Config Register */
#define PCAL6408_CONFIGURATION_REG 0x03

/** IO0 Output */
#define PCAL6408_IO0_OUTPUT 0b00000000
/** IO0 Input */
#define PCAL6408_IO0_INPUT 0b00000001
/** IO1 Output */
#define PCAL6408_IO1_OUTPUT 0b00000000
/** IO1 Input */
#define PCAL6408_IO1_INPUT 0b00000010
/** IO2 Output */
#define PCAL6408_IO2_OUTPUT 0b00000000
/** IO2 Input */
#define PCAL6408_IO2_INPUT 0b00000100
/** IO3 Output */
#define PCAL6408_IO3_OUTPUT 0b00000000
/** IO3 Input */
#define PCAL6408_IO3_INPUT 0b00001000
/** IO4 Output */
#define PCAL6408_IO4_OUTPUT 0b00000000
/** IO4 Input */
#define PCAL6408_IO4_INPUT 0b00010000
/** IO5 Output */
#define PCAL6408_IO5_OUTPUT 0b00000000
/** IO5 Input */
#define PCAL6408_IO5_INPUT 0b00100000
/** IO6 Output */
#define PCAL6408_IO6_OUTPUT 0b00000000
/** IO6 Input */
#define PCAL6408_IO6_INPUT 0b01000000
/** IO7 Output */
#define PCAL6408_IO7_OUTPUT 0b00000000
/** IO7 Input */
#define PCAL6408_IO7_INPUT 0b10000000

/** IO0 port */
#define PCAL6408_IO0 0b00000001
/** IO1 port */
#define PCAL6408_IO1 0b00000010
/** IO2 port */
#define PCAL6408_IO2 0b00000100
/** IO3 port */
#define PCAL6408_IO3 0b00001000
/** IO4 port */
#define PCAL6408_IO4 0b00010000
/** IO5 port */
#define PCAL6408_IO5 0b00100000
/** IO6 port */
#define PCAL6408_IO6 0b01000000
/** IO7 port */
#define PCAL6408_IO7 0b10000000

/**
 * @class FaBoGPIO
 * @brief pcal6408 Control
 */
class FaBoGPIO
{
public:
  void configuration(void);
  void setDigital(int port, int output);
  void setAllClear();
  void setGPIO(byte output);
private:
  /** Gpio output mode */
  byte gpio_output = 0x00;
  void writeI2c(byte register_addr, byte value);
  void readI2c(byte register_addr, int num, byte *buf);
};
