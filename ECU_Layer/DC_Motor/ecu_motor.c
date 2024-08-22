/* 
 * File:   ecy_motor.c
 * Author: LEGION
 *
 * Created on August 22, 2024, 4:36 PM
 */

#include "ecu_motor.h"

//static pin_config_t motor_pin1;
//static pin_config_t motor_pin2;

STD_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor) {

    STD_ReturnType ret = E_OK;
    if (NULL == dc_motor) {
        ret = E_NOK;
    } else {

        gpio_pin_initialization(&(dc_motor->dc_motor[0]));
        gpio_pin_initialization(&(dc_motor->dc_motor[1]));

    }
    return ret;
}

STD_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor) {

    STD_ReturnType ret = E_OK;
    if (NULL == dc_motor) {
        ret = E_NOK;
    } else {
        gpio_pin_write_logic(&(dc_motor->dc_motor[0]), GPIO_HIGH);
        gpio_pin_write_logic(&(dc_motor->dc_motor[1]), GPIO_LOW);
    }
    return ret;

}

STD_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor) {

    STD_ReturnType ret = E_OK;
    if (NULL == dc_motor) {
        ret = E_NOK;
    } else {
        gpio_pin_write_logic(&(dc_motor->dc_motor[0]), GPIO_LOW);
        gpio_pin_write_logic(&(dc_motor->dc_motor[1]), GPIO_HIGH);
    }
    return ret;

}

STD_ReturnType dc_motor_stop(const dc_motor_t *dc_motor) {

    STD_ReturnType ret = E_OK;
    if (NULL == dc_motor) {
        ret = E_NOK;
    } else {
        gpio_pin_write_logic(&(dc_motor->dc_motor[0]), GPIO_LOW);
        gpio_pin_write_logic(&(dc_motor->dc_motor[1]), GPIO_LOW);
    }
    return ret;

}