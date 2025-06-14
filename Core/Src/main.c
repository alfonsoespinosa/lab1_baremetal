#include <stdbool.h>
#include <stdio.h>

#include "main.h"

extern void hw_init();

extern void toggle_red_led();
extern void toggle_green_led();
extern void toggle_blue_led();

extern void red_led_on();
extern void green_led_on();
extern void red_led_off();
extern void green_led_off();

const uint32_t UART_BAUDRATE = 9600;

#define DELAY_RED   500
#define DELAY_GREEN 400
#define DELAY_BLUE  100

static inline void delay_ms(uint32_t msec)
{
  volatile uint32_t counter = 14000 * msec;

  while (counter--) {}
}

void red_led_task()
{
  while (1) {
    toggle_red_led();
    delay_ms(DELAY_RED);
  }
}

void green_led_task()
{
  while (1) {
    toggle_green_led();
    delay_ms(DELAY_GREEN);
  }
}

void blue_led_task()
{
  while (1) {
    toggle_blue_led();
    delay_ms(DELAY_BLUE);
  }
}

int main(void)
{
  hw_init();

  red_led_task();
  green_led_task();
  blue_led_task();

  while (1)
  {
  }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (USER_BUTTON_GPIO_PIN == GPIO_Pin)
  {
  }
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  HAL_IncTick();
}

void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{
}
#endif /* USE_FULL_ASSERT */
