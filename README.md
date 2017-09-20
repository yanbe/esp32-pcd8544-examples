# ESP32-PCD8544 example projects

This repository hold example projects of [ESP32-PCD8544](https://github.com/yanbe/esp32-pcd8544),
Nokia 5100 LCD driver for [Espressif IoT Development Framework (ESP-IDF)](https://github.com/espressif/esp-idf).

## Usage

```sh
$ git submodule update --init
$ cd examples/hello_pcd8544 # or other example you interested in
$ make menuconfig
$ make -j9 flash
$ make monitor

# You can confirm which pins are automatically assigned o Nokia 5110 LCD module
# via serial monitor. It will be something like below.
...
I (195) PCD8544: Control pins: RST=IO4, DC=IO25, BL=IO16
I (195) PCD8544: SPI pins: Din=IO12, Clk=IO14, CE=IO15
...

# Then connect your Nokia 5110 LCD module to ESP32 according to the guide above.
```

Enjoy.
