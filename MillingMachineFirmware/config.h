﻿#pragma once
#include "Arduino.h"

#define DEBUG

// PINOUT

#define RX0_PIN							0   // RX PIN - DO NOT USE <- CONNECTED TO USB
#define TX0_PIN							1	// TX PIN - DO NOT USE <- CONNECTED TO USB
#define X_MAX_ENDSTOP_PIN				2   // PWM PIN
#define X_MIN_ENDSTOP_PIN				3   // PWM PIN
#define SERVO_4_PIN						4   // PWM PIN
#define SERVO_3_PIN						5   // PWM PIN // Analog In 1
#define DC_ENABLE						6   // PWM PIN
#define N_C								7   // NOT CONNECTED, DO NOT USE
#define D8_ENABLE_PIN					8   // PWM PIN
#define D9_ENABLE_PIN					9   // PWM PIN
#define D10_ENABLE_PIN					10  // PWM PIN
#define SPINDLE_SIGNAL_PIN				11  // PWM PIN
#define PS_ON_PIN						12  // PWM PIN
#define LED_PIN							13  // PWM PIN
#define Y_MIN_ENDSTOP_PIN				14  // TX3
#define Y_MAX_ENDSTOP_PIN				15  // RX3
#define UNKNOWN_PIN						16  // TX2
#define UNKNOWN_PIN						17  // RX2
#define Z_MAX_ENDSTOP_PIN				18  // TX1
#define Z_MIN_ENDSTOP_PIN				19  // RX1
#define UNKNOWN_PIN						20  // SDA
#define UNKNOWN_PIN						21  // SCL
#define N_C								22  // NOT CONNECTED, DO NOT USE
#define TABLE_FLIP_ENDSTOP_1_PIN		23
#define TABLE_ENABLE_PIN				24
#define TABLE_FLIP_ENDSTOP_2_PIN		25
#define TABLE_STEP_PIN					26
#define TABLE_HOLD_MAX_ENDSTOP_PIN		27
#define TABLE_DIR_PIN					28
#define TABLE_LEVEL_ENDSTOP_PIN			29
#define E1_ENABLE_PIN					30//e1
#define TABLE_HOLD_LEFT_ENDSTOP_4_PIN	31
#define TABLE_LEVEL_PROBE_PIN			32
#define TABLE_HOLD_LEFT_ENDSTOP_3_PIN	33
#define E1_DIR_PIN						34//e1
#define TABLE_HOLD_LEFT_ENDSTOP_2_PIN	35
#define E1_STEP_PIN						36//e1
#define TABLE_HOLD_LEFT_ENDSTOP_1_PIN	37
#define X_ENABLE_PIN					38
#define TABLE_HOLD_RIGHT_ENDSTOP_4_PIN	39
#define DC_DIR_2						40
#define TABLE_HOLD_RIGHT_ENDSTOP_3_PIN	41
#define DC_DIR_1						42
#define TABLE_HOLD_RIGHT_ENDSTOP_2_PIN	43
#define UNKNOWN_PIN						44  // PWM PIN
#define TABLE_HOLD_RIGHT_ENDSTOP_1_PIN	45  // PWM PIN
#define Y_STEP_PIN						46  // PWM PIN
#define UNKNOWN_PIN						47
#define Y_DIR_PIN						48
#define UNKNOWN_PIN						49
#define UNKNOWN_PIN						50  // MISO
#define UNKNOWN_PIN						51  // MOSI
#define UNKNOWN_PIN						52
#define UNKNOWN_PIN						53
#define X_STEP_PIN						A0  // ANALOG PIN
#define X_DIR_PIN						A1  // ANALOG PIN
#define Z_ENABLE_PIN					A2  // ANALOG PIN
#define UNKNOWN_PIN						A3  // ANALOG PIN
#define UNKNOWN_PIN						A4  // ANALOG PIN
#define UNKNOWN_PIN						A5  // ANALOG PIN
#define Z_STEP_PIN						A6  // ANALOG PIN
#define Z_DIR_PIN						A7  // ANALOG PIN
#define Y_ENABLE_PIN					A8  // ANALOG PIN
#define UNKNOWN_PIN						A9  // ANALOG PIN
#define UNKNOWN_PIN						A10 // ANALOG PIN
#define RANDOM_SEED_1_PIN				A11 // ANALOG PIN
#define RANDOM_SEED_2_PIN				A12 // ANALOG PIN
#define THERM_0_PIN						A13 // ANALOG PIN
#define THERM_1_PIN						A14 // ANALOG PIN
#define THERM_2_PIN						A15 // ANALOG PIN

// possible States

#define INIT_STATE						0
#define IDLE_STATE						1
#define EXECUTION_STATE					2
#define ERROR_STATE						3

//					PARAMETERS

// SERIAL
#define BAUD_RATE						115200
#define NO_OF_ENDSTOPS					19
#define MM_TO_INCH						0.0393700787
#define INCH_TO_MM						25.4
#define POSITION_ACCURACY				0.00001
#define POSITION_ACCURACY_INVERSE		100000
#define EEPROM_SAVE_PLACE				10
#define LEVEL_SENSOR_DELTA				1400
// DUMMY
#define DUMMY_VALUE						999999999

//					MOTOR AND MOVEMENT

//dziala
#define RPS0_25							11384//45536; 
#define RPS0_5							55536
#define RPS1							58036//60536
#define RPS1_5							62203

//nie dziala
#define RPS2							63036
#define RPS2_5							63536
#define RPS3							63869
#define RPS4							64286


#define GO_HOME_SPEED					RPS1
#define GO_HOME_SLOW_SPEED				RPS0_25
#define WORKING_SPEED					RPS0_5
#define RAPID_SPEED						RPS1//57536

#define SAFE_HEIGHT						200 // height in z axis
#define XHOME							0
#define YHOME							0
#define ZHOME							10000

//					STATIC COMMANDS

#define ROTATE_TABLE_COMMAND			"U0"
#define LOCK_BOARD_COMMAND				"U1"
#define UNLOCK_BOARD_COMMAND			"U2"
#define BED_LEVELING_COMMAND			"U3"
#define COMMUNICATION_TEST_COMMAND		"U4"
#define STANDARD_REPLY_COMMAND			"U5"
#define ERROR_COMMAND					"U6"
#define RESET_COMMAND					"U7"
#define MOVEMENT_DONE					"U8"
#define THE_SAME_COORD					"U9"
#define BEGIN_WORK_COMMAND				"U10"
#define END_WORK_COMMAND				"U11"


// kody błędów - używane przez funkcję MMComm.SetErrorState - jeśli funkcja nie posiada parametru, wysyła E0.

#define UNKNOWN_ERROR					"E0" // ogólny błąd wskazujący że coś jest nie tak. Im mniej się go użyje, tym lepiej. 
#define UNEXPECTED_STATE_ERROR			"E1" // wysłana wiadomość error lub nieogarnięta wiadomość - np. test komunikacji w stanie innym niż init.
#define UNHANDLED_STATE_ERROR			"E2" // nieznana wartość zmiennej _State
#define UNKNOWN_GCODE_ERROR				"E3" // nieznana komenda G, M lub U
#define SENSOR_ERROR					"E4" // niesprawny czujnik miedzi

//kody ostrzeżeń - nie zmieniają stanu na error, ale informują o czymś komputer.

#define WARNING							"W0" // nieznany warning.
#define INTERPRETATION_FAILED_WARNING	"W1" // błąd interpretacji G-Kodu


// BLDC

#define BLDC_MINIMUM_SPEED_VALUE		1000
#define BLDC_MAXIMUM_SPEED_VALUE		2000
#define BLDC_ACCELERATION_VALUE			1
#define BLDC_DEFAULT_SPEED				1800
#define BLDC_ACCELERATION_SPEED			10
// DC

#define DC_MINIMUM_SPEED_VALUE			-255
#define DC_MAXIMUM_SPEED_VALUE			255
#define ROTATION_TABLE_SPEED			40
#define CLOCKWISE						1
#define COUNTER_CLOCKWISE				0


// endstop array

#define X_MIN_ENDSTOP					0
#define X_MAX_ENDSTOP					1
#define Y_MIN_ENDSTOP					2
#define Y_MAX_ENDSTOP					3
#define Z_MIN_ENDSTOP					4
#define Z_MAX_ENDSTOP					5
#define TABLE_FLIP_ENDSTOP_1			6
#define TABLE_FLIP_ENDSTOP_2			7
#define TABLE_HOLD_LEFT_ENDSTOP_1		8
#define TABLE_HOLD_LEFT_ENDSTOP_2		9
#define TABLE_HOLD_LEFT_ENDSTOP_3		10
#define TABLE_HOLD_LEFT_ENDSTOP_4		11
#define TABLE_HOLD_RIGHT_ENDSTOP_1		12
#define TABLE_HOLD_RIGHT_ENDSTOP_2		13
#define TABLE_HOLD_RIGHT_ENDSTOP_3		14
#define TABLE_HOLD_RIGHT_ENDSTOP_4		15
#define TABLE_HOLD_MAX_ENDSTOP			16
#define TABLE_LEVEL_ENDSTOP				17
#define TABLE_LEVEL_PROBE				18