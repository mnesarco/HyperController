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


#ifndef MNESARCO_3DM_SERIAL_H
#define MNESARCO_3DM_SERIAL_H

// +--------------------------------------------------------------------------+
// | Serial communitation functions                                           |
// +--------------------------------------------------------------------------+

// usb setup
void serial_init()
{
  Serial.begin(BAUD_RATE);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }  
  delay(1000);
}

// Read integer command id from usb
int read_command_id()
{
  if (Serial.available() > 0) {
    return Serial.parseInt();
  }
  return 0;
}

// Send events by usb
// Poor man's "Template argument deduction" not available in arduino.
#define PRINT_CODE Serial.print(event); Serial.print('\t'); Serial.println(value);
void send(int event, int value)                         { PRINT_CODE }
void send(int event, float value)                       { PRINT_CODE }
void send(int event, const __FlashStringHelper* value)  { PRINT_CODE }
void send(int event, const char* value)                 { PRINT_CODE }
#undef PRINT_CODE

#endif
