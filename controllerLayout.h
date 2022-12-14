/*
  controllerLayout.h - Library to define button inputs for custom contoller layouts and button reading
  Author: Matt Norman

  MIT License

  Copyright (c) 2022 Matt Norman

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
 */

#ifndef controllerLayout_h
#define controllerLayout_h

#include "Arduino.h"
#include "controllerLayoutDefine.h"


class controllerLayout 
{
private:
struct switch_control {
  int switch_type;                 // type of switch connected
  int switch_pin;                  // digital input pin assigned to the switch
  int circuit_type;                // the type of circuit wired to the switch
  bool switch_on_value;            // used for BUTTON SWITCHES only - defines what "on" means, set up in setup()
  bool switch_pending;             // records if switch in transition or not
  long unsigned int elapse_timer;  // records debounce timer count when associated switch is in transition
  bool switch_status;              // used for TOGGLE SWITCHES only - current state of toggle switch.
} switches[num_switches] = {
  // Note order of preset entries not relevant, but keep in a tidy order

  toggle_switch,
  cameraSelect,
  circuit_C2,
  not_used,
  false,
  0,
  !on,

  toggle_switch,
  drivePwr,
  circuit_C2,
  not_used,
  false,
  0,
  !on,

  toggle_switch,
  videoTransmitPwr,
  circuit_C2,
  not_used,
  false,
  0,
  !on,
  
  toggle_switch,
  micRecord,
  circuit_C2,
  not_used,
  false,
  0,
  !on,

  toggle_switch,
  lightBPwr,
  circuit_C2,
  not_used,
  false,
  0,
  !on,

  toggle_switch,
  lightAPwr,
  circuit_C2,
  not_used,
  false,
  0,
  !on,

  toggle_switch,
  shutterSelect,
  circuit_C2,
  not_used,
  false,
  0,
  !on,

  toggle_switch,
  cameraBPwr,
  circuit_C2,
  not_used,
  false,
  0,
  !on,

  toggle_switch,
  cameraAPwr,
  circuit_C2,
  not_used,
  false,
  0,
  !on,

  button_switch,
  apertureP,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  apertureN,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  isoP,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  isoN,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  shutterSpeedP,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  shutterSpeedN,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  menu,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  up,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  down,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  left,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  right,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  select,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  playBack,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  triggerAF,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  shutter,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  recVideo,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  customOne,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  customTwo,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  customThree,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,

  button_switch,
  customFour,
  circuit_C2,
  LOW,
  false,
  0,
  not_used,
};

public:
controllerLayout(void);
void switchSetup (void);
bool read_switch (uint8_t sw);
bool read_toggle_switch (uint8_t sw);
bool read_button_switch (uint8_t);
uint16_t pollSwitches();

};
#endif