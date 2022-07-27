/*
  controllerLayout.cpp - Library to define button inputs for custom contoller layouts and button reading
  Author: Matt Norman

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

#include "controllerLayout.h"

/**
 *  Constructor class.
 */

controllerLayout::controllerLayout (){
}

/**
 *  initalize buttons
 */

void contollerLayout::switchSetup(void){
for (int sw = 0; sw < num_switches; sw++) {
    // Define the switch circuit type - circuit_type is:
    // circuit_C1 (INPUT) or circuit_C2 (INPUT_PULLUP)
    pinMode(switches[sw].switch_pin, switches[sw].circuit_type);
    // Establish 'meaning' for switch on/off for a button switch, depending on circuit type.
    // This is used only by button read function, it has no relevance for toggle switches.
    if (switches[sw].circuit_type == circuit_C2) {
      // Switch is NOT configured with a pull down switch resistor
      switches[sw].switch_on_value = LOW;  // switch pin goes LOW when switch pressed, ie on
    } else {
      // Circuit_type_C1, so switch IS configured with a pull down switch resistor
      switches[sw].switch_on_value = HIGH;  // switch pin goes HIGH when switch pressed, ie on
    }
  }
}

/**
 *  read button input
 */
bool controllerLayout::read_switch(uint8_t sw){
if (switches[sw].switch_type == button_switch) {
    return read_button_switch(sw);
  }
  return read_toggle_switch(sw);
}

/**
 *  toggle switch input 
 */

bool controllerLayout::read_toggle_switch(uint8_t sw){
int pin_value = digitalRead(switches[sw].switch_pin);  // test current state of toggle pin
  if (switches[sw].circuit_type == circuit_C2) {
    // Need to invert HIGH/LOW if circuit design sets pin HIGH representing switch in off state
    // ie inititialised as INPUT_PULLUP
    pin_value = !pin_value;
  }
  if (pin_value != switches[sw].switch_status && !switches[sw].switch_pending) {
    // Switch change detected so start debounce cycle
    switches[sw].switch_pending = true;
    switches[sw].elapse_timer = millis();  // set start of debounce timer
  } else {
    if (switches[sw].switch_pending) {
      // We are in the switch transition cycle so check if debounce period has elapsed
      if (millis() - switches[sw].elapse_timer >= debounce) {
        // Debounce period elapse so assume switch has settled down after transition
        switches[sw].switch_status = !switches[sw].switch_status;  // flip status
        switches[sw].switch_pending = false;                       // cease transition cycle
        return switched;
      }
    }
  }
  return !switched;
}

/**
 *  button switch input 
 */

bool controllerLayout::read_button_switch(uint8_t sw){
int switch_pin_reading;
  switch_pin_reading = digitalRead(switches[sw].switch_pin);
  if (switch_pin_reading == switches[sw].switch_on_value && !switches[sw].switch_pending) {
    // Switch is pressed (ON), so start/restart debounce process
    switches[sw].elapse_timer = millis();
    switches[sw].switch_pending = true;

    return switched;  // now waiting for debounce to conclude
  }
  if (switches[sw].switch_pending) {
    // Switch was pressed, now released (OFF), so check if debounce time elapsed
    if (millis() - switches[sw].elapse_timer > debounce) {
      // dounce time elapsed, so switch press cycle complete
      switches[sw].switch_pending = false;
      return !switched;
    }
  }

  return !switched;
}