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

#ifndef MNESARCO_JOYSTICK_H
#define MNESARCO_JOYSTICK_H

#include "serial.hpp"

template<int _PIN_X, int _PIN_Y, int _EVENT_X, int _EVENT_Y, int _EVENT_RX, int _EVENT_RY, int _EVENT_XY0, int _THRESSHOLD, int _SENSITIVITY>
struct Joystick
{
    int offset = 0;
    int X0 = 0;
    int Y0 = 0;
    bool moved = false;
    
    inline void init()
    {
        pinMode(_PIN_X, INPUT);
        pinMode(_PIN_Y, INPUT);
        calibrate();
    }

    void calibrate()
    {
        X0 = analogRead(_PIN_X);
        Y0 = analogRead(_PIN_Y);
        send(_EVENT_XY0, 0);
    }

    inline int filter(int value)
    {
        if (value > _THRESSHOLD)
        {
            return value - _THRESSHOLD;
        }
        else if (value < -_THRESSHOLD)
        {
            return value + _THRESSHOLD;
        }
        return 0;
    }

    inline void send(int event, int value)
    {
        ::send(event, value / _SENSITIVITY);
    }

    inline void process()
    {
        int x = filter(analogRead(_PIN_X) - X0);
        int y = filter(analogRead(_PIN_Y) - Y0);

        // Rotations

        if (x > 0 && y > 0)
        {
            send(_EVENT_RX, x);
        }
        else if (x > 0 && y < 0)
        {
            send(_EVENT_RY, x);
        }
        else if (x < 0 && y > 0)
        {
            send(_EVENT_RY, x);
        }
        else if (x < 0 && y < 0)
        {
            send(_EVENT_RX, x);
        }

        // Translations

        else if (x != 0)
        {
            send(_EVENT_X, x);
        }
        else if (y != 0)
        {
            send(_EVENT_Y, y);
        }

        // Neutral

        if (x == 0 && y == 0)
        {
            if (moved)
            {
                send(_EVENT_XY0, 0);
                moved = false;
            }
        }
        else
        {
            moved = true;
        }

    }

};

#endif