#include "command.h" //include the declaration for this class

Command::Command(){
  
}

//<<destructor>>
Command::~Command(){/*nothing to destruct*/}

//turn the LED on

void Command::getSearchBehaviorPunch(unsigned char nZone,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower){

    maintainValue = 0;

    switch (nZone) {

    case Z_UNKNOWN:
                      //Turn Hard Left
                      leftMotorPower   = 4000; 
                      rightMotorPower  = 4000;
      break;
     
    case Z_SIDE_LEFT:
                      //Turn Hard Left
                      leftMotorPower   = -5000;//-30;
                      rightMotorPower  = 5000;// 30;
                      maintainValue = 40;
      break;
    case Z_FRONT:
                      //Full Foward
                      leftMotorPower   = 6500;
                      rightMotorPower  = 6500;
      break;

    case Z_FRONT_LEFT:

                      //Turn Hard Left
                      leftMotorPower   = 0;
                      rightMotorPower  = 5000;//25;

      break;

    case Z_FRONT_RIGHT:

                      //Turn Hard Left
                      leftMotorPower   = 5000;//25;
                      rightMotorPower  = 0;
      break;

    case Z_SIDE_RIGHT:
                      //Turn Hard Right
                      leftMotorPower   =  5000;//30;
                      rightMotorPower  =  -5000;//-30;
                      maintainValue = 40;
      break;

     case Z_NEAR_LEFT:
                      leftMotorPower   = 0;//25;
                      rightMotorPower  = 5000;
      break;
      
     case Z_NEAR_RIGHT:
                      leftMotorPower   = 5000;
                      rightMotorPower  = 0;//25;
      break;

    case Z_NEAR:
                      leftMotorPower   = 18000;
                      rightMotorPower  = 18000;
      break;
      
    default: 
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
    break;
  }
}

void Command::getSearchBehaviorSeek(unsigned char nZone,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower){


    switch (nZone) {

    case Z_UNKNOWN:
                      //Turn Hard Left
                      leftMotorPower   = 0; 
                      rightMotorPower  = 0;
      break;
     
    case Z_SIDE_LEFT:
                      //Turn Hard Left
                      leftMotorPower   = -5000;//-30;
                      rightMotorPower  = 5000;// 30;
                      maintainValue = 40;
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
                      leftMotorPower   =  5000;//30;
                      rightMotorPower  =  -5000;//-30;
                      maintainValue = 40;
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
                      leftMotorPower   = 3000;
                      rightMotorPower  = 3000;
      break;
      
    default: 
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
    break;
  }
}


void Command::getSearchBehavior(unsigned char nZone,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower){

    switch (nZone) {

    case Z_UNKNOWN:
                      //Foward
                      leftMotorPower   = 6000; 
                      rightMotorPower  = 6000;
      break;
      
    case Z_SIDE_LEFT:
                      //Turn Hard Left
                      leftMotorPower   = -5000;
                      rightMotorPower  =  5000;
                      maintainValue = 40;
      break;
    case Z_FRONT:
                      //Full Foward
                      leftMotorPower   = 8000; //2000
                      rightMotorPower  = 8000; //2000
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
                      maintainValue = 40;
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
                      leftMotorPower   =  5000; //
                      rightMotorPower  = -5000;  // -6000 is working
                      maintainValue    =  30; //  * 20 at 5 DT
                      
      break;
    case RIGHT_WL:
                      //Full Foward
                      leftMotorPower   = -5000;
                      rightMotorPower  = 5000;
                      maintainValue    =  30; // * 20 at 5 DT
      break;

    case BOTH_WL:
                      //Full Foward
                      leftMotorPower   = -5000;
                      rightMotorPower  = -6000;
                      maintainValue    =  100; // * 20 at 5 DT
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
                      maintainValue    =  150; // * 30 at 5 DT
                      
      break;
    case RIGHT_WL:
                      //Full Foward
                      leftMotorPower   = -6000;
                      rightMotorPower  = 0;
                      maintainValue    =  150;    //30 at 5 DT
      break;

    case BOTH_WL:
                      //Full Foward
                      leftMotorPower   = -7000;
                      rightMotorPower  = -7000;
                      maintainValue    =  150;  //60 at 5 DT
      break;

    default: 
                      leftMotorPower   = 0;
                      rightMotorPower  = 0;
                      maintainValue    = 0;
    break;
  }
 
}
