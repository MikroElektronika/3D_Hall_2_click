_systemInit:
;Click_3DHall2_MSP.c,36 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_3DHall2_MSP.c,38 :: 		mikrobus_i2cInit( _MIKROBUS1, &_C3DHALL2_I2C_CFG[0] );
MOVW	R0, #lo_addr(__C3DHALL2_I2C_CFG+0)
MOVT	R0, #hi_addr(__C3DHALL2_I2C_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_i2cInit+0
;Click_3DHall2_MSP.c,39 :: 		mikrobus_logInit( _MIKROBUS2, 9600 );
MOVW	R1, #9600
MOVS	R0, #1
BL	_mikrobus_logInit+0
;Click_3DHall2_MSP.c,40 :: 		mikrobus_logWrite("--- System Init ----", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_3DHall2_MSP+0)
MOVT	R0, #hi_addr(?lstr1_Click_3DHall2_MSP+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_3DHall2_MSP.c,41 :: 		Delay_ms( 100 );
MOVW	R7, #20349
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_3DHall2_MSP.c,42 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_3DHall2_MSP.c,44 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_3DHall2_MSP.c,46 :: 		c3dhall2_i2cDriverInit( (T_C3DHALL2_P)&_MIKROBUS1_GPIO, (T_C3DHALL2_P)&_MIKROBUS1_I2C, 0x5E );
MOVS	R2, #94
MOVW	R1, #lo_addr(__MIKROBUS1_I2C+0)
MOVT	R1, #hi_addr(__MIKROBUS1_I2C+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_c3dhall2_i2cDriverInit+0
;Click_3DHall2_MSP.c,47 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_3DHall2_MSP.c,49 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_3DHall2_MSP.c,51 :: 		Temperature = c3dhall2_getTemperature();
BL	_c3dhall2_getTemperature+0
MOVW	R0, #lo_addr(_Temperature+0)
MOVT	R0, #hi_addr(_Temperature+0)
VSTR	#1, S0, [R0, #0]
;Click_3DHall2_MSP.c,52 :: 		FloatToStr(Temperature, demoText);
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_FloatToStr+0
;Click_3DHall2_MSP.c,53 :: 		mikrobus_logWrite(" Temperature :", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr2_Click_3DHall2_MSP+0)
MOVT	R0, #hi_addr(?lstr2_Click_3DHall2_MSP+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_3DHall2_MSP.c,54 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_3DHall2_MSP.c,56 :: 		Delay_ms( 1000 );
MOVW	R7, #6909
MOVT	R7, #183
NOP
NOP
L_applicationTask2:
SUBS	R7, R7, #1
BNE	L_applicationTask2
NOP
NOP
NOP
;Click_3DHall2_MSP.c,57 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_3DHall2_MSP.c,59 :: 		void main()
SUB	SP, SP, #4
;Click_3DHall2_MSP.c,61 :: 		systemInit();
BL	_systemInit+0
;Click_3DHall2_MSP.c,62 :: 		applicationInit();
BL	_applicationInit+0
;Click_3DHall2_MSP.c,64 :: 		while (1)
L_main4:
;Click_3DHall2_MSP.c,66 :: 		applicationTask();
BL	_applicationTask+0
;Click_3DHall2_MSP.c,67 :: 		}
IT	AL
BAL	L_main4
;Click_3DHall2_MSP.c,68 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
