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
#include "HumiditySensor.h"

HumiditySensor::HumiditySensor(byte sPin, byte vPin, byte lPin) {
  sensorPin = sPin;
  vccPin = vPin;
  pinMode(vccPin, OUTPUT);
  digitalWrite(vccPin, LOW);
  ledPin = lPin;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
}


bool HumiditySensor::isDry() {
  
  
  return false;
}

bool HumiditySensor::isHumid() {
  return true;  
}

int HumiditySensor::readValue() {
  digitalWrite(vccPin, HIGH);
  delay(1000);
  int value = analogRead(sensorPin);
  digitalWrite(vccPin, LOW);
  return value;
}
