#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#define SCREEN_ONE_CS 17
#define SCREEN_TWO_CS 16

enum CLOCK_NAME{    
    CLOCK_FLIP = 0,
    CLOCK_FPS,
    CLOCK_WALK,                     
    CLOCK_HOOK,                     
    CLOCK_JUMP,                     
    CLOCK_BUCKET_MOVE,              
    CLOCK_STEEL_MOVE,               
    CLOCK_LIFE_ANI,                 
    CLOCK_SCORE_ADD,                
    CLOCK_GAME_SPEED,               
    CLOCK_ROLE_FLASH,               
    CLOCK_ROLE_OUT,                 
    CLOCK_SET_CLOCK,                
    CLOCK_ANI_FIRE,                 
    CLOCK_ANI_BIRD,                 
    CLOCK_STAR,                     
    CLOCK_IN_TIME,                  
    CLOCK_JUMP_DELAY,               
};

typedef struct{
    const unsigned short  *img;
    short           x;
    short           y;
    short           w;
    short           h;
}image_struct;

TFT_eSPI tft = TFT_eSPI(); 
TFT_eSprite backupPage = TFT_eSprite(&tft);


static unsigned long int next = 1;    

int gl_rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}

void gl_srand(unsigned int seed) {
    next = seed;
}

#endif