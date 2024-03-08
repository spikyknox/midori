#include "sensors.h" //include the declaration for this class

Sensors::Sensors(){
 
    //White Line  pin as input
  pinMode(WL_LEFT_1,  INPUT);
  pinMode(WL_LEFT_2,  INPUT);
  pinMode(WL_RIGHT_1, INPUT);
  pinMode(WL_RIGHT_2, INPUT);
    
    //Distance Sensors  pin as input
    
  pinMode(DIS_S_LEFT,  INPUT);
  pinMode(DIS_F_LEFT,  INPUT);
  pinMode(DIS_D_RIGHT, INPUT);
  pinMode(DIS_F_RIGHT, INPUT);
  pinMode(DIS_D_LEFT,  INPUT);
  pinMode(DIS_S_RIGHT, INPUT);

}

//<<destructor>>
Sensors::~Sensors(){/*nothing to destruct*/}

//turn the LED on
unsigned char Sensors::getDistanceState(){
  
  unsigned char currentZone;
  
  currentZone = Z_UNKNOWN;
  
  if(!digitalRead(DIS_S_LEFT))  currentZone = Z_SIDE_LEFT;
  if(!digitalRead(DIS_S_RIGHT)) currentZone = Z_SIDE_RIGHT;
    
  if(!digitalRead(DIS_D_RIGHT) || !digitalRead(DIS_F_RIGHT)) currentZone = Z_FRONT_RIGHT;
  if(!digitalRead(DIS_D_LEFT) &&  !digitalRead(DIS_F_RIGHT)) currentZone = Z_NEAR_RIGHT;
  
  if(!digitalRead(DIS_F_LEFT) ||  !digitalRead(DIS_D_LEFT))  currentZone =  Z_FRONT_LEFT;
  if(!digitalRead(DIS_F_LEFT) &&  !digitalRead(DIS_D_RIGHT)) currentZone =  Z_NEAR_LEFT;

  if(!digitalRead(DIS_D_LEFT) &&  !digitalRead(DIS_F_RIGHT)) currentZone =  Z_FRONT_RIGHT;
  if(!digitalRead(DIS_F_LEFT) &&  !digitalRead(DIS_D_RIGHT)) currentZone =  Z_FRONT_LEFT;
  
  if(!digitalRead(DIS_F_LEFT) &&  !digitalRead(DIS_F_RIGHT)) currentZone = Z_FRONT;  
  if(!digitalRead(DIS_D_LEFT) &&  !digitalRead(DIS_D_RIGHT)) currentZone = Z_NEAR;

  return currentZone;
}

unsigned char Sensors::getWLState(){
  
  unsigned char currentState = NO_WL;

  // OR ou AND pour les WL

  if( analogRead(WL_LEFT_1) < WHITE_LINE_THRESHOLD || analogRead(WL_LEFT_2) < WHITE_LINE_THRESHOLD)   currentState = LEFT_WL;
  if( analogRead(WL_RIGHT_1) < WHITE_LINE_THRESHOLD || analogRead(WL_RIGHT_2) < WHITE_LINE_THRESHOLD)
  {  
    if(currentState == LEFT_WL)
    {
      currentState = BOTH_WL;
    }else
    {
      currentState = RIGHT_WL;
    }
  }

   return currentState;
}




