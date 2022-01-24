# -*- coding: utf-8 -*
'''!
  @file DFRobot_MPX5700.py
  @brief Run the Raspberry Pi library of the air pressure sensor
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author      PengKaixing(kaixing.peng@dfrobot.com)
  @version     V1.0.0
  @date        2021-05-14
  @url         https://github.com/dfrobot/DFRobot_MPX5700
'''

import time
import smbus
import spidev
import os
import RPi.GPIO as GPIO
import math
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
I2C_MODE   = 1

class DFRobot_MPX5700(object):
  '''!
    @brief Basic class of the air pressure sensor
  '''
  def __init__(self ,bus):
    if bus != 0:
      self.i2cbus = smbus.SMBus(bus)

  def set_mean_sample_size(self, size):
    '''!
      @brief Set sample size, i.e take the mean value based on how many raw data
      @param size Sample size
    '''
    buf = [0]*1
    buf[0] = size
    self.write_reg(0x05, buf)
    time.sleep(0.5)

  def get_pressure_value_kpa(self,ifcalibration):
    '''
      @brief Get the current air pressure
      @param ifcalibration Whether to output calibrated air pressure value
      @return float type
    '''
    sbuf = [0]*1
    sbuf[0] = ifcalibration
    self.write_reg(0x09,sbuf)
    time.sleep(1)
    buf = self.read_reg(0x06,2)
    time.sleep(1)
    Pressure_100 = (buf[0] << 8) | buf[1]
    return (Pressure_100/100.0)

  def calibration_kpa(self,standard_values):
    '''
      @brief Set standard air pressure
      @param standard_values The air pressure reference value for calibration
    '''
    Pressure = [0]*2
    ifcalibration = [0]*1
    ifcalibration[0]=1
    plus_or_minus_calibration = [0]*1
    values = self.get_pressure_value_kpa(0)
    if(standard_values>values):
      plus_or_minus_calibration[0] = 0 #Plus calibration
    else:
      plus_or_minus_calibration[0] = 1 #Minus calibration  
    self.write_reg(0x0C, plus_or_minus_calibration)
    time.sleep(1)
    Pressure_100 = (abs(standard_values - values) * 100)
    Pressure[0] = (int(Pressure_100) >> 8) & 0xff
    Pressure[1] = int(Pressure_100) & 0xff
    self.write_reg(0x0A, Pressure)
    time.sleep(1)
    self.write_reg(0x08, ifcalibration)

#brief An example of an i2c interface module
class DFRobot_MPX5700_I2C(DFRobot_MPX5700):
  def __init__(self ,bus ,addr):
    self.__addr = addr
    super(DFRobot_MPX5700_I2C, self).__init__(bus)

  def write_reg(self, reg, data):
    '''
      @brief writes data to a register
      @param reg register address
      @param value written data
    '''
    while 1:
      try:
        self.i2cbus.write_i2c_block_data(self.__addr ,reg ,data)
        return
      except:
        print("please check connect!")
        time.sleep(1)
        return

  def read_reg(self, reg ,len):
    '''
      @brief read the data from the register
      @param reg register address
      @param value read data
    '''
    try:
      rslt = self.i2cbus.read_i2c_block_data(self.__addr ,reg ,len)
    except:
      rslt = -1
    return rslt
