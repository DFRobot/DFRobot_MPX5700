
/*!
 * @file  DFRobot_MPX5700.h
 * @brief A air pressure sensor with calibration
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version     V1.0.0
 * @date        2021-05-14
 * @url         https://github.com/dfrobot/DFRobot_MPX5700
 */
#ifndef __DFRobot_GAS_H__
#define __DFRobot_GAS_H__
#include "Arduino.h"
#include <Wire.h>

// Open this macro to see the program running in detail
#define ENABLE_DBG

#ifdef ENABLE_DBG
#define DBG(...)                     \
    {                                \
        Serial.print("[");           \
        Serial.print(__FUNCTION__);  \
        Serial.print("(): ");        \
        Serial.print(__LINE__);      \
        Serial.print(" ] ");         \
        Serial.println(__VA_ARGS__); \
    }
#else
#define DBG(...)
#endif
class DFRobot_MPX5700
{
  public:
    DFRobot_MPX5700(TwoWire *pWire = &Wire, uint8_t addr = 0x19);

    /**
     * @fn begin
     * @brief Init function
     * @return bool type, indicate return init status
     * @retval TRUE Init succeed
     * @retval FALSE Init failed
     */
    bool begin(void);

    /**
     * @fn setMeanSampleSize
     * @brief Set sample size, i.e take the mean value based on how many raw data
     * @param size Sample size
     */
    void setMeanSampleSize(uint8_t size);

    /**
     * @fn getPressureValue_kpa
     * @brief Get the current air pressure
     * @param ifcalibration Whether to output calibrated air pressure value
     * @return float类型
     */
    float getPressureValue_kpa(uint8_t ifcalibration);

    /**
     * @fn calibration_kpa(float standard_values)
     * @brief Set standard air pressure
     * @param standard_values The air pressure reference value for calibration
     */
    void calibration_kpa(float standard_values);

  protected:
    /**
     * @fn writeReg
     * @brief Write data to the device
     * @param Reg  Register address to be written
     * @param Data Data to be written to register
     * @param len  Length of data to be written
     */
    void writeReg(uint8_t Reg, void *Data, uint8_t len);
    
    /**
     * @fn readReg
     * @brief Read data from the device
     * @param Reg  Register address to be read
     * @param Data The register data to be read
     * @param len  Length of the data to be written
     * @return int16_t type
     */
    int16_t readReg(uint8_t Reg, uint8_t *Data, uint8_t len);
  private:
    TwoWire *_pWire;
    uint8_t _I2C_addr;
};
#endif
