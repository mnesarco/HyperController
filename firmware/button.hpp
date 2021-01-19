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

#ifndef MNESARCO_3DM_BUTTON_H
#define MNESARCO_3DM_BUTTON_H

#include "serial.hpp"

// +--------------------------------------------------------------------------+
// | Push button abstraction                                                  |
// +--------------------------------------------------------------------------+

template<int _PIN, int _EVENT_CLICK, int _EVENT_LONG_PRESS>
class Button
{
  private:
    unsigned long press_time = 0;
    unsigned int click_time = 0;
    inline bool read() {
      return !digitalRead(_PIN);
    }

  public:
    bool pressed = false;
    bool long_pressed = false;
    bool click = false;



  bool read(unsigned long time)
  {
    bool value = read();
    if (value && !pressed)
    {
      press_time = time;
      click_time = time;
      pressed = true;
    }
    else if (!value && pressed)
    {
      pressed = false;
      click = false;
      long_pressed = false;
    }    
    if (pressed)
    {
      if (time - press_time > BUTTON_LONG_PRESS_TIME)
      {
        long_pressed = true;
        press_time = time;
      }
      else {
        long_pressed = false;
      }
      if (time - click_time > BUTTON_CLICK_TIME)
      {
        click = true;
        click_time = time;
      }
      else {
        click = false;
      }
    }
    else {
      long_pressed = false;
      click = false;
    }
    return pressed;
  }

  void init()
  {
    pinMode(_PIN, INPUT_PULLUP);
  }

  void process(unsigned int time)
  {
    read(time);
    if (click)
    {
      send(_EVENT_CLICK, 0);
    }
    if (long_pressed)
    {
      send(_EVENT_LONG_PRESS, 0);
    }
  }

};

#endif
