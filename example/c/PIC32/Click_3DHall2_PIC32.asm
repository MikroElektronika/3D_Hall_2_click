_systemInit:
;Click_3DHall2_PIC32.c,36 :: 		void systemInit()
ADDIU	SP, SP, -12
SW	RA, 0(SP)
;Click_3DHall2_PIC32.c,38 :: 		mikrobus_i2cInit( _MIKROBUS1, &_C3DHALL2_I2C_CFG[0] );
SW	R25, 4(SP)
SW	R26, 8(SP)
LUI	R2, hi_addr(__C3DHALL2_I2C_CFG+0)
ORI	R2, R2, lo_addr(__C3DHALL2_I2C_CFG+0)
MOVZ	R26, R2, R0
MOVZ	R25, R0, R0
JAL	_mikrobus_i2cInit+0
NOP	
;Click_3DHall2_PIC32.c,39 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
ORI	R26, R0, 9600
ORI	R25, R0, 32
JAL	_mikrobus_logInit+0
NOP	
;Click_3DHall2_PIC32.c,40 :: 		mikrobus_logWrite("--- System Init ----", _LOG_LINE);
ORI	R26, R0, 2
LUI	R25, hi_addr(?lstr1_Click_3DHall2_PIC32+0)
ORI	R25, R25, lo_addr(?lstr1_Click_3DHall2_PIC32+0)
JAL	_mikrobus_logWrite+0
NOP	
;Click_3DHall2_PIC32.c,41 :: 		Delay_ms( 100 );
LUI	R24, 40
ORI	R24, R24, 45226
L_systemInit0:
ADDIU	R24, R24, -1
BNE	R24, R0, L_systemInit0
NOP	
;Click_3DHall2_PIC32.c,42 :: 		}
L_end_systemInit:
LW	R26, 8(SP)
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 12
JR	RA
NOP	
; end of _systemInit
_applicationInit:
;Click_3DHall2_PIC32.c,44 :: 		void applicationInit()
ADDIU	SP, SP, -16
SW	RA, 0(SP)
;Click_3DHall2_PIC32.c,46 :: 		c3dhall2_i2cDriverInit( (T_C3DHALL2_P)&_MIKROBUS1_GPIO, (T_C3DHALL2_P)&_MIKROBUS1_I2C, 0x5E );
SW	R25, 4(SP)
SW	R26, 8(SP)
SW	R27, 12(SP)
ORI	R27, R0, 94
LUI	R26, hi_addr(__MIKROBUS1_I2C+0)
ORI	R26, R26, lo_addr(__MIKROBUS1_I2C+0)
LUI	R25, hi_addr(__MIKROBUS1_GPIO+0)
ORI	R25, R25, lo_addr(__MIKROBUS1_GPIO+0)
JAL	_c3dhall2_i2cDriverInit+0
NOP	
;Click_3DHall2_PIC32.c,51 :: 		}
L_end_applicationInit:
LW	R27, 12(SP)
LW	R26, 8(SP)
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 16
JR	RA
NOP	
; end of _applicationInit
_applicationTask:
;Click_3DHall2_PIC32.c,53 :: 		void applicationTask()
ADDIU	SP, SP, -12
SW	RA, 0(SP)
;Click_3DHall2_PIC32.c,55 :: 		Temperature = c3dhall2_getTemperature();
SW	R25, 4(SP)
SW	R26, 8(SP)
JAL	_c3dhall2_getTemperature+0
NOP	
SW	R2, Offset(_Temperature+0)(GP)
;Click_3DHall2_PIC32.c,56 :: 		FloatToStr(Temperature, demoText);
LUI	R26, hi_addr(_demoText+0)
ORI	R26, R26, lo_addr(_demoText+0)
MOVZ	R25, R2, R0
JAL	_FloatToStr+0
NOP	
;Click_3DHall2_PIC32.c,57 :: 		mikrobus_logWrite(" Temperature :", _LOG_TEXT);
ORI	R26, R0, 1
LUI	R25, hi_addr(?lstr2_Click_3DHall2_PIC32+0)
ORI	R25, R25, lo_addr(?lstr2_Click_3DHall2_PIC32+0)
JAL	_mikrobus_logWrite+0
NOP	
;Click_3DHall2_PIC32.c,58 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
ORI	R26, R0, 2
LUI	R25, hi_addr(_demoText+0)
ORI	R25, R25, lo_addr(_demoText+0)
JAL	_mikrobus_logWrite+0
NOP	
;Click_3DHall2_PIC32.c,60 :: 		Delay_1sec();
JAL	_Delay_1sec+0
NOP	
;Click_3DHall2_PIC32.c,61 :: 		}
L_end_applicationTask:
LW	R26, 8(SP)
LW	R25, 4(SP)
LW	RA, 0(SP)
ADDIU	SP, SP, 12
JR	RA
NOP	
; end of _applicationTask
_main:
;Click_3DHall2_PIC32.c,63 :: 		void main()
ADDIU	SP, SP, -4
;Click_3DHall2_PIC32.c,65 :: 		systemInit();
JAL	_systemInit+0
NOP	
;Click_3DHall2_PIC32.c,66 :: 		applicationInit();
JAL	_applicationInit+0
NOP	
;Click_3DHall2_PIC32.c,68 :: 		while (1)
L_main2:
;Click_3DHall2_PIC32.c,70 :: 		applicationTask();
JAL	_applicationTask+0
NOP	
;Click_3DHall2_PIC32.c,71 :: 		}
J	L_main2
NOP	
;Click_3DHall2_PIC32.c,72 :: 		}
L_end_main:
L__main_end_loop:
J	L__main_end_loop
NOP	
; end of _main
