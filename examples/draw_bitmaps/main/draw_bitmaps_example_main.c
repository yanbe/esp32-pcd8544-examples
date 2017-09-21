#include "driver/spi_common.h"
#include "pcd8544.h"
#include "bitmaps.h"

void app_main(void) {
    pcd8544_config_t config = {
        .spi_host = HSPI_HOST,
        .is_backlight_common_anode = true,
    };
    pcd8544_init(&config);
    pcd8544_clear_display();
    pcd8544_draw_bitmap(smily_bitmap, 18, 2, false);

    /* transparent on */
    pcd8544_set_pos(30, 3);
    pcd8544_draw_bitmap(smily_bitmap, 18, 2, false);
    pcd8544_set_pos(35, 4);
    pcd8544_draw_bitmap(smily_bitmap, 18, 2, true);

    /* transparent off */
    pcd8544_set_pos(50, 0);
    pcd8544_draw_bitmap(smily_bitmap, 18, 2, false);
    pcd8544_set_pos(55, 1);
    pcd8544_draw_bitmap(smily_bitmap, 18, 2, false);

    pcd8544_finalize_frame_buf();
    pcd8544_sync_and_gc();
    pcd8544_free();
}
