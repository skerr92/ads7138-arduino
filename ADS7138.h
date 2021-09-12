/*!
 * @file ADS7138.h
 *
 * This is a library for the ADS7138 Analog To Digital Converter
 *
 * Designed specifically to work with the Oak Development Technologies
 * ADS7138 Acorn Analog to Digital Converter
 * ----> urlhere
 *
 * The sensor uses I2C to communicate with additional pins that can be connected
 * to for other operational modes.
 *
 * Writen by Seth Kerr for Oak Development Technologies
 *
 * Please support additional open source libraries and hardware through your
 * purchases from Oak Development Technologies
 *
 * MIT License, can be used, modified, or copied under license terms
 *
 */

#ifndef ADS7138_H
#define ADS7138_H

#include "Arduino.h"

#include <Adafruit_BusIO_Register.h>
#include <Adafruit_I2CDevice.h>
#include <Wire.h>

// I2C Address (permanent, can not be changed

#define ADS7138_ADDRESS (0x10) ///< default I2C Address (fixed)

//===========================================

// Registers

/*!
 * @brief   Information addresses for the AT42QT1070
 */

enum chip_info {
  
};

/*!
 * @brief   register addresses for Keys
 */

enum {
  SYSTEM_STATUS = (0x00)
  GENERAL_CFG = (0x01)
  DATA_CFG = (0x02)
  OSR_CFG = (0x03)
  OPMODE_CFG = (0x04)
  PIN_CFG = (0x05)
  GPIO_CFG = (0x06)
};


/*!
 * @brief ADS7138 Class object
 */
class ADS7138 {
public:
  // Hardware I2C
  ADS7138();

  bool begin(uint8_t i2caddr = ADS7138_ADDRESS);

  uint16_t readRegister16(uint8_t regMSB);
  uint8_t readRegister8(uint8_t reg);
  void writeRegister8(uint8_t reg, uint8_t value);
  void reset();
  void cal();
  uint8_t get_status();
  uint8_t read_channel(uint8_t chan);
  void gpio_config(uint8_t val);

private:
  Adafruit_I2CDevice *i2c_dev = NULL;
};

#endif
