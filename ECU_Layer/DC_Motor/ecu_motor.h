/* 
 * File:   ecu_motor.h
 * Author: LEGION
 *
 * Created on August 22, 2024, 4:38 PM
 */

#ifndef ECU_MOTOR_H
#define	ECU_MOTOR_H


/* Section : Includes */
#include "ecu_motor_cfg.h"
#include "../../MCAL_Layer/GPIO/hal_gpio.h"

/*Section : Macro Declaration*/
#define MOTOR_ON_STATUS  0x01U
#define MOTOR_OFF_STATUS 0x00U

/*Section : Macro Function Declaration*/

/*Section : Data Type Declaration*/

typedef struct {
    pin_config_t dc_motor[2];
} dc_motor_t;

/*Section : Function Declaration*/
STD_ReturnType dc_motor_initialize(const dc_motor_t *dc_motor);
STD_ReturnType dc_motor_move_right(const dc_motor_t *dc_motor);
STD_ReturnType dc_motor_move_left(const dc_motor_t *dc_motor);
STD_ReturnType dc_motor_stop(const dc_motor_t *dc_motor);
#endif	/* ECU_MOTOR_H */

