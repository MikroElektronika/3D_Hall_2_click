![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# 3DHall2 Click

- **CIC Prefix**  : C3DHALL2
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : okt 2018.

---

### Software Support

We provide a library for the 3DHall2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/2592/3d-hall-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus driver and drivers that offer a choice for writing data in register and reads data from register.
The library includes function for read hall X/Y/Z axis data, and temperature data.


Key functions :

- ``` void c3dhall2_getAxisTempData(float *axisData, float *tempData) ``` - Functions for gets Hall axis data and Temperature data
- ``` void c3dhall2_configuration(uint8_t settings1, uint8_t settings2) ``` - Functions for settings chip for measurement

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes I2C module
- Application Initialization - Initialization driver init and configuration chip
- Application Task - (code snippet) - Reads X/Y/Z hall axis and Temperature data.
                                      All data logs on the USBUART every 3 sec.


```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2592/3d-hall-2-click) page.

Other mikroE Libraries used in the example:

- I2C

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
