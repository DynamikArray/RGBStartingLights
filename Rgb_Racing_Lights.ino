#include "racelightConfig.h"

void setup() {
  strip.begin();
  strip.setBrightness(255);
  strip.show();  // Initialize all pixels to 'off'

  //init timer vars
 timerForSensor= 0;

  //for logging
  Serial.begin(9600);
}

void reset(){
  //init stagingState
  stagingState[0]=EMPTY;

  //init timer vars
  timerForSensor=0;
}


void loop() {
  run_race_control();
  delay(100); // fastest we want to read between pings, all other states, should have there own delays and timers as needed
}


void run_race_control(){
  switch(raceState){
    case WAITING:
      //check the lanes
      checkLaneStaging();   
      //
      if(stagingState[0] == READY ){        
        stagingLightOne.ledOn();
        stagingLightTwo.ledOn();
        raceState = STAGED;
      }     
    break;
    case STAGED:
      handleStaged();
      raceState = COUNTDOWN;               
    break;
    case COUNTDOWN:
      handleCountdown();
      reset();
      raceState = WAITING;             
    break;
  }
}

