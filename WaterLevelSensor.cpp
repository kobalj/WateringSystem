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
#include "Arduino.h"
#include "WaterLevelSensor.h"

WaterLevelSensor::WaterLevelSensor(byte slPin, byte shPin, byte lPin) {
  sensorLowPin = slPin;
  sensorHighPin = shPin;
  
  pinMode(sensorLowPin, INPUT);
  pinMode(sensorHighPin, INPUT);
  
  ledPin = lPin;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}

bool WaterLevelSensor::containsWater() {
  int valLow = digitalRead(sensorLowPin);
  int valHigh = digitalRead(sensorHighPin);

  if (valLow == 0) {
    digitalWrite(ledPin, HIGH);
    return false; 
  } else if (valLow == 1 || valHigh == 1) {
    digitalWrite(ledPin, LOW);
    return true;  
  } 
}
