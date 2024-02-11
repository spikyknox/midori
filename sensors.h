#ifndef SENSORS_H
#define SENSORS_H
 
#include "midori.h"

#define Z_UNKNOWN     0
#define Z_SIDE_LEFT   1
#define Z_FRONT_LEFT  2
#define Z_FRONT       3
#define Z_FRONT_RIGHT 4 
#define Z_SIDE_RIGHT  5
#define Z_NEAR_LEFT   6
#define Z_NEAR_RIGHT  7
#define Z_NEAR        8

#define NO_WL         0
#define LEFT_WL       1
#define RIGHT_WL      2
#define BOTH_WL       3

class Sensors {
public:
        Sensors();
        ~Sensors();
        
        unsigned char getDistanceState();
        unsigned char getWLState();
        unsigned char getRCState();
};
 
#endif
