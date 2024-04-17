#ifndef _CLOCK_SYSTEM_H
#define _CLOCK_SYSTEM_H

class ClockSystem{
public:
  
  ClockSystem() {    
    init();     
  }

  void init(byte n = 255) {
    if (n == 255) {
      for (byte i = 0; i < (sizeof(clockSys) / sizeof(unsigned long)); i++)
        clockSys[i] = millis();
    }
    else {
      clockSys[n] = millis();
    }
  }

  bool check(byte id, unsigned long t) {
    unsigned long diff = millis() - clockSys[id];
    if (diff > t) {
      
      clockSys[id] = millis();
      return true;
    }
    return false;
  }

  void reset(byte id, unsigned long t) {
    clockSys[id] = millis() - t;
  }
  
private:  
  
  unsigned long clockSys[16];

};
#endif