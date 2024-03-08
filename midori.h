/*
    This file is part of AKA firmware.
	
	Default configuration
	
*/

#ifndef _MIDORI_H
#define _MIDORI_H

//extern millis_t previousMillisCmd;

#include "Adafruit_NeoPixel.h"

#include "pins.h"
#include "leds.h"

#include "command.h"
#include "sensors.h"

#define WHITE_LINE_THRESHOLD 3000
#define DT 5

#define STOP_MODE  0
#define AUTO_MODE  1

#define LEFT_MOTOR_CANID 106
#define RIGHT_MOTOR_CANID 105



#endif
