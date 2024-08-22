/* 
 * File:   application.c
 * Author: LEGION
 *
 * Created on August 10, 2024, 10:07 PM
 */


#include "application.h"

dc_motor_t dc_motor_1 = {
    .dc_motor[0].port = PORTC_INDEX,
    .dc_motor[0].pin = GPIO_PIN0,
    .dc_motor[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor[0].logic = MOTOR_OFF_STATUS,
    .dc_motor[1].port = PORTC_INDEX,
    .dc_motor[1].pin = GPIO_PIN1,
    .dc_motor[1].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor[1].logic = MOTOR_OFF_STATUS,
};

dc_motor_t dc_motor_2 = {
    .dc_motor[0].port = PORTC_INDEX,
    .dc_motor[0].pin = GPIO_PIN2,
    .dc_motor[0].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor[0].logic = MOTOR_OFF_STATUS,
    .dc_motor[1].port = PORTC_INDEX,
    .dc_motor[1].pin = GPIO_PIN3,
    .dc_motor[1].direction = GPIO_DIRECTION_OUTPUT,
    .dc_motor[1].logic = MOTOR_OFF_STATUS,
};

STD_ReturnType ret = E_OK;

int main() {

    application_initialize();

    while (1) {

        ret = dc_motor_move_right(&dc_motor_1);
        ret = dc_motor_move_right(&dc_motor_2);

        __delay_ms(2000);

        ret = dc_motor_stop(&dc_motor_1);
        ret = dc_motor_stop(&dc_motor_2);

        __delay_ms(2000);

        ret = dc_motor_move_left(&dc_motor_1);
        ret = dc_motor_move_left(&dc_motor_2);

        __delay_ms(2000);

        ret = dc_motor_stop(&dc_motor_1);
        ret = dc_motor_stop(&dc_motor_2);

        __delay_ms(2000);
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void) {

    dc_motor_initialize(&dc_motor_1);
    dc_motor_initialize(&dc_motor_2);
}

