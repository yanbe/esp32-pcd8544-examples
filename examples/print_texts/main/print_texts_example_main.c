#include "driver/spi_common.h"
#include "pcd8544.h"

void app_main(void) {
    pcd8544_config_t config = {
        .spi_host = HSPI_HOST,
        .is_backlight_common_anode = true,
    };
    pcd8544_init(&config);
    pcd8544_clear_display();
    pcd8544_finalize_frame_buf();
    pcd8544_puts("Long text wraps line");
    pcd8544_set_pos(24, 3);
    pcd8544_puts("Positioned");
    pcd8544_set_pos(0, 5);
    float temperature = 24.563;
    pcd8544_printf("Format: %2.1f%", temperature);
    pcd8544_sync_and_gc();
    pcd8544_free();
}
