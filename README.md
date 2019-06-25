# Wii-Controller

Wii-Controller extracts the sensor data from your Wii Balance Board.

This project is heavily modified from https://github.com/aelveborn/Wii-Scale and the original code can be found there. This fork
removes most of the web interface as well as weighing aspects of the original project and only collects the output from any connected
Wii Balance Board.

Wii-Controller is based on C++.

## Before You Run

Ensure your Wii Balance Board is connected to your computer via Bluetooth

## Installation

Wii-Controller is based on the following dependencies `Python 2`, `Python-pip` and `BlueZ` bluetooth stack.

### Installing

	cd <your-directory>/
	git clone https://github.com/danhumeniuk/Wii-Controller.git --recursive --depth 1
	cd Wii-Scale/
	sudo cp wii-controller/70-wii-scales.rules /etc/udev/rules.d/
	mkdir build && cd build
	cmake ../wii-scale && make

### Run

	./wii-controller

## Libraries

Wii-Controller uses the [xwiimote](https://github.com/dvdhrm/xwiimote), [glibmm / giomm](https://developer.gnome.org/glibmm) and [libudev](https://www.freedesktop.org/software/systemd/man/libudev.html) libraries.

## Licence

Wii-Scale is created and copyrighted by [Andreas Älveborn](http://aelveborn.com) and lincensed under GPL v2. Wii-Controller makes use of Andreas's code.

This project has been modified to only extract data from the Wii Balance Board