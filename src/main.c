#include "esp_check.h"
#include "driver/gpio.h"
#include "iot_button.h"

/*
 * Most development boards have "boot" button attached to GPIO0.
 * You can also change this to another pin.
 */
#define BOOT_BUTTON_NUM 0
#define SHORT_PRESS_MS 500
#define LONG_PRESS_MS 3000

#define MOD_TAG "GPIO-BTN"

/* Use board boot button as gpio input */
#define BTN_NUM BOOT_BUTTON_NUM

void btn_short_press_handler(void *button_handle, void *usr_data)
{

    ESP_LOGI(MOD_TAG, "button event: short press");
}

void btn_long_press_handler(void *button_handle, void *usr_data)
{

    ESP_LOGI(MOD_TAG, "button event: long press");
}

esp_err_t register_gpio_btn(void)
{
    // create gpio button
    button_config_t gpio_btn_cfg = {
        .type = BUTTON_TYPE_GPIO,
        .long_press_time = LONG_PRESS_MS,
        .short_press_time = SHORT_PRESS_MS,
        .gpio_button_config = {
            .gpio_num = BTN_NUM,
            .active_level = 0,
        },
    };
    button_handle_t gpio_btn = iot_button_create(&gpio_btn_cfg);
    if (NULL == gpio_btn)
    {
        ESP_LOGE(MOD_TAG, "Button create failed");
    }

    ESP_RETURN_ON_ERROR(iot_button_register_cb(gpio_btn, BUTTON_SINGLE_CLICK, btn_short_press_handler, NULL), MOD_TAG, "setup button event hander failed");
    ESP_RETURN_ON_ERROR(iot_button_register_cb(gpio_btn, BUTTON_LONG_PRESS_UP, btn_long_press_handler, NULL), MOD_TAG, "setup button event hander failed");

    return ESP_OK;
}

void app_main(void)
{
    register_gpio_btn();
}
