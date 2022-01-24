/**
 * @file  getPressureValue.ino
 * @brief Get air pressure
 * @details  I2C address select, i2c address is default to be 0x19, A1 and A0 combine into 4 I2C addresses
 * @n        | A1 | A0 |
 * @n        | 0  | 0  |    0x16
 * @n        | 0  | 1  |    0x17
 * @n        | 1  | 0  |    0x18
 * @n        | 1  | 1  |    0x19   default i2c address
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @licence     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version     V1.0.0
 * @date        2021-05-14
 * @url         https://github.com/dfrobot/DFRobot_MPX5700
 */

#include "DFRobot_MPX5700.h"
#define I2C_ADDRESS 0x19
DFRobot_MPX5700 mpx5700(&Wire, I2C_ADDRESS);
void setup()
{
  Serial.begin(115200);
  while (false == mpx5700.begin())
  {
    Serial.println("i2c begin fail,please chack connect!");
    delay(1000);
  }
  Serial.println("i2c begin success");

  //In order to smooth data, set to take the mean value based on xx (quantity) adc data, if not set, the system will automatically get the mean value of 5 samples.
  mpx5700.setMeanSampleSize(/*Sample Total*/5);
}

void loop()
{
  Serial.print("Pressure Value: ");
  //Get the current ambient air pressure, set whether to enable calibration, 1 for calibration required, 0 for no calibration required
  Serial.print(mpx5700.getPressureValue_kpa(1));
  Serial.println(" kpa");
  delay(1000);
}
