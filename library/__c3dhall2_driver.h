/*
    __c3dhall2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __c3dhall2_driver.h
@brief    3DHall2 Driver
@mainpage 3DHall2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   C3DHALL2
@brief      3DHall2 Click Driver
@{

| Global Library Prefix | **C3DHALL2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **okt 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _C3DHALL2_H_
#define _C3DHALL2_H_

/** 
 * @macro T_C3DHALL2_P
 * @brief Driver Abstract type 
 */
#define T_C3DHALL2_P    const uint8_t*

/** @defgroup C3DHALL2_COMPILE Compilation Config */              /** @{ */

//  #define   __C3DHALL2_DRV_SPI__                            /**<     @macro __C3DHALL2_DRV_SPI__  @brief SPI driver selector */
   #define   __C3DHALL2_DRV_I2C__                            /**<     @macro __C3DHALL2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __C3DHALL2_DRV_UART__                           /**<     @macro __C3DHALL2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup C3DHALL2_VAR Variables */                           /** @{ */

extern const uint8_t _C3DHALL2_DEF_SLAVE_ADDRESS;

/* Mode 1 settings */
extern const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_0   ;
extern const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_1   ;
extern const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_2   ;
extern const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_3   ;
extern const uint8_t _C3DHALL2_M1_INTERRUPT_ENABLE      ;
extern const uint8_t _C3DHALL2_M1_INTERRUPT_DISABLE     ;
extern const uint8_t _C3DHALL2_M1_FAST_MODE_ENABLE      ;
extern const uint8_t _C3DHALL2_M1_FAST_MODE_DISABLE     ;
extern const uint8_t _C3DHALL2_M1_LOW_POWER_MODE_ENABLE ;
extern const uint8_t _C3DHALL2_M1_LOW_POWER_MODE_DISABLE;

/* Mode 2 settings */
extern const uint8_t _C3DHALL2_M2_TEMPERATURE_ENABLE     ;
extern const uint8_t _C3DHALL2_M2_TEMPERATURE_DISABLE    ;
extern const uint8_t _C3DHALL2_M2_LOW_POWER_PERIOD_100ms ;
extern const uint8_t _C3DHALL2_M2_LOW_POWER_PERIOD_12ms  ;
extern const uint8_t _C3DHALL2_M2_PARITY_TEST_ENABLE     ;
extern const uint8_t _C3DHALL2_M2_PARITY_TEST_DISABLE    ;
                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup C3DHALL2_INIT Driver Initialization */              /** @{ */

#ifdef   __C3DHALL2_DRV_SPI__
void c3dhall2_spiDriverInit(T_C3DHALL2_P gpioObj, T_C3DHALL2_P spiObj);
#endif
#ifdef   __C3DHALL2_DRV_I2C__
void c3dhall2_i2cDriverInit(T_C3DHALL2_P gpioObj, T_C3DHALL2_P i2cObj, uint8_t slave);
#endif
#ifdef   __C3DHALL2_DRV_UART__
void c3dhall2_uartDriverInit(T_C3DHALL2_P gpioObj, T_C3DHALL2_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void c3dhall2_gpioDriverInit(T_C3DHALL2_P gpioObj);
                                                                       /** @} */
/** @defgroup C3DHALL2_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write data in registers
 *
 * @param[in] pBuf    Buffer with data that will be written to registers starting at 0x00
 * @param[in] count   The number of data to be written
 */
void c3dhall2_writeData(uint8_t *pBuf, uint16_t count);

/**
 * @brief Functions for reads data from registers
 *
 * @param[out] pBuf   The buffer that the data from the registers will be stored
 * @param[in] count   The number of data 
 */
void c3dhall2_readData(uint8_t *pBuf, uint16_t count);

/**
 * @brief Functions for gets Hall axis data and Temperature data
 *
 * @param[out] axisData   Hall axis data in mT - (axisData[0] - X axis, axisData[1] - Y axis, axisData[2] - Z axis)
 * @param[out] tempData   Temperature data in C 
 */
void c3dhall2_getAxisTempData(float *axisData, float *tempData);

/**
 * @brief Functions for settings chip for measurement
 *
 * @param[in] settings1   Mode 1 register settings
 * @param[in] settings2   Mode 2 register settings 
 *
 * Options for settings:
 *  Mode 1 :
 *       Slave address (0,1, 2 or 3)
 *		Interrupt (Enable or Disable)
 *		Fast mode (Enable or Disable)
 *		Low power mode (Enable or Disable)
 *	Mode 2 :
 *	    Temperature (Enable or Disable)
 *		Low power period (100ms or 12ms)
 *		Parity test (Enable or Disable)
 */
void c3dhall2_configuration(uint8_t settings1, uint8_t settings2);








                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_3DHall2_STM.c
    @example Click_3DHall2_TIVA.c
    @example Click_3DHall2_CEC.c
    @example Click_3DHall2_KINETIS.c
    @example Click_3DHall2_MSP.c
    @example Click_3DHall2_PIC.c
    @example Click_3DHall2_PIC32.c
    @example Click_3DHall2_DSPIC.c
    @example Click_3DHall2_AVR.c
    @example Click_3DHall2_FT90x.c
    @example Click_3DHall2_STM.mbas
    @example Click_3DHall2_TIVA.mbas
    @example Click_3DHall2_CEC.mbas
    @example Click_3DHall2_KINETIS.mbas
    @example Click_3DHall2_MSP.mbas
    @example Click_3DHall2_PIC.mbas
    @example Click_3DHall2_PIC32.mbas
    @example Click_3DHall2_DSPIC.mbas
    @example Click_3DHall2_AVR.mbas
    @example Click_3DHall2_FT90x.mbas
    @example Click_3DHall2_STM.mpas
    @example Click_3DHall2_TIVA.mpas
    @example Click_3DHall2_CEC.mpas
    @example Click_3DHall2_KINETIS.mpas
    @example Click_3DHall2_MSP.mpas
    @example Click_3DHall2_PIC.mpas
    @example Click_3DHall2_PIC32.mpas
    @example Click_3DHall2_DSPIC.mpas
    @example Click_3DHall2_AVR.mpas
    @example Click_3DHall2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __c3dhall2_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */