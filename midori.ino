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

unsigned char mainMode;
unsigned int searchDelay;
unsigned int checkSerial;

int leftMotorRPM = 0;
int rightMotorRPM = 0;
int wlState = 0;
unsigned char currentZone;
unsigned int maintainValue = 0;

bool isPunching = false; // Stop punch
bool isCooldown = false; // Start cooldown
unsigned long cooldownTime = 0;
unsigned long punchTime = 0;

//Seek vars
unsigned long waitingTime = 0;
bool isSeeking = false;

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
    //digitalWrite(LED_GREEN, HIGH);
    //digitalWrite(LED_RED, LOW);
    //digitalWrite(LED_BLUE, HIGH);
    //NeoPixel.showRedBarValue(100);
     if( analogRead(WL_RIGHT_1) < WHITE_LINE_THRESHOLD || analogRead(WL_LEFT_1) < WHITE_LINE_THRESHOLD)
     {  
       digitalWrite(LED_RED, HIGH);
   
     }else{
       digitalWrite(LED_RED, LOW);
     }


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
  } while (startDelay < 2990);

  mainMode = AUTO_MODE;
}
int zone;

void loop() {

  leftMotorRPM = 0;
  rightMotorRPM = 0;
  wlState = 0;

  if (!digitalRead(IR_1)) mainMode = STOP_MODE;
  else if (mainMode != STOP_MODE){
    //mainMode = AUTO_MODE;
    mainMode = ONE_IN_PUNCH;
    //mainMode = ONE_IN_PUNCH_SEEK;
  }
  

  switch (mainMode) {
      // --------------------------------------- Automatic Mode ----------------------------------------//
    case AUTO_MODE:

      wlState = sensorsCtrl.getWLState();
      if (wlState) {
          commandCtrl.getWLBehavior(wlState, maintainValue, leftMotorRPM, rightMotorRPM);
       }
       else {
         commandCtrl.getSearchBehavior(sensorsCtrl.getDistanceState(),maintainValue, leftMotorRPM, rightMotorRPM);
       }
      break;
    // --------------------------------------- Automatic Mode ----------------------------------------//
    case ONE_IN_PUNCH:

      wlState = sensorsCtrl.getWLState();
      if (wlState) {
          commandCtrl.getWLBehavior(wlState, maintainValue, leftMotorRPM, rightMotorRPM);
       }
       else {

        currentZone = sensorsCtrl.getDistanceState();
        commandCtrl.getSearchBehaviorPunch(currentZone, maintainValue, leftMotorRPM, rightMotorRPM);

        // Check if in cooldown and if cooldown is over
        if (isCooldown && millis() - cooldownTime >= 3000) { // 3 seconds cooldown
          isCooldown = false;
        } 

        // Handle Z_NEAR and activate punching
        if (currentZone == Z_NEAR && !isCooldown && !isPunching) {
            punchTime = millis();
            isPunching = true; // Start punch
        }

        // Check if punch duration has exceeded 1 second
        if (isPunching && millis() - punchTime >= 160) {
            isPunching = false; // Stop punch
            isCooldown = true; // Start cooldown
            cooldownTime = millis(); // Update cooldown start time
        }

        // If in cooldown after punching, execute Z_FRONT behavior
        if (currentZone == Z_NEAR && isCooldown and !isPunching) {
            commandCtrl.getSearchBehaviorPunch(Z_FRONT, maintainValue, leftMotorRPM, rightMotorRPM);
        }

      }
      break;

    case ONE_IN_PUNCH_SEEK:

      wlState = sensorsCtrl.getWLState();
      if (wlState) {
          commandCtrl.getWLBehavior(wlState, maintainValue, leftMotorRPM, rightMotorRPM);
       }
       else {

        currentZone = sensorsCtrl.getDistanceState();
        commandCtrl.getSearchBehaviorSeek(currentZone, maintainValue, leftMotorRPM, rightMotorRPM);

        // // Check if in cooldown and if cooldown is over
        // if (isCooldown && millis() - cooldownTime >= 3000) { // 3 seconds cooldown
        //   isCooldown = false;
        // }
         
        // // Handle Z_NEAR and activate punching
        // if (currentZone == Z_NEAR && !isCooldown && !isPunching) {
        //     punchTime = millis();
        //     isPunching = true; // Start punch
        // }
      
        // // Check if punch duration has exceeded 1 second
        // if (isPunching && millis() - punchTime >= 400) {
        //     isPunching = false; // Stop punch
        //     isCooldown = true; // Start cooldown
        //     cooldownTime = millis(); // Update cooldown start time
        // }
      
        // // If in cooldown after punching, execute Z_FRONT behavior
        // if (currentZone == Z_NEAR && isCooldown and !isPunching) {
        //     commandCtrl.getSearchBehaviorPunch(Z_FRONT, leftMotorRPM, rightMotorRPM);
        // }

        if (currentZone == Z_UNKNOWN){
         if (isSeeking == false){
          waitingTime = millis();
          isSeeking = true;
         }
        }else{
          isSeeking = false;
        }

        if((millis() - waitingTime > 3000) && isSeeking){
          leftMotorRPM = 3000;
          rightMotorRPM = 3000;
          // Foward done stop seeking
          if((millis() - waitingTime > 4000) && isSeeking){
            isSeeking = false;
        }
        }


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
      digitalWrite(LED_BLUE, LOW);
      break;

    default:

      leftMotorRPM = 0;
      rightMotorRPM = 0;
      maintainValue = 0;
      digitalWrite(LED_GREEN, HIGH);
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_BLUE, LOW);
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
            digitalWrite(LED_GREEN, HIGH);
            digitalWrite(LED_RED, LOW);
            digitalWrite(LED_BLUE, HIGH);
          }

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
       // No maintain value. 
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
