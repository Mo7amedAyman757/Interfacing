/* 
 * File:   ecu_seven_seg.c
 * Author: LEGION
 *
 * Created on August 25, 2024, 11:19 PM
 */


#include "ecu_seven_seg.h"

/**
 * 
 * @param segment
 * @return 
 */
STD_ReturnType seven_segment_initialize(const segment_t *segment) {
    STD_ReturnType ret = E_NOK;
    if (segment == NULL) {
        ret = E_NOK;
    } else {
        ret = gpio_pin_initialization(&(segment->segment_pins[SEGMENT_PIN0]));
        ret = gpio_pin_initialization(&(segment->segment_pins[SEGMENT_PIN1]));
        ret = gpio_pin_initialization(&(segment->segment_pins[SEGMENT_PIN2]));
        ret = gpio_pin_initialization(&(segment->segment_pins[SEGMENT_PIN3]));
    }
    return ret;
}

/**
 * 
 * @param segment
 * @param number
 * @return 
 */
STD_ReturnType seven_segment_write_number(const segment_t *segment, uint8 number) {
    STD_ReturnType ret = E_NOK;
    if ((segment == NULL) && (number > 9)) {
        ret = E_NOK;
    } else {
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PIN0]), number & 0x01);
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PIN1]), (number >> 1) & 0x01);
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PIN2]), (number >> 2) & 0x01);
        ret = gpio_pin_write_logic(&(segment->segment_pins[SEGMENT_PIN3]), (number >> 3) & 0x01);
    }
    return ret;
}