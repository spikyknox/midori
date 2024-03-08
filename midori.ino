#include <VescUart.h>
#include <buffer.h>
#include <crc.h>
#include <datatypes.h>


/*
    This is MIDORI firmware

    Main author: 
    Pier-Marc Comtois-Rivet.
    Charles Richard-Allix.
    

*/

#include "midori.h"


/** Initiate //VESCUART class */
VescUart VESCUART;
Leds NeoPixel;


Command commandCtrl;
Sensors sensorsCtrl;
unsigned int maintainValue;
unsigned char mainMode;
unsigned int searchDelay;
unsigned int checkSerial;

int leftMotorRPM = 0;
int rightMotorRPM = 0;
int wlState = 0;

void setup() {
  //VESC INIT
  Serial0.begin(115200);
  while (!Serial0) { ; }
  VESCUART.setSerialPort(&Serial0);

  pinMode(IR_1, INPUT);

  pinMode(LED_RED, OUTPUT);

  VESCUART.setDuty(0, LEFT_MOTOR_CANID);
  VESCUART.setDuty(0, RIGHT_MOTOR_CANID);
  delay(100);

  do {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_BLUE, HIGH);
    //NeoPixel.showRedBarValue(100);
    // if( analogRead(WL_RIGHT_1) < WHITE_LINE_THRESHOLD)
    // {  
    //   digitalWrite(LED_RED, HIGH);
   
    // }else{
    //   digitalWrite(LED_RED, LOW);
    // }


    delay(10);

  } while (!digitalRead(IR_1));



  int startDelay = 0;
  do {
    //NeoPixel.showBlueBarValue(startDelay / 30);
    delay(10);
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_BLUE, LOW);
    startDelay += 10;
  } while (startDelay < 0);

  mainMode = AUTO_MODE;
}
int zone;

void loop() {

  leftMotorRPM = 0;
  rightMotorRPM = 0;
  wlState = 0;

  if (!digitalRead(IR_1)) mainMode = STOP_MODE;
  else if (mainMode != STOP_MODE) mainMode = AUTO_MODE;

  switch (mainMode) {
      // --------------------------------------- Automatic Mode ----------------------------------------//
    case AUTO_MODE:
      digitalWrite(LED_GREEN, LOW);
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_BLUE, LOW);

      wlState = sensorsCtrl.getWLState();
      if (wlState) {
          commandCtrl.getWLBehavior(wlState, maintainValue, leftMotorRPM, rightMotorRPM);
       }
       else {
         commandCtrl.getSearchBehavior(sensorsCtrl.getDistanceState(), leftMotorRPM, rightMotorRPM);
       }
      break;
      // ----------------------------------------- Stop Mode ---------------------------------------------//
    case STOP_MODE:

      leftMotorRPM = 0;
      rightMotorRPM = 0;
      maintainValue = 0;
      VESCUART.setRPM(leftMotorRPM, LEFT_MOTOR_CANID);
      VESCUART.setRPM(rightMotorRPM, RIGHT_MOTOR_CANID);
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_BLUE, HIGH);
      break;

    default:

      leftMotorRPM = 0;
      rightMotorRPM = 0;
      maintainValue = 0;
      VESCUART.setRPM(leftMotorRPM, LEFT_MOTOR_CANID);
      VESCUART.setRPM(rightMotorRPM, RIGHT_MOTOR_CANID);
      break;
  }
      // ------------------------ Send Command to motor ----------------------------------//
      if (maintainValue > 0) {
        // Maintain value until timeout or other detection.
        unsigned char timing = 0;

        // Do WLbehavior until WL is cleared
        do {

          wlState = sensorsCtrl.getWLState();

          // Update Value only if we detect a WL
          if (wlState) {
            
            unsigned int dummy;
            commandCtrl.getWLBehavior(wlState, dummy, leftMotorRPM, rightMotorRPM);
          }
          digitalWrite(LED_GREEN, HIGH);
          digitalWrite(LED_RED, LOW);
          digitalWrite(LED_BLUE, HIGH);
          // Apply the already calculated motor command.
          VESCUART.setRPM(leftMotorRPM, LEFT_MOTOR_CANID);
          VESCUART.setRPM(rightMotorRPM, RIGHT_MOTOR_CANID);
          // Leds Status
          //NeoPixel.showQTRValues(wlState);
          //NeoPixel.showMotorValues(leftMotorRPM, rightMotorRPM);
          // Maintain value until white line is cleared
          delay(DT);
        } while (wlState != NO_WL && digitalRead(IR_1));

        // Keep last WL value for maintainValue timing
        do {
          //NeoPixel.showQTRValues(sensorsCtrl.getWLState());
          //NeoPixel.showMotorValues(leftMotorRPM, rightMotorRPM);
          digitalWrite(LED_GREEN, HIGH);
          digitalWrite(LED_RED, LOW);
          digitalWrite(LED_BLUE, HIGH);
          VESCUART.setRPM(leftMotorRPM, LEFT_MOTOR_CANID);
          VESCUART.setRPM(rightMotorRPM, RIGHT_MOTOR_CANID);
          timing++;
          delay(DT);
        } while (timing < (maintainValue) && sensorsCtrl.getWLState() == NO_WL && digitalRead(IR_1));


        maintainValue = 0;
      } else {
       digitalWrite(LED_GREEN, LOW);
       digitalWrite(LED_RED, HIGH);
       digitalWrite(LED_BLUE, HIGH);
        VESCUART.setRPM(leftMotorRPM, LEFT_MOTOR_CANID);
        VESCUART.setRPM(rightMotorRPM, RIGHT_MOTOR_CANID);
      }

      //----------------------------------Leds Status--------------------------------------//

      //NeoPixel.showDistanceValues();
      //NeoPixel.showQTRValues(sensorsCtrl.getWLState());
      //NeoPixel.showMotorValues(leftMotorRPM, rightMotorRPM);
      delay(DT);
  
  }
