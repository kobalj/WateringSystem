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
#include "WaterPump.h"
#include "WaterLevelSensor.h"
#include "HumiditySensor.h"

// Init of variables
byte wsSwitch = 8;
bool isMW = false;
bool requireMW;

void setup() {
  pinMode(wsSwitch, INPUT);
}


// Init of classes

/*
 * WaterPump class enables turning water pump on and off. 
 * Pin 7 is relay and pin 6 is status led
*/
WaterPump wp(7, 6);

/*
 * WaterLevelSensor for detecting availability of water 
 * Pin 9 is sensor pin and pin 5 is water level status LED
 */
WaterLevelSensor wls(9, 10, 5);

/*
 * HumiditySensor for detectng humidity level of the soil
 * Not implemented yet.
 */
HumiditySensor hs(0, 0, 0);

void loop() {

  bool water = wls.containsWater();

  // Check if manual watering switch is on
  int val = digitalRead(wsSwitch);
  if (val == 1) {
    requireMW = true;
  } else {
    requireMW = false;
  }

  if (water) {

    /* 
     *  First we check if manual watering is required
     *  If not, we continue with normal procedure, else we start watering
     */
    if (requireMW && !wp.isRunning()) {
      wp.on();
      isMW = true;
    } else if (!requireMW && isMW) {
      wp.off();
      isMW = false;
    } else if (!isMW) {
      /*
       * When there is no manual watering ongoing
       * TODO: This part of code has to be finished when humidity sensor is implemented
       */
      if (hs.isDry() && !wp.isRunning()) {
        wp.on();
      } else if (hs.isHumid() && wp.isRunning()) {
        wp.off();
      }
    }    
  } else {
    // We check if pump is running and turn it off.
    if (wp.isRunning()) {
      wp.off();  
    }
    if (isMW) {
      isMW = false;
    }
    
    // In case there is no water we wait
    delay(60000);  
  }
}
