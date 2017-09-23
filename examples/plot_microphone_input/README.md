## Plot microphone input example

This example demonstrates how to plot input from analog microphone.

`NOTE`: To try this example application you have to get analog microphone like below (if you don't have already).

[MAX9814 Microphone AGC Amplifier Board Module Auto Gain Control for Arduino Programmable Attack and Release Ratio Low THD-in Integrated Circuits from Electronic Components & Supplies on Aliexpress.com | Alibaba Group](https://www.aliexpress.com/item/MAX9814-Microphone-AGC-Amplifier-Board-Module-Auto-Gain-Control-for-Arduino-Programmable-Attack-and-Release-Ratio/32811696553.html)

And then connect microphone's analog output to SVP (GPIO36).

This example also demonstrates when DMA transfer mode of ESP32-PCD8544 is useful.

`task_read_sensor()` receives input signal from a microphone every 200 microseconds. We don't want to drop these data.

So `task_plot_graph()` is using DMA transfer option ( `.dma_chan=1` for DMA channel 1 ), to data transfer 
can be done in background (no CPU load) as possible, to make CPU can concentrate recieving microphone signals.


For detail of API see.
[API Reference](http://esp32-pcd8544.readthedocs.io/en/latest/api-reference/pcd8544/index.html).
