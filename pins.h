#ifndef PINS_H
#define PINS_H

/*
  Define which pin is related to which sensor

*/

/*---------- White Line ----------*/ 



#define WL_LEFT_1  A3 // Q3     
#define WL_LEFT_2  A2 // Q4

#define WL_RIGHT_1 A0 // Q6
#define WL_RIGHT_2 A1 // Q7

/*---------- Distance Sensor ----------*/ 

// S : Side
// D : Diagonal
// F : Front

#define DIS_S_LEFT  D7 // DIS_BOT_UC1
#define DIS_F_LEFT  D8 // DIS_BOT_UC2
#define DIS_D_RIGHT D9 // DIS_BOT_UC3
#define DIS_F_RIGHT D5 // DIS_BOT_UC4
#define DIS_D_LEFT  D6 // DIS_BOT_UC5
#define DIS_S_RIGHT D4  // DIS_BOT_UC6

/*---------- ESC ----------*/ 

/*---------- Switch ----------*/ 

#define IR_1 D10

#endif
