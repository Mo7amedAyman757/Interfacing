/* 
 * File:   ecu_button.c
 * Author: LEGION
 *
 * Created on August 18, 2024, 1:27 PM
 */

#include "ecu_button.h"

/**
 * 
 * @param btn
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
STD_ReturnType button_initialize(const button_t *btn) {
    STD_ReturnType ret = E_OK;
    if (NULL == btn) {
        ret = E_NOK;
    } else {
        ret = gpio_pin_direction_initialization(&(btn->button_pin));
    }
    return ret;
}

/**
 * 
 * @param btn
 * @param btn_state
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
STD_ReturnType button_read_state(const button_t *btn, button_state_t *btn_state) {

    logic_t Pin_Logic_Status = GPIO_LOW;
    STD_ReturnType ret = E_OK;
    if ((NULL == btn) || (NULL == btn_state)) {
        ret = E_NOK;
    } else {
        gpio_pin_read_logic(&(btn->button_pin), &Pin_Logic_Status);
        if (BUTTON_ACTIVE_HIGH == btn->button_connection) {
            if (GPIO_HIGH == Pin_Logic_Status) {
                *btn_state = BUTTON_PRESSED;
            } else {
                *btn_state = BUTTON_RELEASED;
            }
        } else if (BUTTON_ACTIVE_LOW == btn->button_connection) {
            if (GPIO_HIGH == Pin_Logic_Status) {
                *btn_state = BUTTON_RELEASED;
            } else {
                *btn_state = BUTTON_PRESSED;
            }
        }
    }
    return ret;

}