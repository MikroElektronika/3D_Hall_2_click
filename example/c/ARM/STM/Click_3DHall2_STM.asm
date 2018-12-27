_systemInit:
;Click_3DHall2_STM.c,38 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_3DHall2_STM.c,40 :: 		mikrobus_i2cInit( _MIKROBUS1, &_C3DHALL2_I2C_CFG[0] );
MOVW	R0, #lo_addr(__C3DHALL2_I2C_CFG+0)
MOVT	R0, #hi_addr(__C3DHALL2_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_3DHall2_STM.c,41 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_3DHall2_STM.c,42 :: 		mikrobus_logWrite("--- System Init ----", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_3DHall2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,43 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_3DHall2_STM.c,44 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_3DHall2_STM.c,46 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_3DHall2_STM.c,48 :: 		c3dhall2_i2cDriverInit( (T_C3DHALL2_P)&_MIKROBUS1_GPIO, (T_C3DHALL2_P)&_MIKROBUS1_I2C, 0x5E );
MOVS	R2, #94
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_c3dhall2_i2cDriverInit+0
;Click_3DHall2_STM.c,51 :: 		_C3DHALL2_M2_TEMPERATURE_ENABLE | _C3DHALL2_M2_LOW_POWER_PERIOD_12ms |
MOVS	R0, __C3DHALL2_M2_TEMPERATURE_ENABLE
ORR	R0, R0, __C3DHALL2_M2_LOW_POWER_PERIOD_12ms
UXTB	R0, R0
;Click_3DHall2_STM.c,52 :: 		_C3DHALL2_M2_PARITY_TEST_ENABLE );
ORR	R1, R0, __C3DHALL2_M2_PARITY_TEST_ENABLE
;Click_3DHall2_STM.c,49 :: 		c3dhall2_configuration(_C3DHALL2_M1_I2C_SLAVE_ADDRESS_0 | _C3DHALL2_M1_INTERRUPT_DISABLE |
MOVS	R0, __C3DHALL2_M1_I2C_SLAVE_ADDRESS_0
ORR	R0, R0, __C3DHALL2_M1_INTERRUPT_DISABLE
UXTB	R0, R0
;Click_3DHall2_STM.c,50 :: 		_C3DHALL2_M1_FAST_MODE_ENABLE | _C3DHALL2_M1_LOW_POWER_MODE_DISABLE,
ORR	R0, R0, __C3DHALL2_M1_FAST_MODE_ENABLE
UXTB	R0, R0
ORR	R0, R0, __C3DHALL2_M1_LOW_POWER_MODE_DISABLE
;Click_3DHall2_STM.c,52 :: 		_C3DHALL2_M2_PARITY_TEST_ENABLE );
;Click_3DHall2_STM.c,50 :: 		_C3DHALL2_M1_FAST_MODE_ENABLE | _C3DHALL2_M1_LOW_POWER_MODE_DISABLE,
;Click_3DHall2_STM.c,52 :: 		_C3DHALL2_M2_PARITY_TEST_ENABLE );
BL	_c3dhall2_configuration+0
;Click_3DHall2_STM.c,53 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_3DHall2_STM.c,55 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_3DHall2_STM.c,57 :: 		c3dhall2_getAxisTempData(XYZ_Axis, &Temperature);
MOVW	R1, #lo_addr(_Temperature+0)
MOVT	R1, #hi_addr(_Temperature+0)
MOVW	R0, #lo_addr(_XYZ_Axis+0)
MOVT	R0, #hi_addr(_XYZ_Axis+0)
BL	_c3dhall2_getAxisTempData+0
;Click_3DHall2_STM.c,59 :: 		mikrobus_logWrite("Axis X: ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_3DHall2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,60 :: 		FloatToStr(XYZ_Axis[0],demoText);
MOVW	R0, #lo_addr(_XYZ_Axis+0)
MOVT	R0, #hi_addr(_XYZ_Axis+0)
LDR	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_3DHall2_STM.c,61 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,62 :: 		mikrobus_logWrite(" mT", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr3_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_3DHall2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,64 :: 		mikrobus_logWrite("Axis Y: ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr4_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_3DHall2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,65 :: 		FloatToStr(XYZ_Axis[1],demoText);
MOVW	R0, #lo_addr(_XYZ_Axis+4)
MOVT	R0, #hi_addr(_XYZ_Axis+4)
LDR	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_3DHall2_STM.c,66 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,67 :: 		mikrobus_logWrite(" mT", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr5_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_3DHall2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,69 :: 		mikrobus_logWrite("Axis Z: ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr6_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr6_Click_3DHall2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,70 :: 		FloatToStr(XYZ_Axis[2],demoText);
MOVW	R0, #lo_addr(_XYZ_Axis+8)
MOVT	R0, #hi_addr(_XYZ_Axis+8)
LDR	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_3DHall2_STM.c,71 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,72 :: 		mikrobus_logWrite(" mT", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr7_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr7_Click_3DHall2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,74 :: 		mikrobus_logWrite("Temperature :", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr8_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr8_Click_3DHall2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,75 :: 		FloatToStr(Temperature,demoText);
MOVW	R0, #lo_addr(_Temperature+0)
MOVT	R0, #hi_addr(_Temperature+0)
LDR	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_3DHall2_STM.c,76 :: 		mikrobus_logWrite(demoText, _LOG_TEXT);
MOVS	R1, #1
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,77 :: 		mikrobus_logWrite(" C", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr9_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr9_Click_3DHall2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,79 :: 		mikrobus_logWrite(" ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr10_Click_3DHall2_STM+0)
MOVT	R0, #hi_addr(?lstr10_Click_3DHall2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_3DHall2_STM.c,80 :: 		Delay_ms(3000);
MOVW	R7, #20735
MOVT	R7, #549
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_3DHall2_STM.c,81 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_3DHall2_STM.c,83 :: 		void main()
;Click_3DHall2_STM.c,85 :: 		systemInit();
BL	_systemInit+0
;Click_3DHall2_STM.c,86 :: 		applicationInit();
BL	_applicationInit+0
;Click_3DHall2_STM.c,88 :: 		while (1)
L_main4:
;Click_3DHall2_STM.c,90 :: 		applicationTask();
BL	_applicationTask+0
;Click_3DHall2_STM.c,91 :: 		}
IT	AL
BAL	L_main4
;Click_3DHall2_STM.c,92 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
