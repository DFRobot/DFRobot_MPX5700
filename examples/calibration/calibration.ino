/**
 * @file  calibration.ino
 * @brief Air pressure calibration
 * @details  i2c address select, i2c address is default to be 0x19, A1 and A0 combine into 4 I2C addresses
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
#define I2C_ADDRESS    0x19
DFRobot_MPX5700 mpx5700(&Wire, I2C_ADDRESS);

void setup() {
  Serial.begin(115200);
  while(false==mpx5700.begin())
  {
    Serial.println("i2c begin fail,please chack connect!");
    delay(1000);
  }
  Serial.println("i2c begin success");

  //Add the standard air pressure value in the current environment for calibration. 
  mpx5700.calibration_kpa(101.3);
}

void loop(){

}
