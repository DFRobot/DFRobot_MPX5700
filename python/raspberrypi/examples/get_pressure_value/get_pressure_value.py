# -*- coding:utf-8 -*-
'''!
  @file get_pressure_value.py
  @brief Get air pressure
  @details I2C address select, i2c address is default to be 0x19, A1 and A0 combine into 4 I2C addresses
  @        | A1 | A0 |
  @        | 0  | 0  |    0x16
  @        | 0  | 1  |    0x17
  @        | 1  | 0  |    0x18
  @        | 1  | 1  |    0x19   default i2c address  
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      PengKaixing(kaixing.peng@dfrobot.com)
  @version     V1.0.0
  @date        2021-05-14
  @url         https://github.com/dfrobot/DFRobot_MPX5700
'''
import sys
import os
import time

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.realpath(__file__)))))
from DFRobot_MPX5700 import *
mpx5700 = DFRobot_MPX5700 (0x01 ,0x16) # bus default use I2C1 , iic address is 0x16

def setup():
  mpx5700.set_mean_sample_size(5)
  
def loop():
  press = mpx5700.get_pressure_value_kpa(1)
  print ("Pressure : " + str(press) + " kPA")
  time.sleep(1)  
  
if __name__ == "__main__":
  setup()
  while True:
    loop()
