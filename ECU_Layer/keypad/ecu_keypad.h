/* 
 * File:   ecu_keypad.h
 * Author: LEGION
 *
 * Created on August 26, 2024, 5:42 PM
 */

#ifndef ECU_KEYPAD_H
#define	ECU_KEYPAD_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_keypad_cfg.h"

/*Section : Macro Declaration*/
#define ECU_KEYPAD_ROW     4
#define ECU_KEYPAD_COLUMNS 4

/*Section : Macro Function Declaration*/

/*Section : Data Type Declaration*/
typedef struct {
    pin_config_t keypad_row_pins[ECU_KEYPAD_ROW];
    pin_config_t keypad_column_pins[ECU_KEYPAD_COLUMNS];
} keypad_t;

/*Section : Function Declaration*/
STD_ReturnType keypad_initialize(const keypad_t *keypad_obj);

STD_ReturnType keypad_get_value(const keypad_t *keypad_obj, uint8 *value);
#endif	/* ECU_KEYPAD_H */

