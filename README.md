# ESP32-PCD8544 example projects 

This repository hold example projects of [yanbe/esp32-pcd8544](https://github.com/yanbe/esp32-pcd8544), 
Nokia 5100 LCD driver for ESP-IDF https://github.com/espressif/esp-idf.

## Usage

```sh
$ git submodule update --init
$ cd examples/hello_pcd8544 # or other example you interested in
$ make menuconfig
$ make -j9 flash
$ make monitor

# via serial log, confirm which pins are automatically assigned 
  to Nokia 5100 LCD module. It will be something like below.
...
I (195) PCD8544: Control pins: RST=IO4, DC=IO25, BL=IO16
I (195) PCD8544: SPI pins: Din=IO12, Clk=IO14, CE=IO15
...
```

Enjoy.
