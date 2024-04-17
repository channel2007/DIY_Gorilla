#ifndef _DONKEY_KONG_CLOCK_H
#define _DONKEY_KONG_CLOCK_H

#include <DS3231.h>
#include <Wire.h>

#define PIN_SDA 12
#define PIN_SCL 13

#define START_UP_CLOCK 5


DS3231 myRTC;
bool century = false;
bool h12Flag;
bool pmFlag;

byte c_set_clock = 0;
bool c_flash = true;

byte c_hour   = 12;
byte c_minute = 00;
bool c_pm = true;

void c_init(){
  Wire.setSDA(PIN_SDA);
  Wire.setSCL(PIN_SCL);	
  Wire.begin();
    
  myRTC.setClockMode(true);       
  myRTC.getHour(h12Flag, pmFlag);
}

void c_setDateTime(byte hour, byte minute) {
  myRTC.setHour(hour);
  myRTC.setMinute(minute);
  myRTC.setSecond(0);
  
  myRTC.setA1Time( 0, hour, minute, 0, 0x0, true, true, true);
}  

bool c_isPM(){
  if (pmFlag){
    
    return true;
  }else{
    
    return false;
  }
}


String c_getSecond(){
  return String(myRTC.getSecond());
}

short c_get_hour(){
  byte hour = myRTC.getHour(h12Flag, pmFlag);
  if(hour>12)
    return 12 - hour;
  else
    return hour;
}

short c_get_minute(){  
  return myRTC.getMinute();
}

void c_set_init(){
  c_hour   = c_get_hour();
  c_minute = c_get_minute();
  c_pm = pmFlag;
}

#endif
