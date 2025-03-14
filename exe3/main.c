#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_R = 4;
const int LED_PIN_G = 6;
const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;

int main(){
    stdio_init_all();
    gpio_init(LED_PIN_R);
    gpio_init(LED_PIN_G);
    gpio_set_dir(LED_PIN_R, GPIO_OUT);
    gpio_set_dir(LED_PIN_G, GPIO_OUT);
    gpio_put(LED_PIN_R, 0);
    gpio_put(LED_PIN_G, 0);

    gpio_init(BTN_PIN_R);
    gpio_init(BTN_PIN_G);
    gpio_set_dir(BTN_PIN_R, GPIO_IN);
    gpio_set_dir(BTN_PIN_G, GPIO_IN);
    gpio_pull_up(BTN_PIN_R);
    gpio_pull_up(BTN_PIN_G);

    int i_R = 0;
    int i_G = 0;

    while (true)
    {
        if (!gpio_get(BTN_PIN_R))
        {
            i_R = !i_R;
            gpio_put(LED_PIN_R, i_R);
            sleep_ms(200);  
        }

        if (!gpio_get(BTN_PIN_G))
        {
            i_G = !i_G;
            gpio_put(LED_PIN_G, i_G);
            sleep_ms(200); 
        }
    }
}