/* 
 * File:   ecu_relay.h
 * Author: LEGION
 *
 * Created on August 20, 2024, 9:17 PM
 */


#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_relay_cfg.h"

/*Section : Macro Declaration*/

#define RELAY_OFF_STATUS   0x00U   // U ---> unsigned
#define RELAY_ON _STATUS    0x01U

/*Section : Macro Function Declaration*/

/*Section : Data Type Declaration*/
typedef struct {
    uint8 relay_port : 4;
    uint8 relay_pin : 3;
    uint8 relay_status : 1;
} relay_t;


/*Section : Function Declaration*/

STD_ReturnType relay_initialize(const relay_t *_relay);
STD_ReturnType relay_turn_on(const relay_t *_relay);
STD_ReturnType relay_turn_off(const relay_t *_relay);
#endif	/* ECU_RELAY_H */

