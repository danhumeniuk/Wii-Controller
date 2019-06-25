# Wii-Controller

Wii-Controller turns your Wii Balance Board into a custom controller of your choosing. Wii-Controller runs on Linux and it also runs on a Raspberry Pi.

This project is heavily modified from https://github.com/aelveborn/Wii-Scale and the original code can be found there. This fork
removes most of the web interface as well as weighing aspects of the original project and only collects the output from any connected
Wii Balance Board.

Wii-Controller is based on C++.

## Usage

Before you can use Wii-Controller, you need to have your balance board paired with your computer and connected.

## Installation

Wii-Controller runs most likely only on Linux. Follow these guides to install Wii-Scale on Ubuntu or Raspberry Pi:

To communicate with your Wii Balance Board you'll need a bluetooth 2.0 or 2.1 compatible device. You can find [compatible devices here](http://wiibrew.org/wiki/List_of_Working_Bluetooth_Devices). Wii-Controller is based on the following dependencies `Python 2`, `Python-pip` and `BlueZ` bluetooth stack.

### Install Wii-Controller

Download latest version of Wii-Controller (honestly, I'd just go to the original Wii-Scale repo because Andreas made a pretty good web interface but for some reason if you just need the output like me then here you go):

	cd <your-directory>/
	git clone https://github.com/danhumeniuk/Wii-Controller.git --recursive --depth 1
	cd Wii-Scale/

Allow non-root users to access balance board:

	sudo cp wii-controller/70-wii-scales.rules /etc/udev/rules.d/

Run install:

	mkdir build && cd build
	cmake ../wii-scale && make

### Run

	./wii-controller

## Libraries

Wii-Controller uses the [xwiimote](https://github.com/dvdhrm/xwiimote), [glibmm / giomm](https://developer.gnome.org/glibmm) and [libudev](https://www.freedesktop.org/software/systemd/man/libudev.html) libraries.

## Licence

Wii-Scale is created and copyrighted by [Andreas Älveborn](http://aelveborn.com) and lincensed under GPL v2.

This project has been modified to only extract data from the Wii Balance Board