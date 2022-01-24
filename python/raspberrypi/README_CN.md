# DFRobot_MPX5700
- [English Version](./README.md)

这是一款Arduino兼容的气压传感器模组，测量范围15-700kPa，支持I2C数字输出，可以根据已知气压值进行标定，可以快速、准确的测量管路或其他环境中的气压值。适用于管路气压检测，自然科学实验等场景。

![产品效果图](../../resources/images/SEN0456.png)

## 产品链接（[https://www.dfrobot.com.cn/goods-3416.html](https://www.dfrobot.com.cn/goods-3416.html)）
SKU：SEN0456

## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性y)
* [历史](#历史)
* [创作者](#创作者)

## 概述

这个库提供了一个获取大气压强的例程和一个校准例程

## Installation

要使用这个库，首先将库下载到Raspberry Pi，然后打开例程文件夹。要执行一个例程get_pressure_value.py，请在命令行中输入python get_pressure_value.py。

## 方法

```python

  '''!
    @brief 设置样本量大小，即对多少的原始数据取均值
    @param size 样本量大小
  '''
  def set_mean_sample_size(self, size):

  '''
    @brief 获取此时大气压强
    @param ifcalibration 是否输出经过校准的大气压值
    @return float类型
  '''
  def get_pressure_value_kpa(self,ifcalibration):

  '''
    @brief 设置标准大气压强
    @param standard_values 校准用的大气压强的参考值
  ''' 
  def calibration_kpa(self,standard_values):
       
```


## 兼容性

| 主板         | 通过 | 未通过 | 未测试 | 备注 |
| ------------ | :--: | :----: | :----: | :--: |
| RaspberryPi2 |      |        |   √    |      |
| RaspberryPi3 |      |        |   √    |      |
| RaspberryPi4 |  √   |        |        |      |

* Python 版本

| Python  | 通过 | 未通过 | 未测试 | 备注 |
| ------- | :--: | :----: | :----: | ---- |
| Python2 |  √   |        |        |      |
| Python3 |  √   |        |        |      |
## History

- 2021/5/14 - 1.0.0版本

## Credits

Written by PengKaixing(kaixing.peng@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))