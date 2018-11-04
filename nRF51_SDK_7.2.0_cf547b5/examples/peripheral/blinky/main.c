/* Copyright (c) 2014 Nordic Semiconductor. All Rights Reserved.
 *
 * The information contained herein is property of Nordic Semiconductor ASA.
 * Terms and conditions of usage are described in detail in NORDIC
 * SEMICONDUCTOR STANDARD SOFTWARE LICENSE AGREEMENT.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 *
 */

/** @file
 *
 * @defgroup blinky_example_main main.c
 * @{
 * @ingroup blinky_example
 * @brief Blinky Example Application main file.
 *
 */

#include <stdbool.h>
#include <stdint.h>
#include "nrf_delay.h"
#include "nrf_gpio.h"
#include "boards.h"
#include "neopixel.h"

const uint8_t leds_list[LEDS_NUMBER] = LEDS_LIST;
/**
 * @brief Function for application main entry.
 */
int main(void)
{
	neopixel_strip_t m_strip;
	uint8_t dig_pin_num = 7;
	uint8_t leds_per_strip = 12;
	uint8_t error;
	uint8_t led_to_enable = 10;
	uint8_t red = 125;
	uint8_t green = 0;
	uint8_t blue = 123;

	neopixel_init(&m_strip, dig_pin_num, leds_per_strip);
	neopixel_clear(&m_strip);
//	//clear and remove strip
//	neopixel_clear(&m_strip);
//	neopixel_destroy(&m_strip);	
	
    // Configure LED-pins as outputs.
    LEDS_CONFIGURE(LEDS_MASK);
	nrf_gpio_cfg_output(LED_0);
    // Toggle LEDs.
    while (true)
    {
//        for (int i = 0; i < LEDS_NUMBER; i++)
//        {
//            LEDS_INVERT(1 << leds_list[i]);
//            nrf_delay_ms(500);
//        }
		led_to_enable++;
		led_to_enable = led_to_enable%12;
	error = neopixel_set_color_and_show(&m_strip, led_to_enable, red, green, blue);
	if (error) {
		//led_to_enable was not within number leds_per_strip
	}
		nrf_gpio_pin_set(LED_0);
		nrf_delay_ms(500);
		nrf_gpio_pin_clear(LED_0);
		nrf_delay_ms(500);
    }
}


/** @} */
