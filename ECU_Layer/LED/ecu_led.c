/* 
 * File:   ecu_led.c
 * Author: LEGION
 *
 * Created on August 10, 2024, 10:07 PM
 */

#include "ecu_led.h"

/**
 * @breif Initialize the assigned pin to be output and turn the led off
 * @param led
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
STD_ReturnType led_initialize(const led_t *led) {
    STD_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOK;
    } else {
        pin_config_t pin_obj = {.port = led->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status};
        gpio_pin_initialization(&pin_obj);
    }
    return ret;
}

/**
 * @breif turn on the led
 * @param led
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
STD_ReturnType led_turn_on(const led_t *led) {
    STD_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOK;
    } else {
        pin_config_t pin_obj = {.port = led->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status};
        ret = gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return ret;
}

/**
 * @breif turn the led of
 * @param led
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
STD_ReturnType led_turn_off(const led_t *led) {
    STD_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOK;
    } else {
        pin_config_t pin_obj = {.port = led->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status};
        ret = gpio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return ret;
}

/**
 * 
 * @param led
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
STD_ReturnType led_turn_toggle(const led_t *led) {
    STD_ReturnType ret = E_OK;
    if (NULL == led) {
        ret = E_NOK;
    } else {
        pin_config_t pin_obj = {.port = led->port_name,
            .pin = led->pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = led->led_status};
        ret = gpio_pin_toggle_logic(&pin_obj);
    }
    return ret;
}