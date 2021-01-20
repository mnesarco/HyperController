# HyperController

Arduino based device for 3D space navigation and manipulation inside FreeCAD and probably others.

This stated as a weekend project for my own usage, but the outcome was so satisfiying so 
I am releasing it as Open Hardware with love to the FreeCAD Community.

[![image](https://github.com/mnesarco/HyperController/raw/main/_web/hyperc.png)](https://www.youtube.com/watch?v=o9VPcpPox0Q)
[View on youtube.com](https://www.youtube.com/watch?v=o9VPcpPox0Q)

## Project Status

This project is in its infancy, currently it is just the result of a weekend project.

## IMPORTANT!!!

This repository is not a FreeCAD extension, this repo contains the Hardware and Firmware part of the HyperController. The required FreeCAD extension is [Mnesarco Utils](https://github.com/mnesarco/FreeCAD_Utils), you must install it from: https://github.com/mnesarco/FreeCAD_Utils


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

## Forum threads

* https://forum.freecadweb.org/viewtopic.php?f=24&t=54367

## Important notes about files inside **hardware/3dmodel**

Files inside `hardware/3dmodel` requires:
* FreeCAD 0.19_pre+
* Assembly4 Workbench (https://github.com/Zolko-123/FreeCAD_Assembly4)
* Mnesarco Utils Extension Pack (https://github.com/mnesarco/FreeCAD_Utils)


## Parts

|Image |Description  |Optional
|------|-------------|--------
|<img src="https://github.com/mnesarco/HyperController/raw/main/_web/joystick.jpg" width="200" />|2 Joystick modules|
|<img src="https://github.com/mnesarco/HyperController/raw/main/_web/push_button.jpg" width="200" />|1-3 Push buttons|
|<img src="https://github.com/mnesarco/HyperController/raw/main/_web/arduino_pro_micro.jpg" width="200" />|1 Arduino Pro Micro|
|<img src="https://github.com/mnesarco/HyperController/raw/main/_web/pot.jpg" width="200" />|0-3 Potentiometers (Value: between 10k and 50k are ok)|Optional


## Notices

* ARDUINO&reg; and other Arduino brands and logos are Trademarks of Arduino SA.
* FreeCAD is an independent Open Source project: https://freecadweb.org

