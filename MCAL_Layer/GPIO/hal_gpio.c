/* 
 * File:   hal_gpio.c
 * Author: LEGION
 *
 * Created on August 10, 2024, 10:12 PM
 */

#include "hal_gpio.h"
/*Reference to the data direction control register*/
volatile uint8 *tris_registers[] = {&TRISA, &TRISB, &TRISC, &TRISD, &TRISE};
/*Reference to the data latch register (read and write to data latch)*/
volatile uint8 *lat_registers[] = {&LATA, &LATB, &LATC, &LATD, &LATE};
/*Reference to the port status register*/
volatile uint8 *port_registers[] = {&PORTA, &PORTB, &PORTC, &PORTD, &PORTE};

/**
 *  
 * @param _pin_config pointer to configuration @ref pin_config_t 
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_pin_direction_initialization(const pin_config_t *pin_config) {
    STD_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)) {
        ret = E_NOK;
    } else {
        switch (pin_config->direction) {
            case GPIO_DIRECTION_OUTPUT:
                CLEAR_BIT(*tris_registers[pin_config->port], pin_config->pin);
                break;
            case GPIO_DIRECTION_INPUT:
                SET_BIT(*tris_registers[pin_config->port], pin_config->pin);
                break;
            default: ret = E_NOK;
        }
    }
    return ret;
}
#endif
/**
 * @breif
 * @param pin_config pointer to configuration 
 * @param direction_status
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_pin_direction_status(const pin_config_t *pin_config, direction_t *direction_status) {
    STD_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (NULL == direction_status) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)) {
        ret = E_NOK;
    } else {
        *direction_status = READ_BIT(*tris_registers[pin_config->port], pin_config->pin);
    }
    return ret;
}
#endif
/**
 * @breif
 * @param pin_config pointer to configuration 
 * @param logic_status
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_pin_write_logic(const pin_config_t *pin_config, logic_t logic) {
    STD_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)) {
        ret = E_NOK;
    } else {
        switch (logic) {
            case GPIO_LOW:
                CLEAR_BIT(*lat_registers[pin_config->port], pin_config->pin);
                break;
            case GPIO_HIGH:
                SET_BIT(*lat_registers[pin_config->port], pin_config->pin);
                break;
            default:
                ret = E_NOK;
        }
    }
    return ret;
}
#endif
/**
 * @breif
 * @param pin_config pointer to configuration 
 * @param logic_status
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_pin_read_logic(const pin_config_t *pin_config, logic_t *logic_status) {
    STD_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (NULL == logic_status) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)) {
        ret = E_NOK;
    } else {
        *logic_status = READ_BIT(*port_registers[pin_config->port], pin_config->pin);
    }
    return ret;
}
#endif
/**
 * @breif
 * @param pin_config pointer to configuration 
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_pin_toggle_logic(const pin_config_t *pin_config) {
    STD_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)) {
        ret = E_NOK;
    } else {
        TOGGLE_BIT(*port_registers[pin_config->port], pin_config->pin);
    }
    return ret;
}
#endif
/**
 * @breif
 * @param _pin_config pointer to configuration 
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
#if GPIO_PORT_PIN_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_pin_initialization(const pin_config_t *pin_config) {
    STD_ReturnType ret = E_OK;
    if ((NULL == pin_config) || (pin_config->pin > PORT_PIN_MAX_NUMBER - 1)) {
        ret = E_NOK;
    } else {
        gpio_pin_direction_initialization(pin_config);
        gpio_pin_write_logic(pin_config, pin_config->logic);
    }
    return ret;
}
#endif
/**
 * @breif
 * @param port
 * @param direction
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_port_direction_initialization(port_index_t port, uint8 direction) {
    STD_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1) {
        ret = E_NOK;
    } else {
        *tris_registers[port] = direction;
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param direction_status
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_port_direction_status(port_index_t port, uint8 *direction_status) {
    STD_ReturnType ret = E_OK;
    if ((port > PORT_MAX_NUMBER - 1) || (NULL == direction_status)) {
        ret = E_NOK;
    } else {
        *direction_status = *tris_registers[port];
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed 
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_port_write_logic(port_index_t port, uint8 logic) {
    STD_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1) {
        ret = E_NOK;
    } else {
        *lat_registers[port] = logic;
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @param logic
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed 
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_port_read_logic(port_index_t port, uint8 *logic) {
    STD_ReturnType ret = E_OK;
    if ((port > PORT_MAX_NUMBER - 1)) {
        ret = E_NOK;
    } else {
        *logic = *lat_registers[port];
    }
    return ret;
}
#endif
/**
 * 
 * @param port
 * @return Status of function
 *         (E_OK): function success
 *         (E_NOK): function failed
 */
#if GPIO_PORT_CONFIGURATIONS == CONFIG_ENABLE

STD_ReturnType gpio_port_toggle_logic(port_index_t port) {
    STD_ReturnType ret = E_OK;
    if (port > PORT_MAX_NUMBER - 1) {
        ret = E_NOK;
    } else {
        *lat_registers[port] ^= PORTC_MASK;
    }
    return ret;
}
#endif