#ifndef _INPUT_SYSTEM_H
#define _INPUT_SYSTEM_H

#define PIN_GAME_A    2
#define PIN_GAME_B    3
#define PIN_TIME      4
#define PIN_UP        5
#define PIN_DOWN      6
#define PIN_LEFT      7
#define PIN_RIGHT     8
#define PIN_JUMP      9

enum INPUT_KEY{    
    KEY_GAME_A = 0,
    KEY_GAME_B,
    KEY_TIME,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_JUMP
};

class InputSystem{
  public:
    InputSystem() {
      pinMode( PIN_GAME_A, INPUT_PULLDOWN);
      pinMode( PIN_GAME_B, INPUT_PULLDOWN);
      pinMode( PIN_TIME, INPUT_PULLDOWN);
      pinMode( PIN_UP, INPUT_PULLDOWN);
      pinMode( PIN_DOWN, INPUT_PULLDOWN);
      pinMode( PIN_LEFT, INPUT_PULLDOWN);
      pinMode( PIN_RIGHT, INPUT_PULLDOWN);
      pinMode( PIN_JUMP, INPUT_PULLDOWN);
    }

    bool pressed(INPUT_KEY key){
      int buttonState = 0;

      if (key == KEY_GAME_A)
        buttonState = digitalRead(PIN_GAME_A);
      else if (key == KEY_GAME_B)
        buttonState = digitalRead(PIN_GAME_B);
      else if (key == KEY_TIME)
        buttonState = digitalRead(PIN_TIME);
      else if (key == KEY_UP)
        buttonState = digitalRead(PIN_UP);
      else if (key == KEY_DOWN)
        buttonState = digitalRead(PIN_DOWN);
      else if (key == KEY_LEFT)
        buttonState = digitalRead(PIN_LEFT);
      else if (key == KEY_RIGHT)
        buttonState = digitalRead(PIN_RIGHT);
      else if (key == KEY_JUMP)
        buttonState = digitalRead(PIN_JUMP);

      if (buttonState == HIGH)
        return true;
      else
        return false;
    }

    bool down(INPUT_KEY key){
      if (key == KEY_GAME_A)              
        return _ifDown(KEY_GAME_A);
      else if (key == KEY_GAME_B)
        return _ifDown(KEY_GAME_B);
      else if (key == KEY_TIME)
        return _ifDown(KEY_TIME);
      else if (key == KEY_UP)
        return _ifDown(KEY_UP);
      else if (key == KEY_DOWN)
        return _ifDown(KEY_DOWN);
      else if (key == KEY_LEFT)
        return _ifDown(KEY_LEFT);
      else if (key == KEY_RIGHT)
        return _ifDown(KEY_RIGHT);
      else if (key == KEY_JUMP)
        return _ifDown(KEY_JUMP);      
      return false;    
    }

  private:      
    bool bntState[8]={false,false,false,false,false,false,false,false,};

    bool _ifDown(INPUT_KEY key){
      int buttonState = 0;

      if (key == KEY_GAME_A)
        buttonState = digitalRead(PIN_GAME_A);
      else if (key == KEY_GAME_B)
        buttonState = digitalRead(PIN_GAME_B);
      else if (key == KEY_TIME)
        buttonState = digitalRead(PIN_TIME);
      else if (key == KEY_UP)
        buttonState = digitalRead(PIN_UP);
      else if (key == KEY_DOWN)
        buttonState = digitalRead(PIN_DOWN);
      else if (key == KEY_LEFT)
        buttonState = digitalRead(PIN_LEFT);
      else if (key == KEY_RIGHT)
        buttonState = digitalRead(PIN_RIGHT);
      else if (key == KEY_JUMP)
        buttonState = digitalRead(PIN_JUMP);

      if (!bntState[key] && buttonState == HIGH){
        bntState[key] = true;
        return true;
      }else if(buttonState == LOW){
        bntState[key] = false;
      }
      return false;
    }

};
#endif
