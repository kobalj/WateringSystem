/*
 * Copyright (c) 2018 Jure Kobal.
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
#include "WaterPump.h"

bool running;

WaterPump::WaterPump(byte rPin, byte lPin) {
  relayPin = rPin;
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  
  ledPin = lPin;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  running = false;
}

void WaterPump::on() {
  digitalWrite(relayPin, LOW);
  digitalWrite(ledPin, HIGH);
  running = true;
}
  
void WaterPump::off() {
  digitalWrite(relayPin, HIGH);
  digitalWrite(ledPin, LOW);
  running = false;
}

bool WaterPump::isRunning() {
  return running;
}
