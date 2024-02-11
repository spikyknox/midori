#ifndef LEDS_H
#define LEDS_H
 
#include "midori.h"

// Which pin on the Arduino is connected to the NeoPixels?
#define NEO_PIN            22

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      4

#define LED_MAX_POWER 75
 
class Leds {
public:
           
        Leds();
        ~Leds();
        
        void showRedBarValue(float nValue);
        void showBlueBarValue(float nValue);
        void showGreenBarValue(float nValue);
        void showMotorValues(float nLeftValue, float nRightValue);
        void showQTRValues(unsigned int WLState);
        void showDistanceValues();

        
        Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);
        
};
 
#endif
