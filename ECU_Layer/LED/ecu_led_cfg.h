/* 
 * File:   ecu_led_cfg.h
 * Author: LEGION
 *
 * Created on August 16, 2024, 2:40 PM
 */

#ifndef ECU_LED_CFG_H
#define	ECU_LED_CFG_H

/* Section : Includes */


/*Section : Macro Declaration*/


/*Section : Macro Function Declaration*/

/*Section : Data Type Declaration*/
typedef enum {
    LED_OFF,
    LED_ON
} led_status;

typedef struct {
    uint8 port_name : 4;
    uint8 pin : 3;
    uint8 led_status : 1;
} led_t;

/*Section : Function Declaration*/


#endif	/* ECU_LED_CFG_H */

