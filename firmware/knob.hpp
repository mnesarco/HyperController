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

#ifndef MNESARCO_KNOB_H
#define MNESARCO_KNOB_H

#include "serial.hpp"

template<int _PIN, int _EVENT, int _THRESHOLD>
struct Knob
{
    int value = -1024;
    int offset = 0;

    void init()
    {
        pinMode(_PIN, INPUT);
    }

    void process()
    {
        int read = analogRead(_PIN) - offset;
        int diff = value - read;
        if (diff > _THRESHOLD || diff < - _THRESHOLD)
        {
            value = read;
            send(_EVENT, value);
        }
    }

    void calibrate()
    {
        offset = analogRead(_PIN);
        send(_EVENT, 0);
    }

};


#endif