#ifndef _SOUND_H
#define _SOUND_H
#include <Arduino.h>

#include "AudioFileSourcePROGMEM.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2SNoDAC.h"

#include "sound/s1.h"
#include "sound/s2.h"
#include "sound/s3.h"
#include "sound/s4.h"
#include "sound/s5.h"
#include "sound/s6.h"
#include "sound/s7.h"

#define SOUND_PIN     14        
#define SOUND_MAX     7         


enum SOUND_NAME{    
  SOUND_1 = 0,                  
  SOUND_2,                      
  SOUND_3,                      
  SOUND_4,                      
  SOUND_5,                      
  SOUND_6,                      
  SOUND_7                       
};

static AudioGeneratorWAV *wav[SOUND_MAX];
static AudioFileSourcePROGMEM *file[SOUND_MAX];
static AudioOutputI2SNoDAC *out;

static bool play_state[SOUND_MAX];


static bool so_power_on_mute = true;

static bool so_mute = false;

void so_play(byte id);    
void so_stop(byte id);    
void so_init();           
void so_loop();           

void so_play(byte id){
  
  if(so_power_on_mute || so_mute)
    return;

  
  if(play_state[id])
    so_stop(id);

  
  if(id==SOUND_1)
    
    file[0]->open( _s1,sizeof(_s1));
  else if(id==SOUND_2)
    
    file[1]->open( _s2,sizeof(_s2));
  else if(id==SOUND_3)
    
    file[2]->open( _s3,sizeof(_s3));
  else if(id==SOUND_4)
    
    file[3]->open( _s4,sizeof(_s4));
  else if(id==SOUND_5)
    
    file[4]->open( _s5,sizeof(_s5));
  else if(id==SOUND_6)
    
    file[5]->open( _s6,sizeof(_s6));
  else if(id==SOUND_7)
    
    file[6]->open( _s7,sizeof(_s7));
  

  
  
  wav[id]->begin(file[id], out);
  play_state[id] = true;

}

void so_stop(byte id){
  wav[id]->stop();  
  
  
  play_state[id] = false;
}

void so_init(){
  
  out = new AudioOutputI2SNoDAC(SOUND_PIN);
  
  file[0] = new AudioFileSourcePROGMEM( _s1, sizeof(_s1) );
  file[1] = new AudioFileSourcePROGMEM( _s2, sizeof(_s2) );
  file[2] = new AudioFileSourcePROGMEM( _s3, sizeof(_s3) );
  file[3] = new AudioFileSourcePROGMEM( _s4, sizeof(_s4) );
  file[4] = new AudioFileSourcePROGMEM( _s5, sizeof(_s5) );
  file[5] = new AudioFileSourcePROGMEM( _s6, sizeof(_s6) );
  file[6] = new AudioFileSourcePROGMEM( _s7, sizeof(_s7) );
  
  for (int i=0; i<SOUND_MAX; i++){
    
    wav[i] = new AudioGeneratorWAV();
  }

  
  for (int i=0; i<SOUND_MAX; i++)
    play_state[i] = false;

}

void so_loop(){  
  for (int i=0; i<SOUND_MAX; i++){
    if(play_state[i]){
      if (wav[i]->isRunning()) {
        if (!wav[i]->loop()) 
          so_stop(i);
      }
    }
  }
}

#endif
