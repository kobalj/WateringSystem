/*
 * Copyright (c) 2020 Jure Kobal.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef WaterLevelSensor_h
#define WaterLevelSensor_h

#include "Arduino.h"

class WaterLevelSensor {
  public:
  /*
   * Class takes two input parameters.
   * slPin - input pin for detecting of low level of water in the tank
   * shPin - input pin for detecting of high level of water in the tank
   * lPin - output pin for low level status LED
   */
    WaterLevelSensor(byte slPin, byte shPin, byte lPin);
    bool containsWater();
  private:
    byte ledPin;
    byte sensorLowPin;
    byte sensorHighPin;
};

#endif
