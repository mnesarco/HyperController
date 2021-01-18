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

#ifndef MNESARCO_COMMAND_H
#define MNESARCO_COMMAND_H

/**
* Syntactic sugar for command management
* <pre>
* process_commands {
*     command(CMD_ID_X, cmd_funtion_a);
*     command(CMD_ID_Y, cmd_funtion_b);
*     command(CMD_ID_Z, cmd_funtion_c);
* }
* </pre>
*/
#define process_commands int _cmdid_1q2w3e4r = read_command_id(); if (_cmdid_1q2w3e4r)
#define command(CMD_ID, CMD) if (CMD_ID == _cmdid_1q2w3e4r) CMD()

#endif
