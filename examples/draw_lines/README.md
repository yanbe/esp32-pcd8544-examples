## Line drawing example of ESP32-PCD8544

Drawing line API is availble so you can plot small line graphs or draw menu UI easily. 
Nokia 5100 LCD has 84x48 pixels, You can pass (x0, y0, x1, y0) corrdinates to draw lines.

via `pcd8544_draw_line(x0, y0, x1, y1)` line data is  written are internal "frame buffer" 
memory in ESP32 first.

When writing content to frame buffer finsihed, You have to call `pcd8544_finalize_frame_buf()`
to update LCD content.

For detail of API see.
[API Reference](http://esp32-pcd8544.readthedocs.io/en/latest/api-reference/pcd8544/index.html).

