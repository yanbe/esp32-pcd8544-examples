#include "rom/ets_sys.h"
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

    {
        pcd8544_puts("Entering inverse mode");
        ets_delay_us(3000000);

        pcd8544_set_display_mode(PCD8544_DISPLAY_MODE_INVERSE);
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_set_pos(0, 0);
        pcd8544_puts("Inverse mode");
        pcd8544_sync_and_gc();
        ets_delay_us(3000000);
    }

    {
        pcd8544_set_display_mode(PCD8544_DISPLAY_MODE_NORMAL);
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_set_pos(0, 0);
        pcd8544_puts("Entring blank mode");
        ets_delay_us(3000000);

        pcd8544_set_display_mode(PCD8544_DISPLAY_MODE_BLANK);
        pcd8544_sync_and_gc();
        ets_delay_us(3000000);
    }

    {
        pcd8544_set_display_mode(PCD8544_DISPLAY_MODE_NORMAL);
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_set_pos(0, 0);
        pcd8544_puts("Entring all segments on mode");
        ets_delay_us(3000000);

        pcd8544_set_display_mode(PCD8544_DISPLAY_MODE_ALL_SEGMENTS_ON);
        pcd8544_sync_and_gc();
        ets_delay_us(3000000);
    }

    {
        pcd8544_set_display_mode(PCD8544_DISPLAY_MODE_NORMAL);
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_set_pos(0, 0);
        pcd8544_puts("Entering low contrast mode");
        ets_delay_us(3000000);

        pcd8544_set_contrast(18);
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_set_pos(0, 0);
        pcd8544_puts("Low contrast mode");
        pcd8544_sync_and_gc();
        ets_delay_us(3000000);
    }

    {

        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_set_contrast(20);
        pcd8544_set_pos(0, 0);
        pcd8544_puts("Entering high contrast mode");
        ets_delay_us(3000000);

        pcd8544_set_contrast(26);
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_set_pos(0, 0);
        pcd8544_puts("High contrast mode");
        ets_delay_us(3000000);
    }

    {
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_set_contrast(20);
        pcd8544_set_pos(0, 0);
        pcd8544_puts("Backlight control. Blink twice");
        ets_delay_us(3000000);
        pcd8544_set_backlight(false);
        ets_delay_us(1000000);
        pcd8544_set_backlight(true);
        ets_delay_us(1000000);
        pcd8544_set_backlight(false);
        ets_delay_us(1000000);
        pcd8544_set_backlight(true);
        ets_delay_us(3000000);
    }

    {
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_set_pos(0, 0);
        pcd8544_puts("Entering power-down mode. Backlight off and content is cleared");
        ets_delay_us(3000000);

        pcd8544_set_powerdown_mode(true);
        pcd8544_sync_and_gc();
        ets_delay_us(3000000);

        pcd8544_set_powerdown_mode(false);
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_puts("Backed from power-down mode");
        ets_delay_us(3000000);
    }

    {
        pcd8544_clear_display();
        pcd8544_finalize_frame_buf();
        pcd8544_puts("Finished.");
    }

    pcd8544_sync_and_gc();
    pcd8544_free();
}
