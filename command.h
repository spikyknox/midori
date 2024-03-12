#ifndef COMMAND_H
#define COMMAND_H

#include "midori.h"
  
class Command {
public:
    
        Command();
        ~Command();

        void getRCBehavior(unsigned char rcState, int &leftMotorPower,int &rightMotorPower);
        void getWLBehavior(unsigned char wlState, int &leftMotorPower,int &rightMotorPower);
        void getSearchBehavior(unsigned char nZone, int &leftMotorPower,int &rightMotorPower);
        void getSearchBehaviorPunch(unsigned char nZone, int &leftMotorPower,int &rightMotorPower);
        void getWLBehavior(unsigned char wlState,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower);
        void getWLBehaviorOneWheel(unsigned char wlState,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower);

        

};
 
#endif
