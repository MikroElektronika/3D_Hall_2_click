/*
Example for 3DHall2 Click

    Date          : okt 2018.
    Author        : Katarina Perendic

Test configuration TIVA :
    
    MCU              : TM4C129XNCZAD
    Dev. Board       : EasyMx PRO v7 for TIVA ARM
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initialization driver init and configuration chip
- Application Task - (code snippet) - Reads X/Y/Z hall axis and Temperature data.
                                      All data logs on the USBUART every 3 sec.
*/

#include "Click_3DHall2_types.h"
#include "Click_3DHall2_config.h"

char demoText[ 50 ];
float XYZ_Axis[3];
float Temperature;

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_C3DHALL2_I2C_CFG[0] );
    mikrobus_logInit( _LOG_USBUART_A, 9600 );
    mikrobus_logWrite("--- System Init ----", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    c3dhall2_i2cDriverInit( (T_C3DHALL2_P)&_MIKROBUS1_GPIO, (T_C3DHALL2_P)&_MIKROBUS1_I2C, 0x5E );
    c3dhall2_configuration(_C3DHALL2_M1_I2C_SLAVE_ADDRESS_0 | _C3DHALL2_M1_INTERRUPT_DISABLE |
                           _C3DHALL2_M1_FAST_MODE_ENABLE | _C3DHALL2_M1_LOW_POWER_MODE_DISABLE,
                           _C3DHALL2_M2_TEMPERATURE_ENABLE | _C3DHALL2_M2_LOW_POWER_PERIOD_12ms |
                           _C3DHALL2_M2_PARITY_TEST_ENABLE );
}

void applicationTask()
{
    c3dhall2_getAxisTempData(&XYZ_Axis[0], &Temperature);

    mikrobus_logWrite("Axis X: ", _LOG_TEXT);
    FloatToStr(XYZ_Axis[0],demoText);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" mT", _LOG_LINE);
   
    mikrobus_logWrite("Axis Y: ", _LOG_TEXT);
    FloatToStr(XYZ_Axis[1],demoText);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" mT", _LOG_LINE);
   
    mikrobus_logWrite("Axis Z: ", _LOG_TEXT);
    FloatToStr(XYZ_Axis[2],demoText);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" mT", _LOG_LINE);
   
    mikrobus_logWrite("Temperature :", _LOG_TEXT);
    FloatToStr(Temperature,demoText);
    mikrobus_logWrite(demoText, _LOG_TEXT);
    mikrobus_logWrite(" C", _LOG_LINE);
   
    mikrobus_logWrite(" ", _LOG_LINE);
    Delay_ms(3000);
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
        applicationTask();
    }
}