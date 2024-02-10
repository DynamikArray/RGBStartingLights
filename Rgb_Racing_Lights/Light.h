#ifndef LIGHT_H
#define LIGHT_H

class Light{
  private:
    uint32_t color;
    int startingPixel;
    int length;
    unsigned long ledTimer;
    bool ledStatus;

  public:
    Light(uint32_t color, int startingPixel, int length){
      ledTimer = 0;
      ledStatus = false;
      this->color = color;
      this->startingPixel = startingPixel;
      this->length = length;      
    }
    
    void ledOn(){
      strip.fill(color,startingPixel,length);
       strip.show();
      ledStatus = true;
    }

    void ledOff(){
      strip.fill(BLACK,startingPixel,length);
       strip.show();
      ledStatus = false;
    }

    void blinkLed(unsigned long interval) {
      unsigned long currentTime = millis();
            
      if (currentTime - ledTimer >= interval) {
        ledTimer = currentTime;
        
        if (ledStatus) {
          ledOff();
        } else {
          ledOn();
        }
      }
    }

};

#endif