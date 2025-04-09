#include <stdbool.h>
#include <stdio.h>

#include "main.h"
#include "hw.h"

#define GREEN_LED_TOOGLE_TIME_MS 500
#define BLUE_LED_TOGGLE_TIME_MS 333

bool toggle_red = false;

static void delay_ms(uint32_t msec)
{
	uint32_t initial_tick_ms = HAL_GetTick();
	uint32_t final_tick_ms = initial_tick_ms + msec;

	while (HAL_GetTick() < final_tick_ms) {}
}

int main(void)
{
  init();

  int32_t green_led_toggle_time_ms = GREEN_LED_TOOGLE_TIME_MS;
  int32_t blue_led_toggle_time_ms = BLUE_LED_TOGGLE_TIME_MS;
  uint32_t prev_tick_ms = HAL_GetTick();

  while (1)
  {
	// Bucle
  }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if (USER_BUTTON_GPIO_PIN == GPIO_Pin)
  {
    HAL_GPIO_TogglePin(RED_LED_GPIO_PORT, RED_LED_GPIO_PIN);
    toggle_red = true;
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
