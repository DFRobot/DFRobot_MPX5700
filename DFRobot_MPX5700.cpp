/*!
 * @file  DFRobot_MPX5700.cpp
 * @brief A air pressure sensor with calibration
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      PengKaixing(kaixing.peng@dfrobot.com)
 * @version     V1.0.0
 * @date        2021-05-14
 * @url         https://github.com/dfrobot/DFRobot_MPX5700
 */
#include "DFRobot_MPX5700.h"

DFRobot_MPX5700::DFRobot_MPX5700(TwoWire *pWire, uint8_t addr)
{
  _pWire = pWire;
  this->_I2C_addr = addr;
}

bool DFRobot_MPX5700::begin(void)
{
  _pWire->begin();
  _pWire->beginTransmission(_I2C_addr);
  if (_pWire->endTransmission() == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void DFRobot_MPX5700::setMeanSampleSize(uint8_t size)
{
  writeReg(0x05, &size,1);
}

float DFRobot_MPX5700::getPressureValue_kpa(uint8_t ifcalibration)
{
  uint8_t buf[2];
  float voltage, Pressure;
  writeReg(0x09, &ifcalibration, 1);
  delay(100);
  readReg(0x06, buf,2);
  uint16_t Pressure_100 = ((uint16_t)buf[0] << 8) | (uint16_t)buf[1];
  return (Pressure_100/100.0);
}

void DFRobot_MPX5700::calibration_kpa(float standard_values)
{
  uint8_t Pressure[2];
  uint8_t ifcalibration=1; 
  float values = getPressureValue_kpa(0);
  uint8_t plus_or_minus_calibration;
  if(standard_values>values)
  {
    //Plus calibration
    plus_or_minus_calibration = 0;
  }
  else
  {
    //Minus calibration
    plus_or_minus_calibration = 1; 
  }
  writeReg(0x0C, &plus_or_minus_calibration, 1);
  delay(100);
  uint16_t Pressure_100 = (uint16_t)(abs(standard_values - values) * 100);
  Pressure[0] = (uint8_t)(Pressure_100 >> 8);
  Pressure[1] = (uint8_t)Pressure_100;
  writeReg(0x0A, Pressure, 2);
  delay(100);
  writeReg(0x08, &ifcalibration, 1);
}

void DFRobot_MPX5700::writeReg(uint8_t Reg, void *pData, uint8_t len)
{
  uint8_t *Data = (uint8_t *)pData;
  _pWire->beginTransmission(this->_I2C_addr);
  _pWire->write(Reg);
  for (uint8_t i = 0; i < len; i++)
  {
    _pWire->write(Data[i]);
  }
  _pWire->endTransmission();
}

int16_t DFRobot_MPX5700::readReg(uint8_t Reg, uint8_t *Data, uint8_t len)
{
  int i = 0;
  _pWire->beginTransmission(this->_I2C_addr);
  _pWire->write(Reg);
  if (_pWire->endTransmission() != 0)
  {
    return -1;
  }
  _pWire->requestFrom((uint8_t)this->_I2C_addr, (uint8_t)len);
  while (_pWire->available())
  {
    Data[i++] = _pWire->read();
  }
  return len;
}

