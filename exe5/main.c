#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 26;
const int BTN_PIN_2 = 7;
const int DEBOUNCE_DELAY = 10; // ms

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);

    gpio_init(BTN_PIN_2);
    gpio_set_dir(BTN_PIN_2, GPIO_IN);
    gpio_pull_up(BTN_PIN_2);

    int cnt_1 = 0;
    int cnt_2 = 0;

    bool btn1_pressed = false;
    bool btn2_pressed = false;

    while (true) {
        
        if (!gpio_get(BTN_PIN)) {
            if (!btn1_pressed) {
                btn1_pressed = true;
                printf("Botao 1: %d\n", cnt_1++);
            }
        } else {
            btn1_pressed = false;
        }

        
        if (!gpio_get(BTN_PIN_2)) {
            if (!btn2_pressed) {
                btn2_pressed = true;
                printf("Botao 2: %d\n", cnt_2++);
            }
        } else {
            btn2_pressed = false;
        }

        sleep_ms(DEBOUNCE_DELAY);
    }
}