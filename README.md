# HyperController

Arduino based device for 3D space navigation and manipulation inside FreeCAD and probably others.

This stated as a weekend project for my own usage, but the outcome was so satisfiying so 
I am releasing it as Open Hardware with love to the FreeCAD Community.

![image](https://github.com/mnesarco/HyperController/raw/main/_web/hyperc.png)

## Project Status

This project is in its infancy, currently it is just the result of a weekend project.

## Features/Goals

* Keep the hand in rest position all the time
* Allow direct Panning, Zomming and Rotation without modal buttons and without Mouse or Keyboard interference.
* Extendable Hardware, Firmware and Software
* Open Hardware, Open Source
* USB communication
* Affordable components
* Easy to build, easy to install, easy to mod

## Documentation

* Arduino Wiring/Schematic:
https://github.com/mnesarco/HyperController/raw/main/hardware/schema.pdf
* Axes Movements: https://github.com/mnesarco/HyperController/raw/main/hardware/axes.pdf
* Firmware: The source code is well documented: https://github.com/mnesarco/HyperController/blob/main/firmware
  * `config.hpp` contains all configurations.
  * `HyperController.ino` is the main arduino sketch.
  * Everything else are utilities.

## FreeCAD Integration

This device uses USB to comunicate with FreeCAD, in order to make it happend, you need to Install a FreeCAD extension called "Mnesarco's Utils for FreeCAD" from here: https://github.com/mnesarco/FreeCAD_Utils.git

## License and permissions

1. Freely Use and/or modify this software under GPLv3. So if you use and/or modify it, please share your modifications back to the community.
2. It is not allowed to use or distribute this software/hardware commercially or with commercial purposes. I you want a commercial license, please contact me.
3. If you redistribute this project or any of its parts, you must include a copyright notice: **Copyright (c) 2020 Frank D. Martinez M.** and a link to this repository: https://github.com/mnesarco/HyperController.git
4. You must not modify the copyright info inside the source files.

## Notices

* ARDUINO&reg; and other Arduino brands and logos are Trademarks of Arduino SA.
* FreeCAD is an independent Open Source project: https://freecadweb.org

