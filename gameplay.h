#ifndef __GAME_PLAY_H
#define __GAME_PLAY_H

#include "image.h"
#include "sound.h"

#define BUCKET_MAX      28
#define STEEL_MAX       5

#define HOOK_MAX_INIT   4

enum GAME_MODE{    
  MODE_POWER_ON = 0,
  MODE_GAME,
  MODE_PAUSE,
  MODE_CLOCK,
};

enum MODE_AB{    
  MODE_A=0,
  MODE_B,
  MODE_TIME,
};

static int set_throw_min = 3;
static int set_throw_max = 4;

static int set_steel_min = 1; 
static int set_steel_max = 6; 

static short set_move_speed = 1000;

void gp_showImg(TFT_eSprite canvas, image_struct *img);
void gp_autoplay();                 
void gp_steel_close();              
void gp_steel_init();               
void gp_steel_move();               
void gp_steel_collision(bool stair);
void gp_steel_update(void);         
void gp_goFB(int a, int b, int c);  
void gp_role_die();                 
void gp_start_game(short m);        
void gp_set_speed();                
void gp_restart();                  
void gp_score_update();             
void gp_pause();                    
void gp_reset();                    
void gp_donkey_init(short pos);     
void gp_donkey_update();            
void gp_role_out();                 
void gp_jump();                     
void gp_up();                       
void gp_down();                     
void gp_right();                    
void gp_left();                     
void gp_input();                    
void gp_shelf_down(short frame);    
void gp_game_up();                  
void gp_game_down();                
void gp_power_on_up();              
void gp_power_on_down();            
void gp_init();                     
void gp_update();                   

ClockSystem clockSystem;
InputSystem inputSystem;

char buffer[16];


unsigned short fps_t = 0;

unsigned short fps = 0;
bool flip = true;
unsigned short game_mode = MODE_POWER_ON;

bool stop_input = false;
bool jump_hook = false;
short get_hook = 0;
short hook_max = HOOK_MAX_INIT;
short hook_score[] = {16,15,14,13};

short role_walk[]={0,2,3,4,6,7,8,10,12,13,14,15,16,18,19,21,22};
short role_walk_id = -1;
short role_flash = -1;
bool role_jump = false;

short bucket_path[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
short bucket_move[]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
short bucket_pos_1[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,21,22,25};
short bucket_pos_2[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,20,23,26};
short bucket_pos_3[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,24,27};

bool role_tieRod = false;
bool tieRod = false;

static short hook_reverse = false;
static short hook_move = 0;
static short hook_count = 0;
bool get_ready_hook = false;
const short life_ani[7][3] = {{1,1,1},{0,1,1},{1,0,1},{1,1,0},{0,1,0},{1,0,0},{0,0,0}};
short life_next = 0;
short life = 3;
short donkey_pos = 1;
short donkey_leave = -2;
short platform_flash = 6;
int score = 0;
int scoreAdd = 0;
short heart_ani = 0;
short play_mode = 0;
short steel_path[]={-1,-1,-1};
short steel_out = -1;

static short gp_path[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
static short gp_steel_path[]={0,0,0,0,0};

bool closet_invincible = false;
bool auto_play = false;
int bat_percentage = 0;

void gp_showImg(TFT_eSprite *canvas, image_struct *img){
  canvas->fillScreen(TFT_BLACK);
  canvas->pushImage( 0, 0, img->w, img->h, img->img);
  canvas->pushToSprite( &backupPage, img->x, img->y, TFT_BLACK);
}

void gp_autoplay(){    
    short bmax = sizeof(bucket_move) / sizeof(bucket_move[0]);
    short id = 0;

    if (role_jump || (role_flash > -1))
      return;

    if (role_walk_id == -1 && !stop_input && !get_ready_hook && hook_max!=-1){
      gp_role_out();
      return;
    }

    for(int i=0; i<BUCKET_MAX; i++)
      gp_path[i]=0;
    for(int i=0; i<STEEL_MAX; i++)
      gp_steel_path[i]=0;
    for(int i=0; i< 3; i++){
      if(steel_path[i]!= -1)
      gp_steel_path[steel_path[i]] = 1;
    }

    for(int i=0; i<bmax; i++){
      if(bucket_move[i]>-1){
        if(bucket_path[i] == 1){
          id = bucket_pos_1[bucket_move[i]];
        }else if(bucket_path[i] == 2){
          id = bucket_pos_2[bucket_move[i]];
        }else if(bucket_path[i] == 3){
          id = bucket_pos_3[bucket_move[i]];
        }
        gp_path[id] = 1;
      }
    }

    clockSystem.reset(CLOCK_WALK, 2000);
    role_tieRod = false;

    if(role_walk_id>=12){
      if(!tieRod){            
        if ((role_walk_id==14  && gp_path[23]==0 && gp_path[26]==0) ||
            (role_walk_id==13 && gp_path[22]==0 && gp_path[25]==0)  ||
            (role_walk_id==12)){
          gp_left();
        }
      }else{
        if ((role_walk_id==12  && gp_path[23]==0 && gp_path[26]==0) ||
            (role_walk_id==13 && gp_path[24]==0 && gp_path[27]==0)  ||
            (role_walk_id==13 && gp_path[23]==1)
        ){
          gp_right();
        }else if (role_walk_id==14 && gp_path[24]==1){
          gp_left();
        }else if (role_walk_id==14 && hook_reverse && hook_move==1){
          gp_jump();
        }
      }

    }else{      
      if( (role_walk_id==0 && gp_path[1]==1)  ||
          (role_walk_id==3 && gp_path[4]==1)  ||
          (role_walk_id==6 && gp_path[8]==1 && gp_steel_path[3]==0) ||
          (role_walk_id==7 && gp_path[9]==1 && gp_steel_path[2]==0)
      ){
        gp_jump();      
      }else if ((role_walk_id==1 && gp_path[2]==1)  ||
                (role_walk_id==2 && gp_path[3]==1)  ||
                (role_walk_id==3 && gp_path[4]==1)  ||
                (role_walk_id==4 && gp_path[7]==1)  ||
                (role_walk_id==5 && gp_path[9]==0)  ||
                (role_walk_id==6 && gp_path[9]==0)  ||
                (role_walk_id==7 && gp_path[10]==0) ||
                (role_walk_id==8 && gp_path[11]==0)
      ){
        gp_left();            
      }else if ((role_walk_id==5 && gp_path[7]==1)  ||
                (role_walk_id==5 && gp_path[8]==1)  ||
                (role_walk_id==10 && gp_path[14]==1 && gp_steel_path[1]==1) ||
                (role_walk_id==11 && gp_path[14]==1)
      ){    
        gp_down();            
      }else if ((role_walk_id==6 && gp_path[8]==1)  ||
                (role_walk_id==7 && gp_path[9]==1)  ||
                (role_walk_id==8 && gp_path[10]==1) ||
                (role_walk_id==8 && gp_path[11]==1) ||
                (role_walk_id==9 && gp_path[11]==1) ||
                (role_walk_id==0 && gp_path[2]==0)  ||
                (role_walk_id==1 && gp_path[3]==0)  ||
                (role_walk_id==2 && gp_path[4]==0)  ||
                (role_walk_id==3 && gp_path[5]==0)
      ){      
        gp_right();                  
      }else if ((role_walk_id==11 && gp_path[14]==1 && gp_path[25]==0 && gp_path[22]==0) ||
                (role_walk_id==4 && gp_path[5]==0)  ||
                (role_walk_id==4 && gp_path[6]==0)  ||
                (role_walk_id==9 && gp_steel_path[0]==0)  ||
                (role_walk_id==10 && gp_path[15]==0)  ||
                (role_walk_id==11 && gp_path[25]==0 && gp_path[22]==0)
      ){    
        gp_up();      
      }
    }
}

void gp_steel_close(void){
  short bmax = sizeof(bucket_move) / sizeof(bucket_move[0]);
  short id = 0;

  for(int i=0; i<bmax; i++){
    if(bucket_move[i]>-1){
      if(bucket_path[i] == 1)
        id = bucket_pos_1[bucket_move[i]];
      else if(bucket_path[i] == 2)
        id = bucket_pos_2[bucket_move[i]];
      else if(bucket_path[i] == 3)
        id = bucket_pos_3[bucket_move[i]];
      
      if(id==1){
        bucket_path[i]= -1;
        bucket_move[i]= -1;
      }
    }
  }
}

void gp_steel_init(void){
  short rmax = sizeof(steel_path) / sizeof(steel_path[0]);
  for(int i=0; i<rmax; i++){
    if(steel_path[i]==-1){
      steel_path[i] = 4;
      clockSystem.init(CLOCK_STEEL_MOVE);
      return;
    }
  }
}

void gp_steel_move(void){
  short rmax = sizeof(steel_path) / sizeof(steel_path[0]);
  
  if (clockSystem.check( CLOCK_STEEL_MOVE, set_move_speed*2) && role_flash==-1 && game_mode != MODE_PAUSE){
    for(int i=0; i<rmax; i++){
      if(steel_path[i]>-1)
        steel_path[i]--;
    }
    if(steel_out>-2){
      steel_out--;
      if(steel_out < 0){
        if(play_mode == MODE_A){
          for(int i=0; i<rmax; i++){
            if(steel_path[i]>-1){
              steel_out = gl_rand() % (set_steel_max - set_steel_min + 1) + set_steel_min;
              return;
            }
          }
        }
        gp_steel_init();
        steel_out = gl_rand() % (set_steel_max - set_steel_min + 1) + set_steel_min;
      }
    }
  }    
}

void gp_steel_collision(bool stair){
  short rmax = sizeof(steel_path) / sizeof(steel_path[0]);
  for(int i=0; i<rmax; i++){
    if(steel_path[i]>-1){            
      if(!closet_invincible){
        if(stair){
          if(role_flash==-1 && (role_walk_id==10 && steel_path[i]==0))
            gp_role_die();
        }else{
          if( (role_flash==-1 && role_jump) && ((role_walk_id==6 && steel_path[i]==3) || (role_walk_id==7 && steel_path[i]==2)) )
            gp_role_die();
        }
      }
    }
  }
}

void gp_steel_update(void){
  short rmax = sizeof(steel_path) / sizeof(steel_path[0]);
  short id = 0;
  
  for(int i=0; i<rmax; i++){
    if(steel_path[i]>-1){
      id = steel_path[i];
      gp_showImg(&canvas_ST, &img_ST[id]);
    }
  }
}

void gp_goFB(int a, int b, int c){
  short bmax = sizeof(bucket_move) / sizeof(bucket_move[0]);
  if(!closet_invincible){
    for(int i=0; i<bmax; i++){
      if(bucket_move[i]>-1){
        if ((bucket_move[i]-a) == (role_walk_id-b)){
          role_walk_id = c;
          gp_role_die();
        }                                    
      }
    }
  }
}

void gp_role_die(){    
  clockSystem.init(CLOCK_BUCKET_MOVE);
  stop_input = true;
  role_flash = 5;
}

void gp_bucket_die(int i){
  if(!closet_invincible){
    gp_role_die();
    bucket_move[i]++;
  }
}

void gp_start_game(short m){
  if(get_hook>0){
    auto_play = so_power_on_mute = true;
    return;
  }

  play_mode = m;
  
  if (m==0){
    set_steel_min = 1;
    set_steel_max = 6;
  }else if (m==1){
    set_steel_min = 0;
    set_steel_max = 5;
  }

  role_walk_id = -1;

  for(int i=0; i<3; i++)
      steel_path[i]=-1;
  hook_max = HOOK_MAX_INIT;
  role_jump = false;
  life = 3;
  life_next = 0;
  score = 0;
  
  platform_flash = 6;

  bucket_path[0] = 1;
  bucket_move[0] = 5;

  bucket_path[1] = 1;
  bucket_move[1] = 8;

  bucket_path[2] = 1;
  bucket_move[2] = 16;

  gp_set_speed();
  clockSystem.init(CLOCK_ROLE_OUT);
  
  game_mode = MODE_GAME;
}

void gp_set_speed(void){
  set_move_speed = 1000;
  clockSystem.init(CLOCK_GAME_SPEED);
}

void gp_restart(){
    hook_max = HOOK_MAX_INIT;
    platform_flash = 6;
    role_flash = -1;
    game_mode =  MODE_GAME;
    gp_reset();
}

void gp_score_update(){
  if (clockSystem.check( CLOCK_SCORE_ADD, 83)){
    if(scoreAdd>0){
      scoreAdd--;
      score++;
      so_play(SOUND_4);
    }
  }
}

void gp_pause(){
  role_walk_id = -1;
  role_flash = 0;        
  game_mode = MODE_PAUSE;
  stop_input = true;
}

void gp_reset(){
  gp_steel_close();
  gp_set_speed();

  role_walk_id = 0;
  stop_input = false;
  jump_hook = false;

  clockSystem.init(CLOCK_ROLE_OUT);
}

void gp_donkey_init(short pos){    
  short rmax = sizeof(bucket_move) / sizeof(bucket_move[0]);

  for(int i=0; i<rmax; i++){
    if(bucket_move[i]==-1){
      bucket_path[i] = pos;
      if(pos==1){
        bucket_move[i] = (sizeof(bucket_pos_1) / sizeof(bucket_pos_1[0]));
      }else if(pos==2){
        bucket_move[i] = (sizeof(bucket_pos_2) / sizeof(bucket_pos_2[0]));
      }else if(pos==3){
        bucket_move[i] = (sizeof(bucket_pos_3) / sizeof(bucket_pos_3[0]));
      }            
      return;
    }
  }       
}

void gp_donkey_update(){
  short rmax = sizeof(bucket_move) / sizeof(bucket_move[0]);
  short id = 0;
  int r = 0;

  if (clockSystem.check(CLOCK_BUCKET_MOVE, set_move_speed) && hook_max>0 && role_flash==-1 && game_mode != MODE_PAUSE){
    if(donkey_leave == -1){
      donkey_leave = -2;
      gp_donkey_init(donkey_pos+1);

    }else if(donkey_leave == -2){                
      donkey_leave = gl_rand() % (set_throw_max - set_throw_min + 1) + set_throw_min;

    }else{
      donkey_leave--;

      r = gl_rand() % (3 - 1 + 1) + 1;
      if(r==1){
        if(donkey_pos>0)
          donkey_pos--;
      }else if(r==2){
        if(donkey_pos<2)
          donkey_pos++;
      }
    }
    
    for(int i=0; i<rmax; i++){                
      if(bucket_move[i]>-1){
        bucket_move[i]--;
        
        if ((role_walk_id>=0 && role_walk_id<=4) && (role_walk_id==bucket_move[i])){
          if(role_jump){                            
            score+=1;
          }else{                        
            gp_bucket_die(i);
          }
        }else if ((role_walk_id>=5 && role_walk_id<=9) && (role_walk_id==(bucket_move[i]-1))){
          if(role_jump){
            score+=2;
          }else{
            gp_bucket_die(i);
          }
        }else if (role_walk_id==11 && (role_walk_id==(bucket_move[i]-2) && (!role_jump))){
          gp_bucket_die(i);
        }else if (role_walk_id==12 && (bucket_path[i]==1) && (bucket_pos_1[bucket_move[i]]==21) && (!role_jump)){
          gp_bucket_die(i);
        }else if (role_walk_id==13 && (bucket_path[i]==2) && (bucket_pos_2[bucket_move[i]]==20) && (!role_jump)){
          gp_bucket_die(i);
        }else if (role_walk_id==14 && (bucket_path[i]==3) && (bucket_pos_3[bucket_move[i]]==19) && (!role_jump)){
          gp_bucket_die(i);
        }        
      }
    }
    
    if(hook_max!=-1)
      so_play(SOUND_1);

    if(role_jump && role_flash==-1){
      role_jump = false;
      stop_input = false;
    }
  }
}

void gp_role_out(void){
    if(life==0)
        return;        
    gp_steel_close();
    if(!auto_play)
      life--;
    role_walk_id=0;
    clockSystem.reset( CLOCK_LIFE_ANI, 1000);
    so_play(SOUND_2);
}

void gp_jump(void){
  if(role_walk_id==-1 && platform_flash == 6){
    gp_role_out();

  }else{    
    if (role_walk_id==0 || role_walk_id==3 || role_walk_id==6 || role_walk_id==7){
      clockSystem.init(CLOCK_WALK);
      stop_input = true;
      role_jump = true;
      gp_steel_collision(false);      
      so_play(SOUND_2);

    }else if (role_walk_id==14){
      stop_input = true;
      jump_hook = true;
      clockSystem.init(CLOCK_JUMP);
      role_walk_id = 20;
      so_play(SOUND_2);
      clockSystem.init(CLOCK_JUMP_DELAY);
    }
  }
}

void gp_up(void){
  if (clockSystem.check(CLOCK_WALK, set_move_speed)){
    if (role_walk_id==4 || (role_walk_id>=9 && role_walk_id<=11)){
      role_walk_id++;        
      so_play(SOUND_3);
    }
  }
}

void gp_down(void){
  if (clockSystem.check(CLOCK_WALK, set_move_speed)){
    if (role_walk_id==5 || (role_walk_id>=10 && role_walk_id<=12)){
      role_walk_id--;
      so_play(SOUND_3);
    }      
  }    
}

void gp_right(){
  if (clockSystem.check(CLOCK_WALK, set_move_speed)){
    
    if ((role_walk_id>=0 && role_walk_id<=4) || (role_walk_id>=12 && role_walk_id<=14)){
      
      role_walk_id++;
      so_play(SOUND_3);

      
      if(role_walk_id==15){
        
        stop_input = true;
        
        jump_hook = true;
        
        clockSystem.init(CLOCK_JUMP);
        
        
      }else{
        
        if (role_walk_id>=0 && role_walk_id<=4){
          
          gp_goFB( 0, 0, (role_walk_id-1));
        }
        
        if (role_walk_id==5)
          role_walk_id-=1;
      }                    
    
    }else if (role_walk_id>=6 && role_walk_id<=9){
      
      role_walk_id--;
      if (role_walk_id < 0)
        role_walk_id = 0;
      so_play(SOUND_3);

      
      gp_goFB( +2, 0, (role_walk_id+1));
    }
  }
}

void gp_left(){
  
  short rmax = sizeof(role_walk) / sizeof(role_walk[0]);

  if (clockSystem.check(CLOCK_WALK, set_move_speed)){
    
    if (role_walk_id==12){
      
      if (!tieRod){
        
        clockSystem.init(CLOCK_HOOK);
        
        hook_reverse = false;
        
        hook_move = 0;
        
        hook_count = 0;
      }
      role_tieRod = tieRod = true;
      
    
    }else if ((role_walk_id>=0 && role_walk_id<=4) || (role_walk_id>=13 && role_walk_id<=14)){
      
      role_walk_id--;
      if (role_walk_id < 0)
        role_walk_id = 0;
      so_play(SOUND_3);

      
      if (role_walk_id>=0 && role_walk_id<=4){
        
        gp_goFB( +1, 0, (role_walk_id+1));
      }
      
    
    }else if (role_walk_id>=5 && role_walk_id<=8){
      
      role_walk_id++;
      if (role_walk_id >= rmax )
        role_walk_id -= 1;
      so_play(SOUND_3);

      
      gp_goFB( 0, -1, (role_walk_id-1));
    }
  }
}

void gp_input(){
  
  if(c_set_clock > START_UP_CLOCK && play_mode==MODE_TIME){
    
    if (clockSystem.check( CLOCK_SET_CLOCK, 500))
      c_flash = !c_flash;

    
    if(inputSystem.down(KEY_UP) || inputSystem.down(KEY_DOWN) || inputSystem.down(KEY_LEFT) || inputSystem.down(KEY_RIGHT)){
      c_hour++;
      if(c_hour>12){
        c_hour = 1;
        c_pm = !c_pm;
      }
    }    
    
    if(inputSystem.down(KEY_JUMP)){
      c_minute++;
      if(c_minute>59){
        c_minute = 0;
      }      
    }
    
    if(inputSystem.down(KEY_TIME)){
      
      if(c_pm)
        c_hour += 12;
      c_setDateTime( c_hour, c_minute);
      
      c_set_clock = 0;      
    }

  
  }else if(game_mode == MODE_POWER_ON || (game_mode == MODE_PAUSE && life==0) || play_mode==MODE_TIME){
    
    if(inputSystem.down(KEY_TIME))
      c_set_clock=0;
    
    if(inputSystem.pressed(KEY_GAME_A)){
      auto_play = so_power_on_mute = false;
      gp_start_game(MODE_A);            
    
    }else if(inputSystem.pressed(KEY_GAME_B)){
      auto_play = so_power_on_mute = false;
      gp_start_game(MODE_B);      
    
    }else if(inputSystem.pressed(KEY_TIME) && !auto_play){
      auto_play = so_power_on_mute = true;
      gp_start_game(MODE_TIME);
    
    }else if(inputSystem.pressed(KEY_TIME) && auto_play){
      if (clockSystem.check( CLOCK_SET_CLOCK, 500)){
        c_set_clock++;
        if(c_set_clock > START_UP_CLOCK)
          c_set_init(); 
      }
      
    }
   
  
  }else if(game_mode == MODE_GAME && !stop_input && !get_ready_hook && hook_max!=-1){
    
    if(inputSystem.pressed(KEY_LEFT))
      gp_left();
    
    else if(inputSystem.pressed(KEY_RIGHT))
      gp_right();
    
    else if(inputSystem.pressed(KEY_UP))
      gp_up();
    
    else if(inputSystem.pressed(KEY_DOWN))
      gp_down();
    else{
      clockSystem.reset(CLOCK_WALK, set_move_speed);
      
      role_tieRod = false;
    }
    
    if(inputSystem.down(KEY_JUMP)){
      gp_jump();
    }

    
    if (inputSystem.down(KEY_TIME)){
      so_mute = !so_mute;
    }        
  }

  if(game_mode != MODE_POWER_ON){
    
    if(inputSystem.pressed(KEY_GAME_A) && inputSystem.pressed(KEY_GAME_B) && inputSystem.pressed(KEY_TIME) && inputSystem.down(KEY_UP)){
      closet_invincible = !closet_invincible;
    }
    
    if(inputSystem.pressed(KEY_GAME_A) && inputSystem.pressed(KEY_GAME_B) && inputSystem.pressed(KEY_TIME) && inputSystem.down(KEY_DOWN)){
      if(auto_play){
        auto_play = closet_invincible = false;
      }else{
        auto_play = closet_invincible = true;
      }
    }
  }
}

void gp_shelf_down(short frame){
  
  if(frame==1){
    gp_showImg(&canvas_S, &img_S[0]);
  }else if(frame==2){
    gp_showImg(&canvas_S, &img_S[1]);
    gp_showImg(&canvas_S, &img_S[3]);
  }else if(frame==3){
    gp_showImg(&canvas_S, &img_S[2]);
    gp_showImg(&canvas_S, &img_S[4]);
  }else if(frame==4){
    gp_showImg(&canvas_S, &img_S[2]);
    gp_reset();       
    get_hook = 0;
  }
}

void gp_game_up(){
  short rmax = sizeof(bucket_move) / sizeof(bucket_move[0]);
  short id = 0;
  short rid=0;
  
  digitalWrite(SCREEN_ONE_CS,0);      
  digitalWrite(SCREEN_TWO_CS,1);      
  backupPage.pushImage(0,0,320,240,bg2);
  
  if (platform_flash > 0){
    
    if (donkey_leave==-1){      
      
      if(donkey_pos==0){
        gp_showImg(&canvas_D, &img_D[3]);
      
      }else if(donkey_pos==1){
        gp_showImg(&canvas_D, &img_D[4]);
      
      }else if(donkey_pos==2){
        gp_showImg(&canvas_D, &img_D[5]);
      }
    }else{
      
      gp_showImg(&canvas_D, &img_D[donkey_pos]);
    }
  }
  
  for(int i=0; i<rmax; i++){
    if(bucket_move[i]>-1){   
      
      if(bucket_path[i] == 1)
          id = bucket_pos_1[bucket_move[i]];
      else if(bucket_path[i] == 2)
          id = bucket_pos_2[bucket_move[i]];
      else if(bucket_path[i] == 3)
          id = bucket_pos_3[bucket_move[i]];          
      
      if(id>=13){
        gp_showImg(&canvas_B, &img_B[id]);
      }
    }
  }
  
  if (hook_max==-1){    
    
    if (platform_flash >= 0){
      gp_showImg(&canvas_S, &img_S[0]);
    }
    
    if (platform_flash == 1){
      for(int i=1; i<4; i++){
        gp_showImg(&canvas_D, &img_P[i]);
      }
        
    }else if (platform_flash == -5){
      gp_restart();

    
    }else if (platform_flash <= 0){
      
      if (platform_flash == -2)
        tieRod = false;
                  
      int h = h = (platform_flash ^ (platform_flash >> 31)) - (platform_flash >> 31);
      
      gp_shelf_down(h);      
      gp_showImg(&canvas_D, &img_D[6]);
    }
  }

  if(tieRod){
    
    if (clockSystem.check(CLOCK_HOOK, 500) && role_walk_id != -1){    
      
      hook_count++;
      
      if(hook_reverse)
        hook_move--;
      else
        hook_move++;                        

      
      if(hook_move>=4 || hook_move<=0)
        hook_reverse = !hook_reverse;

      
      if (hook_count > 10)
        tieRod = false;
    }
    
    if (role_walk_id == 20 && hook_move==0 && get_hook==0){            
      
      if (clockSystem.check(CLOCK_JUMP_DELAY, 150)){
        
        role_walk_id = -1;
        
        get_hook = 2;
        
        stop_input = true;
        
        clockSystem.init(CLOCK_JUMP);
      }
    }

    gp_showImg(&canvas_PO, &img_PO[1]);
    
    if(get_hook==0){
      
      gp_showImg(&canvas_S, &img_S[3]);
      
      gp_showImg(&canvas_SH, &img_SH[hook_move]);

    
    }else if(hook_max!=-1){
      
      if(scoreAdd==0){
        
        if(hook_max==0){
          hook_max=-1;
          
          get_ready_hook = false;
        }
        
        if(get_hook>=4){                    
          
          role_flash = -1;
          
          stop_input = false;
          
          gp_steel_close();
          
          get_ready_hook = false;
          
          game_mode =  MODE_GAME;
        }
      
      }else{
        
        role_flash = 0;
        
        stop_input = true;                
        
        get_hook = 1;
      }
      
      gp_shelf_down(get_hook);
      
      clockSystem.init(CLOCK_ROLE_OUT);
    }
  
  }else{
    
    gp_showImg(&canvas_PO, &img_PO[0]);
    
    if(hook_max>0 && get_hook==0){
      gp_showImg(&canvas_S, &img_S[2]);
    }
  }

  
  for(int i=0; i<hook_max; i++){
    gp_showImg(&canvas_H, &img_H[i]);
  }

  
  if ((platform_flash%2==0)&&(platform_flash>0)){
    gp_showImg(&canvas_P, &img_P[0]);
  }      

  
  if(role_tieRod){
    rid = 17;
    gp_showImg(&canvas_R, &img_R[rid]);
  
  }else if(role_walk_id>16 && role_walk_id != -1){
    rid = role_walk_id;
    gp_showImg(&canvas_R, &img_R[rid]);
  
  }else if(role_walk_id>=11 && (role_flash==-1 || role_flash%2==1)){
    rid = role_walk[role_walk_id];
    gp_showImg(&canvas_R, &img_R[rid]);
  }

  
  if (platform_flash == 0){
    gp_showImg(&canvas_HE, &img_HE[heart_ani]);
  }

}

void gp_game_down(){
  short rmax = sizeof(bucket_move) / sizeof(bucket_move[0]);
  short id = 0;
  short rid=0;
  String str;
  bool pm;

  
  digitalWrite(SCREEN_ONE_CS,1);      
  digitalWrite(SCREEN_TWO_CS,0);      
  backupPage.pushImage(0,0,320,240,bg1);

  
  if (role_jump && role_walk_id==0){
    rid = role_walk_id;
    gp_showImg(&canvas_R, &img_R[1]);

  
  }else if (role_jump && role_walk_id==3){
    gp_showImg(&canvas_R, &img_R[5]);
  
  }else if (role_jump && role_walk_id==6 && (role_flash==-1 || role_flash%2==1)){
    gp_showImg(&canvas_R, &img_R[9]);
  
  }else if (role_jump && role_walk_id==7 && (role_flash==-1 || role_flash%2==1)){
    gp_showImg(&canvas_R, &img_R[11]);
  
  }else if((role_walk_id>-1 && role_walk_id<11) && (role_flash==-1 || role_flash%2==1)){    
    rid = role_walk[role_walk_id];
    gp_showImg(&canvas_R, &img_R[rid]);
  }
  
  for(int i=0; i<rmax; i++){
    if(bucket_move[i]>-1){   
      
      if(bucket_path[i] == 1)
          id = bucket_pos_1[bucket_move[i]];
      else if(bucket_path[i] == 2)
          id = bucket_pos_2[bucket_move[i]];
      else if(bucket_path[i] == 3)
          id = bucket_pos_3[bucket_move[i]];          
      
      if(id<13){
        gp_showImg(&canvas_B, &img_B[id]);
      }
    }
  }
  
  if (clockSystem.check( CLOCK_LIFE_ANI, 500)){
    if (life==2){
      if (life_next<3)
        life_next++;
    }else if (life==1){
      if (life_next<5)
        life_next++;
    }else if (life==0){
      life_next = 6;
    }
    
    
    if (auto_play)
      gp_autoplay();
  }  
  
  if(play_mode!=MODE_TIME){
    for(int i=0; i<3; i++){
      if(life_ani[life_next][i]==1){
        gp_showImg(&canvas_O, &img_O[i]);
      }
    }
  }
  
  if(play_mode==MODE_A || play_mode==MODE_TIME){
    gp_showImg(&canvas_AB, &img_AB[0]);
  }else if(play_mode==MODE_B){
    gp_showImg(&canvas_AB, &img_AB[1]);
  }
  
  gp_steel_update();
  
  scoreSprite.fillSprite(TFT_BLACK);    
  
  if(play_mode==MODE_TIME){
        
    if(c_set_clock > START_UP_CLOCK && auto_play){
      pm = c_pm;
      
      if(c_flash){
        
        if(String(c_minute).length()==1)
          str = String(c_hour) + ":0" + String(c_minute);
        else
          str = String(c_hour) + ":" + String(c_minute);
      }else{
        str = "";
      }      
      scoreSprite.drawString( str,0,0,FONT2);

    
    }else{
      pm = c_isPM();
      
      str = c_getHour()+":"+c_getMinute();
    }
    scoreSprite.drawString( str,0,0,FONT2);

    
    if(pm && str != ""){
      gp_showImg(&canvas_AP, &img_AP[1]);
    }else if(str != ""){
      gp_showImg(&canvas_AP, &img_AP[0]);
    }

  
  }else{
    sprintf(buffer, "%5d\n", score);
    scoreSprite.drawString(buffer,0,0,FONT2);    
  }
  scoreSprite.pushToSprite(&backupPage,240,204,TFT_BLACK);  
}

void gp_power_on_up(){
  
  digitalWrite(SCREEN_ONE_CS,0);      
  digitalWrite(SCREEN_TWO_CS,1);      
  backupPage.pushImage(0,0,320,240,bg2);
  
  for(int i=15; i<23; i++){
    gp_showImg(&canvas_R, &img_R[i]);
  }
  
  for(int i=13; i<28; i++){
    gp_showImg(&canvas_B, &img_B[i]);
  }
  
  for(int i=0; i<5; i++){
    gp_showImg(&canvas_S, &img_S[i]);
  }
  
  for(int i=0; i<7; i++){
    gp_showImg(&canvas_D, &img_D[i]);
  }
  
  gp_showImg(&canvas_P, &img_P[0]);
  for(int i=1; i<4; i++){
    gp_showImg(&canvas_D, &img_P[i]);
  }
  
  for(int i=0; i<4; i++){
    gp_showImg(&canvas_H, &img_H[i]);
  }
  
  for(int i=0; i<5; i++){
    gp_showImg(&canvas_SH, &img_SH[i]);
  }
  
  for(int i=0; i<2; i++){
    gp_showImg(&canvas_PO, &img_PO[i]);
  }
  
  for(int i=0; i<2; i++){
    gp_showImg(&canvas_HE, &img_HE[i]);
  }
}

void gp_power_on_down(){
  
  digitalWrite(SCREEN_ONE_CS,1);      
  digitalWrite(SCREEN_TWO_CS,0);      
  backupPage.pushImage(0,0,320,240,bg1);
  
  
  for(int i=0; i<15; i++){
    gp_showImg(&canvas_R, &img_R[i]);
  }

  
  for(int i=0; i<13; i++){
    gp_showImg(&canvas_B, &img_B[i]);
  }

  
  for(int i=0; i<5; i++){
    gp_showImg(&canvas_ST, &img_ST[i]);
  }

  
  for(int i=0; i<3; i++){
    gp_showImg(&canvas_O, &img_O[i]);
  }

  for(int i=0; i<2; i++){
    gp_showImg(&canvas_AB, &img_AB[i]);
  }  
  gp_showImg(&canvas_AP, &img_AP[0]);
  
  scoreSprite.fillSprite(TFT_BLACK);  
  scoreSprite.drawString("12:00",0,0,FONT2);    
  scoreSprite.pushToSprite(&backupPage,240,204,TFT_BLACK);
}

void gp_init(){
  c_init();  
  clockSystem.init();  
  backupPage.createSprite(320,240);
  backupPage.setSwapBytes(true);
  
  im_init();  
  so_init();
  
  scoreSprite.createSprite(120,32);
  scoreSprite.setTextColor(tft.color565(8,8,8),TFT_BLACK);
  scoreSprite.setFreeFont(FMB24);
  scoreSprite.setTextSize(2);
  
  debugSprite.createSprite(120,18);
  debugSprite.setTextColor(TFT_WHITE,TFT_BLACK);
  
  fpsSprite.createSprite(64,18);
  fpsSprite.setTextColor(TFT_WHITE,TFT_BLACK);

}

void gp_update(){  
  if (clockSystem.check(CLOCK_FLIP, 83)) {    
    
    if (clockSystem.check(CLOCK_FPS, 1000)){
      fps = fps_t;
      fps_t = 0;        
    }
    
    fps_t++;    
    so_loop();
    
    if (clockSystem.check( CLOCK_GAME_SPEED, 30000)){
      set_move_speed -= 250;
      if(set_move_speed<500)
        set_move_speed = 500;
    }
    
    if (game_mode == MODE_GAME && !stop_input && hook_max!=-1){
      
      if (clockSystem.check(CLOCK_ROLE_OUT, 7000) && role_walk_id == -1)
        gp_role_out();  
    }

    
    if (game_mode == MODE_PAUSE && life == 0 && play_mode==MODE_TIME){
        if (clockSystem.check(CLOCK_ROLE_OUT, 7000))
          gp_start_game(MODE_A);   
    }

    gp_input();    
    gp_donkey_update();    
    gp_score_update(); 
    
    if (hook_max==-1){
      
      if (clockSystem.check( CLOCK_JUMP, 500)){
        
        if ((platform_flash%2==0)&&(platform_flash>0))
          so_play(SOUND_1);    

        
        platform_flash--;

        
        if(platform_flash==0){
          so_play(SOUND_7);
          clockSystem.init( CLOCK_SCORE_ADD);
        }

        
        if(platform_flash==1)
          scoreAdd = 20;    

        
        if(platform_flash<0 && scoreAdd>0){
          platform_flash = 0;
          
          heart_ani++;
          if(heart_ani>1)
            heart_ani = 0;
        }
        
        if(platform_flash < -5)
          platform_flash = -5;                    
      }

    }else if (jump_hook){
      if (clockSystem.check( CLOCK_JUMP, 500)){            
        
        if (get_hook>0 && (get_ready_hook || get_hook!=2) && hook_max>0){
          get_hook++;

        
        }else if(get_hook==2 && !get_ready_hook){
          
          get_hook--;
          
          hook_max--;
          scoreAdd = hook_score[hook_max];
          
          get_ready_hook = true;

        
        }else if(hook_max>0){
          
          if(role_walk_id == 20)
            role_walk_id = 14;          
          
          role_walk_id++;
          
          if(role_walk_id==16)
            so_play(SOUND_7);
          if(role_walk_id>16){
            
            if(life<=0){
              
              if(game_mode != MODE_PAUSE)
                so_play(SOUND_6);
              gp_pause();                       
              role_flash = -1;
            }
            gp_reset();
            role_walk_id = -1;                    
            clockSystem.init(CLOCK_ROLE_OUT);   
          }
        }
      }
    }
    
    if( role_flash>-1){
      if (clockSystem.check(CLOCK_ROLE_FLASH, 250)){
        role_flash--;

        
        if(role_flash==2)
          so_play(SOUND_5);

        
        if(role_flash==0)
          clockSystem.init(CLOCK_ROLE_OUT);  

        if(role_flash==-1){
          
          if(life<=0 && !get_ready_hook && hook_max!=-1){
            if(game_mode != MODE_PAUSE)
              so_play(SOUND_6);    
            gp_pause();            
          }else{
            
            gp_set_speed();     
            
            stop_input = false;
            
            role_walk_id = -1;
          }               
        }
      }
    }

    if(game_mode != MODE_PAUSE){
      clockSystem.init(CLOCK_IN_TIME);   
    }    
    if ((game_mode == MODE_PAUSE) && clockSystem.check(CLOCK_IN_TIME, 60000)){
      auto_play = so_power_on_mute = true;
      gp_start_game(MODE_TIME);
    }

    if((play_mode== MODE_B) || (score>=100) || (role_walk_id == 10) || (steel_path[0]>-1 || steel_path[1]>-1 || steel_path[2]>-1))
      gp_steel_move();      
    
    if(role_walk_id==10)
      gp_steel_collision(true);        
    if(flip){           
      if(game_mode == MODE_POWER_ON)
        gp_power_on_down();           
      else if(game_mode == MODE_GAME)
        gp_game_down();               
      fpsSprite.fillSprite(TFT_BLACK);
      fpsSprite.drawString("FPS:"+String(fps),0,0,FONT2);
      fpsSprite.pushToSprite(&backupPage,2,2,TFT_BLACK);
      
    }else{
      
      if(game_mode == MODE_POWER_ON)
        gp_power_on_up();             
      else if(game_mode == MODE_GAME)
        gp_game_up();                 
    }    
    flip = !flip;    
    backupPage.pushSprite(0,0);
  }  
}

#endif
