#include <TFT_eSPI.h> 

#include "hardware/adc.h"

#include "Free_Fonts.h"
#include "ClockSystem.h"
#include "InputSystem.h"

#include "global.h"
#include "clock.h"
#include "gameplay.h"

void setup() {
  Serial.begin(57600);

  pinMode(SCREEN_ONE_CS,OUTPUT);
  pinMode(SCREEN_TWO_CS,OUTPUT);

  tft.init();
  tft.setRotation(3);
  tft.setSwapBytes(true);
  tft.setFreeFont(FSB24);
      
  gp_init();
}

void loop() {  
  gp_update();
}
