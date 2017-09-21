## Drawing bitmap example of ESP32-PCD8544

This example application demonstrates drawing bitmap demo with transparency support. 

Like [line drawing demo](https://github.com/yanbe/esp32-pcd8544-examples/tree/master/examples/draw_lines),
bitmaps are initially written in frame buffer. You have to call `pcd8544_finalize_frame_buf()`
transfer them to Nokia 5510 LCD DDRAM so that LCD content is updated.

For detail of API see.
[API Reference](http://esp32-pcd8544.readthedocs.io/en/latest/api-reference/pcd8544/index.html).

