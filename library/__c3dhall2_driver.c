/*
    __c3dhall2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__c3dhall2_driver.h"
#include "__c3dhall2_hal.c"

/* ------------------------------------------------------------------- MACROS */

const uint8_t _C3DHALL2_DEF_SLAVE_ADDRESS  = 0x00;

/* Mode 1 settings */
const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_0    = 0x00;
const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_1    = 0x20;
const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_2    = 0x40;
const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_3    = 0x60;
const uint8_t _C3DHALL2_M1_INTERRUPT_ENABLE       = 0x04;
const uint8_t _C3DHALL2_M1_INTERRUPT_DISABLE      = 0x00;
const uint8_t _C3DHALL2_M1_FAST_MODE_ENABLE       = 0x02;
const uint8_t _C3DHALL2_M1_FAST_MODE_DISABLE      = 0x00;
const uint8_t _C3DHALL2_M1_LOW_POWER_MODE_ENABLE  = 0x01;
const uint8_t _C3DHALL2_M1_LOW_POWER_MODE_DISABLE = 0x00;

/* Mode 2 settings */
const uint8_t _C3DHALL2_M2_TEMPERATURE_ENABLE     = 0x00;
const uint8_t _C3DHALL2_M2_TEMPERATURE_DISABLE    = 0x80;
const uint8_t _C3DHALL2_M2_LOW_POWER_PERIOD_100ms = 0x00;
const uint8_t _C3DHALL2_M2_LOW_POWER_PERIOD_12ms  = 0x40;
const uint8_t _C3DHALL2_M2_PARITY_TEST_ENABLE     = 0x00;
const uint8_t _C3DHALL2_M2_PARITY_TEST_DISABLE    = 0x20;



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __C3DHALL2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __C3DHALL2_DRV_SPI__

void c3dhall2_spiDriverInit(T_C3DHALL2_P gpioObj, T_C3DHALL2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __C3DHALL2_DRV_I2C__

void c3dhall2_i2cDriverInit(T_C3DHALL2_P gpioObj, T_C3DHALL2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __C3DHALL2_DRV_UART__

void c3dhall2_uartDriverInit(T_C3DHALL2_P gpioObj, T_C3DHALL2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void c3dhall2_writeData(uint8_t *pBuf, uint16_t count)
{
    uint8_t *ptr = pBuf;

    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, ptr, count, END_MODE_STOP);
}

void c3dhall2_readData(uint8_t *pBuf, uint16_t count)
{
    uint8_t *ptr = pBuf;
    uint8_t start_addr = 0x00;
    
    hal_i2cStart();
    hal_i2cWrite(_slaveAddress, &start_addr, 1, END_MODE_STOP);
    hal_i2cStart();
    hal_i2cRead(_slaveAddress, ptr, count, END_MODE_STOP);
}

void c3dhall2_getAxisTempData(float *axisData, float *tempData)
{
    char readData[10];

    int16_t x_axis;
    int16_t y_axis;
    int16_t z_axis;
    volatile int16_t temp;

    c3dhall2_readData(readData, 7);
    
    /* X axis calculation */
    x_axis = readData[0];
    x_axis = x_axis << 4;
    x_axis |= ((readData[4]  >> 4 ) & 0x0F);
    if(x_axis > 2048)
    {
        x_axis = x_axis - 4096;
    }
    axisData[0] = (float)(x_axis * 0.098);
    
    /* Y axis calculation */
    y_axis = readData[1];
    y_axis = y_axis << 4;
    y_axis |= (readData[4] & 0x0F);
    if(y_axis > 2048)
    {
        y_axis = y_axis - 4096;
    }
    axisData[1] = (float)(y_axis * 0.098);
    
    /* Z axis calculation */
    z_axis = readData[2];
    z_axis = z_axis << 4;
    z_axis |= (readData[5] & 0x0F);
    if(z_axis > 2048)
    {
        z_axis = z_axis - 4096;
    }
    axisData[2] = (float)(z_axis * 0.098);
    
    /* Temperature calculation */
    temp = readData[ 3 ];
    temp = temp << 4;
    temp = temp & 0x0F00;
    temp = temp | readData[ 6 ];
    if(temp > 2048)
    {
       temp = temp - 4096;
    }
    *tempData = (temp *1.1) - 340;
}


void c3dhall2_configuration(uint8_t settings1, uint8_t settings2)
{
    uint8_t rdata_[10];
    uint8_t wdata_[10];
    uint8_t addr;
    
    addr = settings1 & 0x60;
    
    c3dhall2_readData(rdata_, 10);
    
    wdata_[0] = 0x00;
    wdata_[1] = (rdata_[7] && 0x71);
    wdata_[1] = (wdata_[1] || settings1);
    wdata_[2] = rdata_[8];
    wdata_[3] = (rdata_[9] && 0x1F);
    wdata_[3] = (wdata_[1] || settings2);

    c3dhall2_writeData(wdata_, 4);
    
}





/* -------------------------------------------------------------------------- */
/*
  __c3dhall2_driver.c

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