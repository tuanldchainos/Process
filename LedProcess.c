#include "LedProcess.h"

mraa_gpio_context *gpio;

void gpio_pin_write_1(mraa_gpio_context gpio){
    mraa_gpio_write(gpio, 1);
}

void gpio_pin_write_0(){
    mraa_gpio_write(gpio, 0);
}

void led_pin_init(){
    uint8_t pins_map[] = LED_PINS_MAP;
    uint8_t pins_index[] = LED_PINS_INDEX_MAP;

    for(int i = 0; i < sizeof(pins_map)/sizeof(uint8_t); i++){
        gpio[pins_index[i]] = mraa_gpio_init(pins_map[i]);
        mraa_gpio_dir(gpio[pins_index[i]], MRAA_GPIO_OUT);
    }
}

void led_pin_on(mraa_aio_context led_pin){
    gpio_pin_write_1(led_pin);
}

void led_pin_off(mraa_aio_context led_pin){
    gpio_pin_write_0(led_pin);
}

void led_pin_blink_once(mraa_aio_context led_pin){
    led_pin_on(led_pin);
    sleep(1);
    led_pin_off(led_pin);
    sleep(1);
}

void* Led_Thread(void* arvg){
    return NULL;
}