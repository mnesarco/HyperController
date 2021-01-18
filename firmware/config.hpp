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

#ifndef MNESARCO_3DM_CONFIG_H
#define MNESARCO_3DM_CONFIG_H

// +----------------------------------------------------------+
// | Firmware Identification                                  |
// +----------------------------------------------------------+

#define FIRMWARE_NAME       "Mnesarco's Hyper Controller Firmware"
#define FIRMWARE_VERSION    "1.0.0"
#define FIRMWARE_COPYRIGHT  "Copyright (C) 2021 Frank D. Martinez M. <https://github.com/mnesarco>"
#define FIRMWARE_LICENSE    "GPLv3 <https://www.gnu.org/licenses/gpl-3.0.en.html>"


// +----------------------------------------------------------+
// | Hardware Pinouts                                         |
// +----------------------------------------------------------+

#define PIN_X       A1 // |
#define PIN_Y       A0 // | <---- XY Joystick
#define PIN_BTN_XY  10 // |

#define PIN_Z       A3 // |  
#define PIN_W       A2 // | <---- ZW Joystick
#define PIN_BTN_ZW  16 // | 

#define PIN_KNOB    A9 // | <---- Potentiometer

#define PIN_BTN_A    8 // |
#define PIN_BTN_B   14 // | <---- Push buttons
#define PIN_BTN_C    6 // |


// +----------------------------------------------------------+
// | Calibration parameters                                   |
// +----------------------------------------------------------+

#define BUTTON_LONG_PRESS_TIME  500  // Pressed milliseconds to trigger Long Press event
#define BUTTON_CLICK_TIME        80  // Pressed milliseconds to trigger Click event
#define SENSITIVITY             100  // Higher sensitivity value = slower mouse, should be <= about 500
#define SLOWDOWN                 30  // Main loop slowdown (ms)
#define JOYSTICK_THRESHOLD        5  // To avoid oscillations near to center
#define KNOB_THRESHOLD            5  // To avoid oscillations


// +----------------------------------------------------------+
// | Event codes (sent through usb)                           |
// +----------------------------------------------------------+

#define EVENT_X                       1 // |
#define EVENT_Y                       2 // | <--- Orthogonal Axes events
#define EVENT_Z                       3 // |      (translational axes)
#define EVENT_W                       4 // |

#define EVENT_RX                      5 // |
#define EVENT_RY                      6 // | <--- 45 deg Axes events
#define EVENT_RZ                      7 // |      (rotational axes)
#define EVENT_RW                      8 // |

#define EVENT_XY0                     9 // | <--- Joystick center events
#define EVENT_ZW0                    10 // | 

#define EVENT_BUTTON_XY_CLICK        50 // | <--- XY Joystick push button events
#define EVENT_BUTTON_XY_LONG_PRESS   51 // | 

#define EVENT_BUTTON_ZW_CLICK        60 // | <--- ZW Joystick push button events
#define EVENT_BUTTON_ZW_LONG_PRESS   61 // | 

#define EVENT_BUTTON_A_CLICK         70 // |
#define EVENT_BUTTON_A_LONG_PRESS    71 // |
                                        // | 
#define EVENT_BUTTON_B_CLICK         80 // | <--- Push buttons events
#define EVENT_BUTTON_B_LONG_PRESS    81 // |
                                        // |
#define EVENT_BUTTON_C_CLICK         90 // |
#define EVENT_BUTTON_C_LONG_PRESS    91 // |

#define EVENT_KNOB                  100 // | <--- Knob (potentiometer) event

#define EVENT_COMMENT               999 // | <--- Generic text based event


// +----------------------------------------------------------+
// | Commands (received through usb)                          |
// +----------------------------------------------------------+

#define CMD_FIRMWARE_INFO  1  // Print Firmware version
#define CMD_CALIBRATE      2  // Recalibrate Analogs (all analogs should be physically in zero position)


// +----------------------------------------------------------+
// | USB Communication                                        |
// +----------------------------------------------------------+

#define BAUD_RATE  115200  // Serial port speed

#endif
