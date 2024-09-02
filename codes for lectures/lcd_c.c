/*
 * File:   ecu_chr_lcd.c
 * Author: LEGION
 *
 * Created on August 31, 2024, 2:05 PM
 */

#include "ecu_chr_lcd.h"

static STD_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8 _data_command);
static STD_ReturnType lcd_4bits_send_enable_signal(const chr_lcd_4bit_t *lcd);
static STD_ReturnType lcd_8bits_send_enable_signal(const chr_lcd_8bit_t *lcd);
static STD_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd, uint8 row, uint8 col);
static STD_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd, uint8 row, uint8 col);

/**
 *
 * @param lcd
 * @return
 */
STD_ReturnType lcd_4bit_initialize(const chr_lcd_4bit_t *lcd)
{
    STD_ReturnType ret = E_OK;
    uint8 l_data_pins_counter = 0;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = gpio_pin_initialization(&(lcd->lcd_rs));
        ret = gpio_pin_initialization(&(lcd->lcd_en));
        for (l_data_pins_counter = 0; l_data_pins_counter < 4; l_data_pins_counter++)
        {
            ret = gpio_pin_initialization(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_4bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_4bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_4bit_send_command(lcd, _LCD_ENTRY_MODE);
        ret = lcd_4bit_send_command(lcd, _LCD_CURSOR_OFF_DISPLAY_ON);
        ret = lcd_4bit_send_command(lcd, _LCD_4BIT_MODE_2_LINE);
        ret = lcd_4bit_send_command(lcd, _LCD_DDRAM_START);
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param command
 * @return
 */
STD_ReturnType lcd_4bit_send_command(const chr_lcd_4bit_t *lcd, uint8 command)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_LOW);
        ret = lcd_send_4bits(lcd, command >> 4);
        ret = lcd_4bits_send_enable_signal(lcd);
        ret = lcd_send_4bits(lcd, command);
        ret = lcd_4bits_send_enable_signal(lcd);
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param data
 * @return
 */
STD_ReturnType lcd_4bit_send_char_data(const chr_lcd_4bit_t *lcd, uint8 data)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_HIGH);
        ret = lcd_send_4bits(lcd, data >> 4);
        ret = lcd_4bits_send_enable_signal(lcd);
        ret = lcd_send_4bits(lcd, data);
        ret = lcd_4bits_send_enable_signal(lcd);
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param col
 * @param data
 * @return
 */
STD_ReturnType lcd_4bit_send_char_data_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 col, uint8 data)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = lcd_4bit_set_cursor(lcd, row, col);
        ret = lcd_4bit_send_char_data(lcd, data);
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param str
 * @return
 */
STD_ReturnType lcd_4bit_send_string(const chr_lcd_4bit_t *lcd, uint8 *str)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {

        while (*str)
        {
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param col
 * @param str
 * @return
 */
STD_ReturnType lcd_4bit_send_string_pos(const chr_lcd_4bit_t *lcd, uint8 row, uint8 col, uint8 *str)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = lcd_4bit_set_cursor(lcd, row, col);
        while (*str)
        {
            ret = lcd_4bit_send_char_data(lcd, *str++);
        }
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param col
 * @param _chr
 * @param mem_pos
 * @return
 */
STD_ReturnType lcd_4bit_send_custom_char(const chr_lcd_4bit_t *lcd, uint8 row, uint8 col, const uint8 _chr[], uint8 mem_pos)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
    }

    return ret;
}

/**
 *
 * @param lcd
 * @return
 */
STD_ReturnType lcd_8bit_initialize(const chr_lcd_8bit_t *lcd)
{
    STD_ReturnType ret = E_OK;
    uint8 l_data_pins_counter = 0;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = gpio_pin_initialization(&(lcd->lcd_rs));
        ret = gpio_pin_initialization(&(lcd->lcd_en));
        for (l_data_pins_counter = 0; l_data_pins_counter < 8; l_data_pins_counter++)
        {
            ret = gpio_pin_initialization(&(lcd->lcd_data[l_data_pins_counter]));
        }
        __delay_ms(20);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_ms(5);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        __delay_us(150);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd, _LCD_CLEAR);
        ret = lcd_8bit_send_command(lcd, _LCD_RETURN_HOME);
        ret = lcd_8bit_send_command(lcd, _LCD_ENTRY_MODE);
        ret = lcd_8bit_send_command(lcd, _LCD_CURSOR_OFF_DISPLAY_ON);
        ret = lcd_8bit_send_command(lcd, _LCD_8BIT_MODE_2_LINE);
        ret = lcd_8bit_send_command(lcd, _LCD_DDRAM_START);
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param command
 * @return
 */
STD_ReturnType lcd_8bit_send_command(const chr_lcd_8bit_t *lcd, uint8 command)
{
    STD_ReturnType ret = E_OK;
    uint8 l_pin_counter = 0;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_LOW);
        for (l_pin_counter = 0; l_pin_counter < 8; l_pin_counter++)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]), (command >> l_pin_counter) & (uint8)0x01);
        }
        ret = lcd_8bits_send_enable_signal(lcd);
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param data
 * @return
 */
STD_ReturnType lcd_8bit_send_char_data(const chr_lcd_8bit_t *lcd, uint8 data)
{
    STD_ReturnType ret = E_OK;
    uint8 l_pin_counter = 0;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(lcd->lcd_rs), GPIO_HIGH);
        for (l_pin_counter = 0; l_pin_counter < 8; l_pin_counter++)
        {
            ret = gpio_pin_write_logic(&(lcd->lcd_data[l_pin_counter]), (data >> l_pin_counter) & (uint8)0x01);
        }
        ret = lcd_8bits_send_enable_signal(lcd);
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param row
 * @param col
 * @param data
 * @return
 */
STD_ReturnType lcd_8bit_send_char_data_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 col, uint8 data)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = lcd_8bit_set_cursor(lcd, row, col);
        ret = lcd_8bit_send_char_data(lcd, data);
    }

    return ret;
}

/**
 *
 * @param lcd
 * @param str
 * @return
 */
STD_ReturnType lcd_8bit_send_string(const chr_lcd_8bit_t *lcd, uint8 *str)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        while (*str)
        {
            ret = lcd_8bit_send_char_data(lcd, *str++);
        }
    }

    return ret;
}

STD_ReturnType lcd_8bit_send_string_pos(const chr_lcd_8bit_t *lcd, uint8 row, uint8 col, uint8 *str)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
        ret = lcd_8bit_set_cursor(lcd, row, col);
        while (*str)
        {
            ret = lcd_8bit_send_char_data(lcd, *str++);
        }
    }

    return ret;
}

STD_ReturnType lcd_8bit_send_custom_char(const chr_lcd_8bit_t *lcd, uint8 row, uint8 col, const uint8 _chr[], uint8 mem_pos)
{
    STD_ReturnType ret = E_OK;
    if (NULL == lcd)
    {
        ret = E_NOK;
    }
    else
    {
    }

    return ret;
}

void convert_byte_to_string(uint8 value, uint8 *str)
{
}

void convert_short_to_string(uint16 value, uint8 *str)
{
}

void convert_int_to_string(uint32 value, uint8 *str)
{
}

STD_ReturnType lcd_send_4bits(const chr_lcd_4bit_t *lcd, uint8 _data_command)
{
    STD_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_data[0]), (_data_command >> 0) & (uint8)0x01);
    ret = gpio_pin_write_logic(&(lcd->lcd_data[1]), (_data_command >> 1) & (uint8)0x01);
    ret = gpio_pin_write_logic(&(lcd->lcd_data[2]), (_data_command >> 2) & (uint8)0x01);
    ret = gpio_pin_write_logic(&(lcd->lcd_data[3]), (_data_command >> 3) & (uint8)0x01);
    return ret;
}

STD_ReturnType lcd_4bits_send_enable_signal(const chr_lcd_4bit_t *lcd)
{
    STD_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_LOW);
    return ret;
}

STD_ReturnType lcd_8bits_send_enable_signal(const chr_lcd_8bit_t *lcd)
{
    STD_ReturnType ret = E_OK;
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_HIGH);
    __delay_us(5);
    ret = gpio_pin_write_logic(&(lcd->lcd_en), GPIO_LOW);
    return ret;
}

STD_ReturnType lcd_4bit_set_cursor(const chr_lcd_4bit_t *lcd, uint8 row, uint8 col)
{
    STD_ReturnType ret = E_OK;
    col--;
    switch (row)
    {
    case ROW1:
        ret = lcd_4bit_send_command(lcd, (0x80 + col));
        break;
    case ROW2:
        ret = lcd_4bit_send_command(lcd, (0xC0 + col));
        break;
        // case ROW3: ret = lcd_8bit_send_command(lcd, (0x94 + col));
        //   break;
        // case ROW4: ret = lcd_8bit_send_command(lcd, (0xD0 + col));
        //   break;
    }
}

STD_ReturnType lcd_8bit_set_cursor(const chr_lcd_8bit_t *lcd, uint8 row, uint8 col)
{
    STD_ReturnType ret = E_OK;
    col--;
    switch (row)
    {
    case ROW1:
        ret = lcd_8bit_send_command(lcd, (0x80 + col));
        break;
    case ROW2:
        ret = lcd_8bit_send_command(lcd, (0xC0 + col));
        break;
        // case ROW3: ret = lcd_8bit_send_command(lcd, (0x94 + col));
        //   break;
        // case ROW4: ret = lcd_8bit_send_command(lcd, (0xD0 + col));
        //   break;
    }
}