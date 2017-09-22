#include <string.h>
#include "driver/spi_common.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "pcd8544.h"
#include "driver/adc.h"
#include "esp_log.h"

xQueueHandle queue;

void task_read_sensor(void* arg) {
    touch_pad_init();
    touch_pad_config(TOUCH_PAD_NUM2, 0);
    uint16_t value;
    while (true) {
        touch_pad_read(TOUCH_PAD_NUM2, &value);
        xQueueSend(queue, &value, portMAX_DELAY);
        vTaskDelay(200 / portTICK_PERIOD_MS);
    }
    vTaskDelete(NULL);
}

void task_plot_graph(void* arg) {
    pcd8544_config_t config = {
        .spi_host = HSPI_HOST,
        .is_backlight_common_anode = true,
        .dma_chan = 1,
    };
    pcd8544_init(&config);
    uint8_t i = 0;
    uint16_t value = 0;
    uint8_t data[84];
    memset(data, 47, 84);
    while (true) {
        xQueueReceive(queue, &value ,portMAX_DELAY);
        pcd8544_clear_display();
        data[i] = value / 38;
        data[i] = data[i] >= 48 ? 47 : data[i];
        ESP_LOGI("sensor", "data[%d]=%d", i, data[i]);
        pcd8544_draw_line(83-i, 0, 83-i, 47);
        for (uint8_t x = 0; x < 83; x++) {
            pcd8544_draw_line(x, data[83-x], x+1, data[82-x]);
        }
        pcd8544_finalize_frame_buf();
        pcd8544_set_pos(0, 0);
        pcd8544_puts("Touch IO2!");
        pcd8544_sync_and_gc();
        i = (i + 1)  % 84;
    }
    vTaskDelete(NULL);
}

void app_main(void) {
    queue = xQueueCreate(1, 2);
    xTaskCreate(&task_plot_graph, "plot_graph_task", 4098, NULL, 5, NULL);
    xTaskCreate(&task_read_sensor, "read_sensor_task", 4098, NULL, 5, NULL);
}
