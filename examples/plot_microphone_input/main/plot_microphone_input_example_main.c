#include <string.h>
#include "driver/spi_common.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "pcd8544.h"
#include "driver/adc.h"

xQueueHandle queue;

void task_read_sensor(void* arg) {
    adc1_config_width(ADC_WIDTH_12Bit);
    adc1_config_channel_atten(ADC1_CHANNEL_0, ADC_ATTEN_11db);
    uint16_t value;
    while (true) {
        value = adc1_get_raw(ADC1_CHANNEL_0);
        xQueueSend(queue, &value, portMAX_DELAY);
        ets_delay_us(200);
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
    uint16_t samples = 0;
    memset(data, 47, 84);
    while (true) {
        xQueueReceive(queue, &value ,portMAX_DELAY);
        data[i] = value / 45;
        i = (i + 1)  % 84;
        if (samples % 1000 == 0) {
            pcd8544_clear_display();
            for (uint8_t x = 0; x < 83; x++) {
                pcd8544_draw_line(x, data[83-x], x+1, data[82-x]);
            }
            pcd8544_finalize_frame_buf();
            pcd8544_set_pos(0, 0);
            pcd8544_printf("%d samples", samples);
            pcd8544_sync_and_gc();
        }
        samples++;
    }
    vTaskDelete(NULL);
}

void app_main(void) {
    queue = xQueueCreate(100, 2);
    xTaskCreate(&task_plot_graph, "plot_graph_task", 4098, NULL, 5, NULL);
    xTaskCreate(&task_read_sensor, "read_sensor_task", 4098, NULL, 5, NULL); }
