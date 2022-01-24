# DFRobot_MPX5700
- [中文版](./README_CN.md)

This is a Arduino compatible pressure sensor module with a measuring range of 15-700kPa, which supports I2C digital output and can be calibrated according to known pressure values and allows fast and accurate measurement of pressure values in pipelines or other environments. It is suitable for pipeline air pressure detection, natural science experiments and other scenarios.

![Product Image](./resources/images/SEN0456.png)

## Product Link（[https://www.dfrobot.com/product-2490.html](https://www.dfrobot.com/product-2490.html)）

SKU：SEN0456

## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)

## Summary

The library provides a routine for getting air pressure and one for calibration.

## Installation

To use this library, first download the library file, paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
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
     * @return float type
     */
    float getPressureValue_kpa(uint8_t ifcalibration);

    /**
     * @fn calibration_kpa
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

```
## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno  |      √       |             |            | 
Leonardo  |      √       |             |            | 
Meag2560 |      √       |             |            | 
M0 |      √       |             |            | 
ESP32 |      √       |             |            | 
ESP8266 |      √       |             |            | 

## History

- 2021/5/14 - 1.0.0 version

## Credits

Written by Pengkaixing(kaixing.peng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))
