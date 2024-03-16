#ifndef COMMAND_H
#define COMMAND_H

#include "midori.h"
  
class Command {
public:
    
        Command();
        ~Command();
        void getSearchBehavior(unsigned char nZone,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower);
        void getSearchBehaviorPunch(unsigned char nZone,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower);
        void getSearchBehaviorSeek(unsigned char nZone, unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower);
        
        void getWLBehavior(unsigned char wlState, int &leftMotorPower,int &rightMotorPower);
        void getWLBehavior(unsigned char wlState,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower);
        void getWLBehaviorOneWheel(unsigned char wlState,unsigned int &maintainValue, int &leftMotorPower,int &rightMotorPower);

        

        

};
 
#endif
