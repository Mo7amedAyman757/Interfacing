/* 
 * File:   application.c
 * Author: LEGION
 *
 * Created on August 10, 2024, 10:07 PM
 */

#include "application.h"

uint8 lcd_counter = 244;
uint8 lcd_counter_txt[4];
uint8 lcd1_counter = 0;

int main() {
    STD_ReturnType ret = E_NOK;

    application_initialize();
    ret = lcd_4bit_send_string_pos(&lcd_1, 2, 1, "Embedded Diploma");
    ret = lcd_8bit_send_string_pos(&lcd_2, 1, 1, "Loading");
    while (1) {
        for (lcd1_counter = 0; lcd1_counter <= 7; ++lcd1_counter) {

            ret = lcd_4bit_send_string_pos(&lcd_1, 1, lcd1_counter, "Hello All");
            __delay_ms(250);
            ret = lcd_4bit_send_char_data_pos(&lcd_1, 1, lcd1_counter, ' ');
        }
        ret = lcd_4bit_send_string_pos(&lcd_1, 1, 5, "            ");
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void) {

    ecu_layer_initialize();
}

