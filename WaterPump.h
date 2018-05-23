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
#ifndef WaterPump_h
#define WaterPump_h

#include "Arduino.h"

class WaterPump {
  public:
  /*
   * Class with the code to manage the watering pump part of the system. 
   * It is intended to start and stop the water pump when needed. At the
   * time it turns a LED on of off depending on the status of the pump.
   * Class takes two input paramteres. 
   * rPin - output pin to which the relay is connected
   * lPin - output pin to which the status LED is connected
   */
    WaterPump(byte rPin, byte lPin);
    void on();
    void off();
    /*
     * Returns true if watering is already running else false.
     */
    bool isRunning();
  
  private:
    int relayPin;
    int ledPin;
};


#endif
