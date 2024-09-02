/* 
 * File:   application.h
 * Author: LEGION
 *
 * Created on August 10, 2024, 10:26 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

/* Section : Includes */
#include "ECU_Layer/ecu_layer_init.h"

/*Section : Macro Declaration*/


/*Section : Macro Function Declaration*/


/*Section : Data Type Declaration*/
extern keypad_t keypad1;
extern chr_lcd_4bit_t lcd_1;
extern chr_lcd_8bit_t lcd_2;
/*Section : Function Declaration*/
void application_initialize(void);


#endif	/* APPLICATION_H */

