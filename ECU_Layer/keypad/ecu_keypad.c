/* 
 * File:   ecu_keypad.c
 * Author: LEGION
 *
 * Created on August 26, 2024, 5:42 PM
 */

#include "ecu_keypad.h"



static const uint8 btn_values [ECU_KEYPAD_ROW][ECU_KEYPAD_COLUMNS] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'#', '0', '=', '+'},
};

/**
 * 
 * @param keypad_obj
 * @return 
 */
STD_ReturnType keypad_initialize(const keypad_t *keypad_obj) {
    STD_ReturnType ret = E_OK;
    uint8 rows_counter = 0, columns_counter = 0;
    if (keypad_obj == NULL) {
        ret = E_NOK;
    } else {
        for (rows_counter = 0; rows_counter < ECU_KEYPAD_ROW; rows_counter++) {
            ret = gpio_pin_initialization(&(keypad_obj->keypad_row_pins[rows_counter]));
        }
        for (columns_counter = 0; columns_counter < ECU_KEYPAD_COLUMNS; columns_counter++) {
            ret = gpio_pin_initialization(&(keypad_obj->keypad_row_pins[rows_counter]));
        }
    }
    return ret;
}

/**
 * @param keypad_obj
 * @param value
 * @return 
 */
STD_ReturnType keypad_get_value(const keypad_t *keypad_obj, uint8 *value) {
    STD_ReturnType ret = E_OK;
    uint8 rows_counter = 0, columns_counter = 0, l_counter = 0;
    uint8 column_logic = 0;
    if ((keypad_obj == NULL) || (value == NULL)) {
        ret = E_NOK;
    } else {
        for (rows_counter = 0; rows_counter < ECU_KEYPAD_ROW; rows_counter++) {
            for (l_counter = 0; l_counter < ECU_KEYPAD_COLUMNS; l_counter++) {
                ret = gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[l_counter]), GPIO_LOW);
            }
            gpio_pin_write_logic(&(keypad_obj->keypad_row_pins[rows_counter]), GPIO_HIGH);
            __delay_ms(10);
            for (columns_counter = 0; columns_counter < ECU_KEYPAD_COLUMNS; columns_counter++) {
                ret = gpio_pin_read_logic(&(keypad_obj->keypad_column_pins[columns_counter]), &column_logic);
                if (column_logic == GPIO_HIGH) {
                    *value = btn_values [rows_counter][columns_counter];
                }
            }
        }
    }
    return ret;

}