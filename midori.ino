/*
    This is MIDORI firmware

    Main author: 
    Pier-Marc Comtois-Rivet.
    Charles Richard-Allix.
    

*/

#include "midori.h"
#include <VescUart.h>


/** Initiate VescUart class */
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
  Serial.begin(115200);
  while (!Serial) { ; }
  VESCUART.setSerialPort(&Serial);

  pinMode(IR_1, INPUT);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  VESCUART.setRPM(0, LEFT_MOTOR_CANID);
  VESCUART.setRPM(0, RIGHT_MOTOR_CANID);
  delay(100);

  do {

    NeoPixel.showRedBarValue(100);

    delay(10);

  } while (!digitalRead(IR_1));

  digitalWrite(LED, LOW);

  int startDelay = 0;
  do {
    NeoPixel.showBlueBarValue(startDelay / 30);
    delay(10);
    startDelay += 10;
  } while (startDelay < 2750);

  mainMode = AUTO_MODE;
}


void loop() {

  leftMotorRPM = 0;
  rightMotorRPM = 0;
  wlState = 0;


  if (digitalRead(IR_1)) mainMode = STOP_MODE;
  else if (mainMode != STOP_MODE) mainMode = AUTO_MODE;

  switch (mainMode) {
      // --------------------------------------- Automatic Mode ----------------------------------------//
    case AUTO_MODE:

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
      break;

    default:

      leftMotorRPM = 0;
      rightMotorRPM = 0;
      maintainValue = 0;
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
          // Apply the already calculated motor command.
          VESCUART.setRPM(leftMotorRPM, LEFT_MOTOR_CANID);
          VESCUART.setRPM(rightMotorRPM, RIGHT_MOTOR_CANID);
          // Leds Status
          NeoPixel.showQTRValues(wlState);
          NeoPixel.showMotorValues(leftMotorRPM, rightMotorRPM);
          // Maintain value until white line is cleared
          delay(DT);
        } while (wlState != NO_WL);

        // Keep last WL value for maintainValue timing
        do {
          NeoPixel.showQTRValues(sensorsCtrl.getWLState());
          NeoPixel.showMotorValues(leftMotorRPM, rightMotorRPM);
          VESCUART.setRPM(leftMotorRPM, LEFT_MOTOR_CANID);
          VESCUART.setRPM(rightMotorRPM, RIGHT_MOTOR_CANID);
          timing++;
          delay(DT);
        } while (timing < (maintainValue) && sensorsCtrl.getWLState() == NO_WL);


        maintainValue = 0;
      } else {
        VESCUART.setRPM(leftMotorRPM, LEFT_MOTOR_CANID);
        VESCUART.setRPM(rightMotorRPM, RIGHT_MOTOR_CANID);
      }

      //----------------------------------Leds Status--------------------------------------//

      //NeoPixel.showDistanceValues();
      NeoPixel.showQTRValues(sensorsCtrl.getWLState());
      NeoPixel.showMotorValues(leftMotorRPM, rightMotorRPM);
      delay(DT);
  }
