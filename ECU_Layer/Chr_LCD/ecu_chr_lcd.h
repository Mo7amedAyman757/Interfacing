/* 
 * File:   ecu_chr_lcd.h
 * Author: LEGION
 *
 * Created on August 31, 2024, 2:05 PM
 */

#ifndef ECU_CHR_LCD_H
#define	ECU_CHR_LCD_H

/* Section : Includes */
#include "../../MCAL_Layer/GPIO/hal_gpio.h"
#include "ecu_chr_lcd_cfg.h"

/*Section : Macro Declaration*/
#define _LCD_CLEAR                    0x01
#define _LCD_RETURN_HOME              0x02
#define _LCD_ENTRY_MODE               0x06
#define _LCD_CURSOR_OFF_DISPLAY_ON    0x0C
#define _LCD_CURSOR_OFF_DISPLAY_OFF   0x08
#define _LCD_CURSOR_ON_DISPLAY_ON     0x0E
#define _LCD_CURSOR_ON_BLINK_ON       0x0F
#define _LCD_DISPLAY_SHIFT_RIGHT      0x1C
#define _LCD_DISPLAY_SHIFT_LEFT       0x18
#define _LCD_8BIT_MODE_2_LINE         0x38
#define _LCD_4BIT_MODE_2_LINE         0x28
#define _LCD_CGRAM_START              0x40
#define _LCD_DDRAM_START              0x80

#define ROW1 1
#define ROW2 2
#define ROW3 3
#define ROW4 4
/*Section : Macro Function Declaration*/

/*Section : Data Type Declaration*/
typedef struct {
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[4];
} chr_lcd_4bit_t;

typedef struct {
    pin_config_t lcd_rs;
    pin_config_t lcd_en;
    pin_config_t lcd_data[8];
} chr_lcd_8bit_t;
/*Section : Function Declaration*/
STD_ReturnType lcd_4bit_initialize(const chr_lcd_4bit_t *lcd);
STD_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t *lcd, uint8 command);
STD_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd, uint8 data);
STD_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 col, uint8 data);
STD_ReturnType lcd_4bit_send_string(const chr_lcd_4bit_t *lcd, uint8 *str);
STD_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 col, uint8 *str);
STD_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd, uint8 row, uint8 col, const uint8 _chr[], uint8 mem_pos);

STD_ReturnType lcd_8bit_initialize(const chr_lcd_8bit_t *lcd);
STD_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t *lcd, uint8 command);
STD_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd, uint8 data);
STD_ReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 col, uint8 data);
STD_ReturnType lcd_8bit_send_string(const chr_lcd_8bit_t *lcd, uint8 *str);
STD_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 col, uint8 *str);
STD_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd, uint8 row, uint8 col, const uint8 _chr[], uint8 mem_pos);

STD_ReturnType convert_byte_to_string(uint8 value, uint8 *str);
STD_ReturnType convert_short_to_string(uint16 value, uint8 *str);
STD_ReturnType convert_int_to_string(uint32 value, uint8 *str);
#endif	/* ECU_CHR_LCD_H */

