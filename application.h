/* 
 * File:   application.h
 * Author: LEGION
 *
 * Created on August 10, 2024, 10:26 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "ECU_Layer/LED/ecu_led.h"
#include "ECU_Layer/button/ecu_button.h"
#include "ECU_Layer/Relay/ecu_relay.h"
#include "ECU_Layer/DC_Motor/ecu_motor.h"
#include "ECU_Layer/7_segment/ecu_seven_seg.h"
/*Section : Macro Declaration*/

#define _XTAL_FREQ 8000000UL
/*Section : Macro Function Declaration*/


/*Section : Data Type Declaration*/


/*Section : Function Declaration*/
void application_initialize(void);


#endif	/* APPLICATION_H */

