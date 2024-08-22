/* 
 * File:   ecu_relay.c
 * Author: LEGION
 *
 * Created on August 20, 2024, 9:18 PM
 */

#include "ecu_relay.h"

/**
 * 
 * @param _relay
 * @return 
 */
STD_ReturnType relay_initialize(const relay_t *_relay) {

    STD_ReturnType ret = E_OK;
    if (NULL == _relay) {
        ret = E_NOK;
    } else {
        pin_config_t pin_obj = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = _relay->relay_status,
        };
        gpio_pin_initialization(&pin_obj);
    }
    return ret;
}

/**
 * 
 * @param _relay
 * @return 
 */
STD_ReturnType relay_turn_on(const relay_t *_relay) {
    STD_ReturnType ret = E_OK;
    if (NULL == _relay) {
        ret = E_NOK;
    } else {
        pin_config_t pin_obj = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = _relay->relay_status,
        };
        gpio_pin_write_logic(&pin_obj, GPIO_HIGH);
    }
    return ret;

}

/**
 * 
 * @param _relay
 * @return 
 */
STD_ReturnType relay_turn_off(const relay_t *_relay) {

    STD_ReturnType ret = E_OK;
    if (NULL == _relay) {
        ret = E_NOK;
    } else {
        pin_config_t pin_obj = {
            .port = _relay->relay_port,
            .pin = _relay->relay_pin,
            .direction = GPIO_DIRECTION_OUTPUT,
            .logic = _relay->relay_status,
        };
        gpio_pin_write_logic(&pin_obj, GPIO_LOW);
    }
    return ret;
}