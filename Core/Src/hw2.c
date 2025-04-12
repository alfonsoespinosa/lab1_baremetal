#include "stm32f4xx_hal.h"
#include "main.h"

void red_led_on()
{
	HAL_GPIO_WritePin(RED_LED_GPIO_PORT, RED_LED_GPIO_PIN, GPIO_PIN_SET);
}

void red_led_off()
{
	HAL_GPIO_WritePin(RED_LED_GPIO_PORT, RED_LED_GPIO_PIN, GPIO_PIN_RESET);
}

void green_led_on()
{
	HAL_GPIO_WritePin(GREEN_LED_GPIO_PORT, GREEN_LED_GPIO_PIN, GPIO_PIN_SET);
}

void green_led_off()
{
	HAL_GPIO_WritePin(GREEN_LED_GPIO_PORT, GREEN_LED_GPIO_PIN, GPIO_PIN_RESET);
}
