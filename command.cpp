#include "command.h" //include the declaration for this class

Command::Command(){
  
}

//<<destructor>>
Command::~Command(){/*nothing to destruct*/}

//turn the LED on

void Command::getSearchBehaviorPunch(unsigned char nZone, int &leftMotorPower,int &rightMotorPower){


    switch (nZone) {

    case Z_UNKNOWN:
                      //Turn Hard Left
                      leftMotorPower   = 0; 
                      rightMotorPower  = 0;
      break;
     
    case Z_SIDE_LEFT:
                      //Turn Hard Left
                      leftMotorPower   = -4000;//-30;
                      rightMotorPower  = 4000;// 30;
      break;
    case Z_FRONT:
                      //Full Foward
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
      break;

    case Z_FRONT_LEFT:

                      //Turn Hard Left
                      leftMotorPower   = 0;
                      rightMotorPower  = 4000;//25;
      break;


    case Z_FRONT_RIGHT:

                      //Turn Hard Left
                      leftMotorPower   = 4000;//25;
                      rightMotorPower  = 0;
      break;

    case Z_SIDE_RIGHT:
                      //Turn Hard Right
                      leftMotorPower   =  4000;//30;
                      rightMotorPower  =  -4000;//-30;
      break;

     case Z_NEAR_LEFT:
                      leftMotorPower   = 0;//25;
                      rightMotorPower  = 4000;
      break;
      
     case Z_NEAR_RIGHT:
                      leftMotorPower   = 4000;
                      rightMotorPower  = 0;//25;
      break;

    case Z_NEAR:
                      //leftMotorPower   = 50;
                      //rightMotorPower  = 50;

                      leftMotorPower   = 18000;
                      rightMotorPower  = 18000;
      break;
      
    default: 
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
    break;
  }
}


void Command::getSearchBehavior(unsigned char nZone, int &leftMotorPower,int &rightMotorPower){

    switch (nZone) {

    case Z_UNKNOWN:
                      //Foward
                      leftMotorPower   = 0; 
                      rightMotorPower  = 0;
      break;
      
    case Z_SIDE_LEFT:
                      //Turn Hard Left
                      leftMotorPower   = -5000;
                      rightMotorPower  =  5000;
      break;
    case Z_FRONT:
                      //Full Foward
                      leftMotorPower   = 0; //2000
                      rightMotorPower  = 0; //2000
      break;

    case Z_FRONT_LEFT:

                      leftMotorPower   = 0;
                      rightMotorPower  = 5000;
      break;


    case Z_FRONT_RIGHT:

                      //Turn Hard Left
                      leftMotorPower   = 5000;
                      rightMotorPower  = 0;
      break;

    case Z_SIDE_RIGHT:
                      //Turn Hard Right
                      leftMotorPower   =  5000;
                      rightMotorPower  =  -5000;
      break;

     case Z_NEAR_LEFT:
                      leftMotorPower   = 0;
                      rightMotorPower  = 6000;
      break;
      
     case Z_NEAR_RIGHT:
                      leftMotorPower   = 6000;
                      rightMotorPower  = 0;
      break;

    case Z_NEAR:
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
      break;
      
    default: 
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
    break;
  }
}

 //turn the LED on
void Command::getWLBehavior(unsigned char wlState,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower){

    switch (wlState) {
    case LEFT_WL:
                      //Turn Hard Left
                      leftMotorPower   =  4500; //
                      rightMotorPower  = -4500;  // -6000 is working
                      maintainValue    =  20; // * DT
                      
      break;
    case RIGHT_WL:
                      //Full Foward
                      leftMotorPower   = -4500;
                      rightMotorPower  = 4500;
                      maintainValue    =  20;
      break;

    case BOTH_WL:
                      //Full Foward
                      leftMotorPower   = -7000;
                      rightMotorPower  = -7000;
                      maintainValue    =  60;
      break;

    default: 
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
                      maintainValue    = 0;
    break;
  }
 
}

 //turn the LED on
void Command::getWLBehaviorOneWheel(unsigned char wlState,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower){

    switch (wlState) {
    case LEFT_WL:
                      //Turn Hard Left
                      leftMotorPower   =  0; //
                      rightMotorPower  = -6000;  // -6000 is working
                      maintainValue    =  30; // * DT
                      
      break;
    case RIGHT_WL:
                      //Full Foward
                      leftMotorPower   = -6000;
                      rightMotorPower  = 0;
                      maintainValue    =  30;
      break;

    case BOTH_WL:
                      //Full Foward
                      leftMotorPower   = -7000;
                      rightMotorPower  = -7000;
                      maintainValue    =  60;
      break;

    default: 
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
                      maintainValue    = 0;
    break;
  }
 
}
