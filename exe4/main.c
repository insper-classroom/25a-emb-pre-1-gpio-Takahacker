#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int LED_PIN_Red = 5;
const int LED_PIN_Purple = 8;
const int LED_PIN_Blue = 11;
const int LED_PIN_Yellow = 15;

const int BTN_PIN_Red = 28;


int main() {
  stdio_init_all();
  gpio_init(LED_PIN_Red);
  gpio_init(LED_PIN_Purple);
  gpio_init(LED_PIN_Blue);
  gpio_init(LED_PIN_Yellow);

  gpio_set_dir(LED_PIN_Red, GPIO_OUT);
  gpio_set_dir(LED_PIN_Purple, GPIO_OUT);
  gpio_set_dir(LED_PIN_Blue, GPIO_OUT);
  gpio_set_dir(LED_PIN_Yellow, GPIO_OUT);

  gpio_init(BTN_PIN_Red);
  gpio_set_dir(BTN_PIN_Red, GPIO_IN);
  gpio_pull_up(BTN_PIN_Red);

  while (true) {
    // Use delay de 300 ms entre os estados!

    if (!gpio_get(BTN_PIN_Red)) {
      while (!gpio_get(BTN_PIN_Red))
        ;
      gpio_put(LED_PIN_Red, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_Red, 0);

      gpio_put(LED_PIN_Purple, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_Purple, 0);

      gpio_put(LED_PIN_Blue, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_Blue, 0);

      gpio_put(LED_PIN_Yellow, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_Yellow, 0);
    }
  }
}
