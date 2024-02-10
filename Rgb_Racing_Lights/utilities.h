Light stagingLightOne(RED, 18, 6);
Light stagingLightTwo(RED, 36, 6);

Light yellowLightOne_Three(YELLOW, 0, 5);
Light yellowLightTwo_Three(YELLOW, 55, 6);

Light yellowLightOne_Two(YELLOW, 12, 6);
Light yellowLightTwo_Two(YELLOW, 42, 6);

Light yellowLightOne_One(YELLOW, 24, 6);
Light yellowLightTwo_One(YELLOW, 30, 6);

Light greenLightAll(GREEN, 0, 60);

void yellowThreeOn(){
 yellowLightOne_Three.ledOn();
 yellowLightTwo_Three.ledOn(); 
}

void yellowTwoOn(){
  yellowThreeOn();
  yellowLightOne_Two.ledOn();
  yellowLightTwo_Two.ledOn();
}

void yellowOneOn(){
  yellowThreeOn();
  yellowTwoOn();
  yellowLightOne_One.ledOn();
  yellowLightTwo_One.ledOn();
}


//setup our lane timers
unsigned long laneTimer;

unsigned long msToSeconds(unsigned long milliseconds) {
  return milliseconds / 1000;  // Divide milliseconds by 1000 to get seconds
}
unsigned long secondsToMs(unsigned long seconds) {
  return seconds * 1000;  // Divide milliseconds by 1000 to get seconds
}

//setup our lane sensors
NewPing laneSensor = NewPing(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);  // NewPing setup of pins  






void checkLaneStaging() {
  int distance = laneSensor.ping_cm();
  
  Serial.print("Distance is in cm = ");
  Serial.print(distance);
  Serial.println("--");
    
  if (distance <= STAGING_HEIGHT_TRIGGER && distance != 0) {
    stagingLightOne.blinkLed(BLINK_INTERVAL);
    stagingLightTwo.blinkLed(BLINK_INTERVAL);
    
    if (timerForSensor == 0) {
      timerForSensor = millis();
    } else {
      Serial.println("Chekcking Times");      
      if (msToSeconds(millis() - timerForSensor) > STAGING_DETECTION_TIME) {        
        stagingState[0] = READY; 
      }
    }
  } else {
    stagingLightOne.ledOff();
    stagingLightTwo.ledOff();
    // Serial.print("Waiting for car in lane: ");    
    timerForSensor = 0;
  }
}

void handleStaged(){ 
    Serial.println("staged");          
    stagingLightOne.ledOn();   
    stagingLightTwo.ledOn();   
    delay(secondsToMs(2));
    stagingLightOne.ledOff();    
    stagingLightTwo.ledOff();    
    delay(secondsToMs(1));
}

void handleCountdown(){
  Serial.println("countdown");
  yellowThreeOn();
  delay(1000);

  strip.clear();

  yellowTwoOn();
  delay(1000);

  strip.clear();
  
  yellowOneOn();
  delay(1000);

  strip.clear();
  greenLightAll.ledOn();
  delay(1000);
  strip.clear();
}


