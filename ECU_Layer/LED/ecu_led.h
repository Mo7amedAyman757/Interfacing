/* 
 * File:   ecu_led.h
 * Author: LEGION
 *
 * Created on August 10, 2024, 10:22 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"

/*Section : Macro Declaration*/


/*Section : Macro Function Declaration*/


/*Section : Data Type Declaration*/


/*Section : Function Declaration*/
STD_ReturnType led_initialize(const led_t *led);
STD_ReturnType led_turn_on(const led_t *led);
STD_ReturnType led_turn_off(const led_t *led);
STD_ReturnType led_turn_toggle(const led_t *led);
#endif	/* ECU_LED_H */

