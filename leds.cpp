#include <SPI.h>

#include <dummy.h>

#include "leds.h" //include the declaration for this class

Leds::Leds(){
  
    
    //pinMode(NEO_PIN, OUTPUT);
    
    // When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
    // Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
    // example for more information on possible values.

     pixels.begin();
  
}

//<<destructor>>
Leds::~Leds(){/*nothing to destruct*/}

void Leds::led1(int RValue,int GValue,int BValue){
  pixels.setPixelColor(0, pixels.Color(RValue ,GValue,BValue)); 
}

//turn the LED on
void Leds::showRedBarValue(float nValue){
  
  
  
  if(nValue < 0 ) nValue = 0;
  if(nValue > 100 ) nValue = 100;
  
  //Reset Old value
  pixels.setPixelColor(0, pixels.Color(0 ,0,0)); 
  pixels.setPixelColor(1, pixels.Color(0 ,0,0)); 
  pixels.setPixelColor(2, pixels.Color(0 ,0,0)); 
  pixels.setPixelColor(3, pixels.Color(0 ,0,0)); 


    // If between 0-25
    if (nValue < 25 ) pixels.setPixelColor(0, pixels.Color((unsigned char)nValue * 10 ,0,0)); 
    
    if (nValue >= 25 ) 
    {
      pixels.setPixelColor(0, pixels.Color(250,0,0));
      
      // If between 25-50
      if (nValue < 50 ) pixels.setPixelColor(1, pixels.Color((unsigned char)(nValue - 25) * 10,0,0));  
    }
      
    if (nValue >= 50 )
    { 
      pixels.setPixelColor(1, pixels.Color(250,0,0));
      
      // If between 50-75
      if (nValue < 75 ) pixels.setPixelColor(2, pixels.Color((unsigned char)(nValue - 50) * 10,0,0));  
    }
    
    // If between 75-100
    if (nValue >= 75 )
   {
     pixels.setPixelColor(2, pixels.Color(250,0,0));
     pixels.setPixelColor(3, pixels.Color((unsigned char)(nValue - 75) * 10 ,0,0)); 
   }  
  
  pixels.show(); // This sends the updated pixel color to the hardware. 
  	
}

//turn the LED on
void Leds::showGreenBarValue(float nValue){
  
  
  
  if(nValue < 0 ) nValue = 0;
  if(nValue > 100 ) nValue = 100;
  
  //Reset Old value
  pixels.setPixelColor(0, pixels.Color(0 ,0,0)); 
  pixels.setPixelColor(1, pixels.Color(0 ,0,0)); 
  pixels.setPixelColor(2, pixels.Color(0 ,0,0)); 
  pixels.setPixelColor(3, pixels.Color(0 ,0,0)); 


    // If between 0-25
    if (nValue < 25 ) pixels.setPixelColor(0, pixels.Color(0 ,(unsigned char)nValue * 10,0)); 
    
    if (nValue >= 25 ) 
    {
      pixels.setPixelColor(0, pixels.Color(0,250,0));
      
      // If between 25-50
      if (nValue < 50 ) pixels.setPixelColor(1, pixels.Color(0,(unsigned char)(nValue - 25) * 10,0));  
    }
      
    if (nValue >= 50 )
    { 
      pixels.setPixelColor(1, pixels.Color(0,250,0));
      
      // If between 50-75
      if (nValue < 75 ) pixels.setPixelColor(2, pixels.Color(0,(unsigned char)(nValue - 50) * 10,0));  
    }
    
    // If between 75-100
    if (nValue >= 75 )
   {
     pixels.setPixelColor(2, pixels.Color(0,250,0));
     pixels.setPixelColor(3, pixels.Color(0,(unsigned char)(nValue - 75) * 10 ,0)); 
   }  
  
  pixels.show(); // This sends the updated pixel color to the hardware. 
  	
}

//turn the LED on
void Leds::showBlueBarValue(float nValue){
  
  
  
  if(nValue < 0 ) nValue = 0;
  if(nValue > 100 ) nValue = 100;
  
  //Reset Old value
  pixels.setPixelColor(0, pixels.Color(0,0,0)); 
  pixels.setPixelColor(1, pixels.Color(0,0,0)); 
  pixels.setPixelColor(2, pixels.Color(0,0,0)); 
  pixels.setPixelColor(3, pixels.Color(0,0,0)); 


    // If between 0-25
    if (nValue < 25 ) pixels.setPixelColor(0, pixels.Color(0 ,0,(unsigned char)nValue * 10)); 
    
    if (nValue >= 25 ) 
    {
      pixels.setPixelColor(0, pixels.Color(0,0,250));
      
      // If between 25-50
      if (nValue < 50 ) pixels.setPixelColor(1, pixels.Color(0,0,(unsigned char)(nValue - 25) * 10));  
    }
      
    if (nValue >= 50 )
    { 
      pixels.setPixelColor(1, pixels.Color(0,0,250));
      
      // If between 50-75
      if (nValue < 75 ) pixels.setPixelColor(2, pixels.Color(0,0,(unsigned char)(nValue - 50) * 10));  
    }
    
    // If between 75-100
    if (nValue >= 75 )
   {
     pixels.setPixelColor(2, pixels.Color(0,0,250));
     pixels.setPixelColor(3, pixels.Color(0,0,(unsigned char)(nValue - 75) * 10 )); 
   }  
  
  pixels.show(); // This sends the updated pixel color to the hardware. 
  	
}

//turn the LED on
void Leds::showMotorValues(float nLeftValue, float nRightValue){
  
  //Reset Old value
  nRightValue >= 0 ? pixels.setPixelColor(1,  pixels.Color(0,map(nRightValue, 0, 100, 0, 128),0))  :  pixels.setPixelColor(1, pixels.Color(0,0,map(nRightValue, 0, -100, 0, 128)));
  nLeftValue >= 0 ? pixels.setPixelColor(2, pixels.Color(0,map(nLeftValue, 0, 100, 0, 128),0))  : pixels.setPixelColor(2, pixels.Color(0,0,map(nLeftValue, 0, -100, 0, 128)));
 
  
  pixels.show(); // This sends the updated pixel color to the hardware. 
    
}

void Leds::showQTRValues(unsigned int WLState){

  switch (WLState){

  case NO_WL    :   pixels.setPixelColor(0,  pixels.Color(0,0,0)); 
                    pixels.setPixelColor(3,  pixels.Color(0,0,0));
                                                                     break;
  case LEFT_WL  :   pixels.setPixelColor(0,  pixels.Color(0,0,0)); 
                    pixels.setPixelColor(3,  pixels.Color(LED_MAX_POWER,0,0));
                                                                     break;
  case RIGHT_WL :   pixels.setPixelColor(0,  pixels.Color(LED_MAX_POWER,0,0)); 
                    pixels.setPixelColor(3,  pixels.Color(0,0,0));
                                                                     break;
  case BOTH_WL  :   pixels.setPixelColor(0,  pixels.Color(LED_MAX_POWER,0,0)); 
                    pixels.setPixelColor(3,  pixels.Color(LED_MAX_POWER,0,0));
                                                                     break;
  default       :   pixels.setPixelColor(0,  pixels.Color(0,0,0)); 
                    pixels.setPixelColor(3,  pixels.Color(0,0,0));
                                                                     break; 
}
  
  pixels.show(); // This sends the updated pixel color to the hardware. 
    
}

void Leds::showDistanceValues(){

  
 // pixels.setPixelColor(0,  pixels.Color(0,!digitalRead(DIS_D_LEFT_B2)*100,!digitalRead(DIS_S_RIGHT_B1)*100)); 
  
 // pixels.show(); // This sends the updated pixel color to the hardware. 
    
}

