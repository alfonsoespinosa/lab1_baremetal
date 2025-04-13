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


static void delay_ms(uint32_t msec)
{
  volatile uint32_t counter = 14000 * msec;

  while (counter--) {}
}

const uint32_t UART_BAUDRATE = 9600;

enum { RED = 0, GREEN, BLUE, NUM_LEDS };

uint32_t led_period_ms[NUM_LEDS];
int32_t led_toggle_time_ms[NUM_LEDS];

void reset_timer(int led)
{
	led_toggle_time_ms[led] = led_period_ms[led];
}

int main(void)
{
  hw_init();

  led_period_ms[RED] = 500;
  led_period_ms[GREEN] = 400;
  led_period_ms[BLUE] = 100;

  reset_timer(RED);
  reset_timer(GREEN);
  reset_timer(BLUE);

  uint32_t prev_tick_ms = HAL_GetTick();

  while (1)
  {
	  uint32_t current_tick_ms = HAL_GetTick();
	  uint32_t elapsed_ms = current_tick_ms - prev_tick_ms;

	  led_toggle_time_ms[GREEN] -= elapsed_ms;
	  led_toggle_time_ms[RED] -= elapsed_ms;
	  led_toggle_time_ms[BLUE] -= elapsed_ms;

	  if (led_toggle_time_ms[GREEN] <= 0) {
		  toggle_green_led();
		  reset_timer(GREEN);
	  }

	  if (led_toggle_time_ms[RED] <= 0) {
		  toggle_red_led();
		  reset_timer(RED);
	  }

	  if (led_toggle_time_ms[BLUE] <= 0) {
		  toggle_blue_led();
		  reset_timer(BLUE);
	  }

	  prev_tick_ms = HAL_GetTick();
  }

}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (USER_BUTTON_GPIO_PIN == GPIO_Pin)
  {
  }
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
