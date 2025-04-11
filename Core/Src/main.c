#include <stdbool.h>
#include <stdio.h>

#include "main.h"

extern void hw_init();

extern void toggle_red_led();
extern void toggle_green_led();
extern void toggle_blue_led();

static void delay_ms(uint32_t msec)
{
  volatile uint32_t counter = 14000 * msec;
  while (counter--) {}
}

const uint32_t UART_BAUDRATE = 9600;

int main(void)
{
  hw_init();

  while (1)
  {
    /* SUPERLOOP */
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
