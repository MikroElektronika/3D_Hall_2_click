#line 1 "D:/Clicks_git/Number/3D_Hall_2_Click/SW/example/c/ARM/STM/Click_3DHall2_STM.c"
#line 1 "d:/clicks_git/number/3d_hall_2_click/sw/example/c/arm/stm/click_3dhall2_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "d:/clicks_git/number/3d_hall_2_click/sw/example/c/arm/stm/click_3dhall2_config.h"
#line 1 "d:/clicks_git/number/3d_hall_2_click/sw/example/c/arm/stm/click_3dhall2_types.h"
#line 19 "d:/clicks_git/number/3d_hall_2_click/sw/example/c/arm/stm/click_3dhall2_config.h"
const uint32_t _C3DHALL2_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/number/3d_hall_2_click/sw/library/__c3dhall2_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 57 "d:/clicks_git/number/3d_hall_2_click/sw/library/__c3dhall2_driver.h"
extern const uint8_t _C3DHALL2_DEF_SLAVE_ADDRESS;


extern const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_0 ;
extern const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_1 ;
extern const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_2 ;
extern const uint8_t _C3DHALL2_M1_I2C_SLAVE_ADDRESS_3 ;
extern const uint8_t _C3DHALL2_M1_INTERRUPT_ENABLE ;
extern const uint8_t _C3DHALL2_M1_INTERRUPT_DISABLE ;
extern const uint8_t _C3DHALL2_M1_FAST_MODE_ENABLE ;
extern const uint8_t _C3DHALL2_M1_FAST_MODE_DISABLE ;
extern const uint8_t _C3DHALL2_M1_LOW_POWER_MODE_ENABLE ;
extern const uint8_t _C3DHALL2_M1_LOW_POWER_MODE_DISABLE;


extern const uint8_t _C3DHALL2_M2_TEMPERATURE_ENABLE ;
extern const uint8_t _C3DHALL2_M2_TEMPERATURE_DISABLE ;
extern const uint8_t _C3DHALL2_M2_LOW_POWER_PERIOD_100ms ;
extern const uint8_t _C3DHALL2_M2_LOW_POWER_PERIOD_12ms ;
extern const uint8_t _C3DHALL2_M2_PARITY_TEST_ENABLE ;
extern const uint8_t _C3DHALL2_M2_PARITY_TEST_DISABLE ;
#line 90 "d:/clicks_git/number/3d_hall_2_click/sw/library/__c3dhall2_driver.h"
void c3dhall2_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 97 "d:/clicks_git/number/3d_hall_2_click/sw/library/__c3dhall2_driver.h"
void c3dhall2_gpioDriverInit( const uint8_t*  gpioObj);



void c3dhall2_writeData(uint8_t *pBuf, uint16_t count);

void c3dhall2_readData(uint8_t *pBuf, uint16_t count);

void c3dhall2_getAxisTempData(float *axisData, float *tempData);

void c3dhall2_configuration(uint8_t settings1, uint8_t settings2);
#line 33 "D:/Clicks_git/Number/3D_Hall_2_Click/SW/example/c/ARM/STM/Click_3DHall2_STM.c"
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
 c3dhall2_i2cDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_I2C, 0x5E );
 c3dhall2_configuration(_C3DHALL2_M1_I2C_SLAVE_ADDRESS_0 | _C3DHALL2_M1_INTERRUPT_DISABLE |
 _C3DHALL2_M1_FAST_MODE_ENABLE | _C3DHALL2_M1_LOW_POWER_MODE_DISABLE,
 _C3DHALL2_M2_TEMPERATURE_ENABLE | _C3DHALL2_M2_LOW_POWER_PERIOD_12ms |
 _C3DHALL2_M2_PARITY_TEST_ENABLE );
}

void applicationTask()
{
 c3dhall2_getAxisTempData(XYZ_Axis, &Temperature);

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
