// Copyright (C) 2021 Frank David Martinez M. <https://github.com/mnesarco/>
// 
// This file is part of HyperController.
// 
// HyperController is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// HyperController is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Mnesarco Utils.  If not, see <http://www.gnu.org/licenses/>.
// 

#include "config.hpp"
#include "button.hpp"
#include "serial.hpp"
#include "joystick.hpp"
#include "knob.hpp"
#include "command.hpp"

// +--------------------------------------------------------------------------+
// | Global state                                                             |
// +--------------------------------------------------------------------------+

// Buttons
Button<PIN_BTN_XY, EVENT_BUTTON_XY_CLICK, EVENT_BUTTON_XY_LONG_PRESS> button_xy;
Button<PIN_BTN_ZW, EVENT_BUTTON_ZW_CLICK, EVENT_BUTTON_ZW_LONG_PRESS> button_zw;
Button<PIN_BTN_A,  EVENT_BUTTON_A_CLICK,  EVENT_BUTTON_A_LONG_PRESS>  button_a;
Button<PIN_BTN_B,  EVENT_BUTTON_B_CLICK,  EVENT_BUTTON_B_LONG_PRESS>  button_b;
Button<PIN_BTN_C,  EVENT_BUTTON_C_CLICK,  EVENT_BUTTON_C_LONG_PRESS>  button_c;

// Joysticks
Joystick<PIN_X, PIN_Y, EVENT_X, EVENT_Y, EVENT_RX, EVENT_RY, EVENT_XY0, JOYSTICK_THRESHOLD, SENSITIVITY> jxy;
Joystick<PIN_W, PIN_Z, EVENT_W, EVENT_Z, EVENT_RW, EVENT_RZ, EVENT_ZW0, JOYSTICK_THRESHOLD, SENSITIVITY> jzw;

// Knobs
Knob<PIN_KNOB, EVENT_KNOB, KNOB_THRESHOLD> knob;

// setup completion
bool ready = false;


// +--------------------------------------------------------------------------+
// | Commands                                                                 |
// |   functions that respond to command codes received by usb                |
// +--------------------------------------------------------------------------+

void cmd_print_info()
{
  send(EVENT_COMMENT, F(FIRMWARE_NAME " version " FIRMWARE_VERSION));
  send(EVENT_COMMENT, F(FIRMWARE_COPYRIGHT));
  send(EVENT_COMMENT, F("Compilation: " __DATE__ " " __TIME__));
};

void cmd_recalibrate()
{
  knob.calibrate();
  jxy.calibrate();
  jzw.calibrate();
  send(EVENT_COMMENT, F("Recalibration completed"));
};


// +==========================================================================+
// || Arduino::Setup                                                         ||
// +==========================================================================+

void setup()
{
  
  // Serial port
  serial_init();

  // Controls
  jxy.init();
  jzw.init();
  knob.init();
  button_xy.init();
  button_zw.init();
  button_a.init();
  button_b.init();
  button_c.init();

  cmd_print_info();
  ready = true;

}


// +==========================================================================+
// || Arduino::Loop                                                          ||
// +==========================================================================+

void loop()
{

  // wait for setup completion
  if (!ready) {
    return;
  }

  // Currrent time
  unsigned long time = millis();

  // Process serial inputs
  process_commands {
    command(CMD_FIRMWARE_INFO, cmd_print_info);
    command(CMD_CALIBRATE, cmd_recalibrate);
  }

  // Process serial outputs
  jxy.process();  
  jzw.process();
  knob.process();
  button_xy.process(time);
  button_zw.process(time);
  button_a.process(time);
  button_b.process(time);
  button_c.process(time);

  // Show version info if requested by hardware
  if (button_xy.long_pressed && button_zw.long_pressed)
  {
    cmd_print_info();
  }

  // Slowdown
  delay(SLOWDOWN);

}
