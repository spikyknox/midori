#ifndef PINS_H
#define PINS_H

/*
  Define which pin is related to which sensor

*/

/*---------- White Line ----------*/ 



#define WL_LEFT_1  14 // Q3     
#define WL_LEFT_2  15 // Q4
#define WL_LEFT_3  16 // Q5

#define WL_RIGHT_1 21 // Q6
#define WL_RIGHT_2 20 // Q7
#define WL_RIGHT_3 17 // Q8

/*---------- Distance Sensor ----------*/ 

// S : Side
// D : Diagonal
// F : Front

#define DIS_S_LEFT_B1  28 // DIS_BOT_UC1
#define DIS_F_LEFT_B2  29 // DIS_BOT_UC2
#define DIS_D_RIGHT_B3 30 // DIS_BOT_UC3
#define DIS_F_RIGHT_B4 31 // DIS_BOT_UC4
#define DIS_D_LEFT_B5  33 // DIS_BOT_UC5
#define DIS_S_RIGHT_B6 32 // DIS_BOT_UC6

/*---------- ESC ----------*/ 


#define MOTOR_LEFT  3
#define MOTOR_RIGHT 4

/*---------- Switch ----------*/ 

#define DIP_0 24
#define DIP_1 25
#define DIP_2 26
#define DIP_3 27

#define IR_1 23

#define LED 13

#endif
