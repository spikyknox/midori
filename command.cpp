#include "command.h" //include the declaration for this class

Command::Command(){
  
}

//<<destructor>>
Command::~Command(){/*nothing to destruct*/}

//turn the LED on
/*
void Command::getSearchBehavior(unsigned char nZone, int &leftMotorPower,int &rightMotorPower){


    switch (nZone) {

    case Z_UNKNOWN:
                      //Turn Hard Left
                      leftMotorPower   = 0; 
                      rightMotorPower  = 0;
      break;
     
    case Z_SIDE_LEFT:
                      //Turn Hard Left
                      leftMotorPower   = 0;//-30;
                      rightMotorPower  = 0;// 30;
      break;
    case Z_FRONT:
                      //Full Foward
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
      break;

    case Z_FRONT_LEFT:

                      //Turn Hard Left
                      leftMotorPower   = 0;
                      rightMotorPower  = 18;//25;
      break;


    case Z_FRONT_RIGHT:

                      //Turn Hard Left
                      leftMotorPower   = 18;//25;
                      rightMotorPower  = 0;
      break;

    case Z_SIDE_RIGHT:
                      //Turn Hard Right
                      leftMotorPower   =  0;//30;
                      rightMotorPower  =  0;//-30;
      break;

     case Z_NEAR_LEFT:
                      leftMotorPower   = 18;//25;
                      rightMotorPower  = 0;
      break;
      
     case Z_NEAR_RIGHT:
                      leftMotorPower   = 0;
                      rightMotorPower  = 18;//25;
      break;

    case Z_NEAR:
                      //leftMotorPower   = 50;
                      //rightMotorPower  = 50;

                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
      break;
      
    default: 
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
    break;
  }
}*/

// JAPAN
void Command::getSearchBehavior(unsigned char nZone, int &leftMotorPower,int &rightMotorPower){

    switch (nZone) {

    case Z_UNKNOWN:
                      //Foward
                      leftMotorPower   = 0; 
                      rightMotorPower  = 0;
      break;
      
    case Z_SIDE_LEFT:
                      //Turn Hard Left
                      leftMotorPower   = -6000;
                      rightMotorPower  =  6000;
      break;
    case Z_FRONT:
                      //Full Foward
                      leftMotorPower   = 0; //2000
                      rightMotorPower  = 0; //2000
      break;

    case Z_FRONT_LEFT:

                      leftMotorPower   = 0;
                      rightMotorPower  = 6000;
      break;


    case Z_FRONT_RIGHT:

                      //Turn Hard Left
                      leftMotorPower   = 6000;
                      rightMotorPower  = 0;
      break;

    case Z_SIDE_RIGHT:
                      //Turn Hard Right
                      leftMotorPower   =  6000;
                      rightMotorPower  =  -6000;
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
                      leftMotorPower   =  0; //4000
                      rightMotorPower  = -4000;
                      maintainValue    =  18; // * DT
                      
      break;
    case RIGHT_WL:
                      //Full Foward
                      leftMotorPower   = -4000;
                      rightMotorPower  = 0;
                      maintainValue    =  18;
      break;

    case BOTH_WL:
                      //Full Foward
                      leftMotorPower   = -4000;
                      rightMotorPower  = -4000;
                      maintainValue    =  40;
      break;

    default: 
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
                      maintainValue    = 0;
    break;
  }
 
}

