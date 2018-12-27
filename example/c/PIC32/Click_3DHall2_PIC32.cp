#line 1 "D:/Clicks_git/Number/3D_Hall_2_Click/SW/example/c/PIC32/Click_3DHall2_PIC32.c"
#line 1 "d:/clicks_git/number/3d_hall_2_click/sw/example/c/pic32/click_3dhall2_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic32/include/stdint.h"




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
#line 1 "d:/clicks_git/number/3d_hall_2_click/sw/example/c/pic32/click_3dhall2_config.h"
#line 1 "d:/clicks_git/number/3d_hall_2_click/sw/example/c/pic32/click_3dhall2_types.h"
#line 17 "d:/clicks_git/number/3d_hall_2_click/sw/example/c/pic32/click_3dhall2_config.h"
const uint32_t _C3DHALL2_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "d:/clicks_git/number/3d_hall_2_click/sw/library/__c3dhall2_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic32/include/stdint.h"
#line 75 "d:/clicks_git/number/3d_hall_2_click/sw/library/__c3dhall2_driver.h"
void c3dhall2_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 82 "d:/clicks_git/number/3d_hall_2_click/sw/library/__c3dhall2_driver.h"
void c3dhall2_gpioDriverInit( const uint8_t*  gpioObj);



void c3dhall2_writeByte(uint8_t reg, uint8_t _data);

uint8_t c3dhall2_readByte(uint8_t reg);

void c3dhall2_getAxis(int16_t *x_axis, int16_t *y_axis, int16_t *z_axis);

float c3dhall2_getTemperature();

void c3dhall2_generalReset();
#line 30 "D:/Clicks_git/Number/3D_Hall_2_Click/SW/example/c/PIC32/Click_3DHall2_PIC32.c"
int16_t X_axis;
int16_t Y_axis;
int16_t Z_axis;
float Temperature;
char demoText[ 50 ];

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




}

void applicationTask()
{
 Temperature = c3dhall2_getTemperature();
 FloatToStr(Temperature, demoText);
 mikrobus_logWrite(" Temperature :", _LOG_TEXT);
 mikrobus_logWrite(demoText, _LOG_LINE);

 Delay_1sec();
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
