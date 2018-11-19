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
	uint8_t red = 0x20;
	uint8_t green = 0x10;
	uint8_t blue = 00;
    uint8_t i = 0;
	neopixel_init(&m_strip, dig_pin_num, leds_per_strip);
	neopixel_clear(&m_strip);
//	//clear and remove strip
//	neopixel_clear(&m_strip);
//	neopixel_destroy(&m_strip);	
	
    // Configure LED-pins as outputs.
    LEDS_CONFIGURE(LEDS_MASK);
	nrf_gpio_cfg_output(LED_0);
	nrf_gpio_cfg_input(BUTTON_1,NRF_GPIO_PIN_PULLUP);

    while (true)
    {
		if(nrf_gpio_pin_read(BUTTON_1))
		{
            error = neopixel_set_color_and_show(&m_strip, i, red, green, blue);
            nrf_delay_ms(500);
			nrf_gpio_pin_set(LED_0);
            i++;
            if(i >=12)
            {
                for(i=0;i<12;i++)
                {
                    error = neopixel_set_color_and_show(&m_strip, i, 0, 0, 0);
                    nrf_delay_ms(500);
                }
                i=0;
            }
		}
		else
		{
			nrf_gpio_pin_clear(LED_0);
		}
    }
}


/** @} */
