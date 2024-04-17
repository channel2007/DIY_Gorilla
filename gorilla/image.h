#ifndef _IMAGE_H
#define _IMAGE_H

#define NEW_KONG

#include "img/bg1.h"
#include "img/bg2.h"
#include "img/r.h"
#include "img/b.h"
#include "img/st.h"
#include "img/o.h"
#include "img/ab.h"
#include "img/ap.h"
#include "img/s.h"
#include "img/d.h"
#include "img/p.h"
#include "img/h.h"
#include "img/sh.h"
#include "img/po.h"
#include "img/he.h"
#include "img/bat.h"
#include "img/nc.h"
#include "img/ani.h"


TFT_eSprite canvas_R = TFT_eSprite(&tft);

TFT_eSprite canvas_B = TFT_eSprite(&tft);

TFT_eSprite canvas_ST = TFT_eSprite(&tft);

TFT_eSprite canvas_O = TFT_eSprite(&tft);

TFT_eSprite canvas_AB = TFT_eSprite(&tft);

TFT_eSprite canvas_AP = TFT_eSprite(&tft);

TFT_eSprite canvas_S = TFT_eSprite(&tft);

TFT_eSprite canvas_D = TFT_eSprite(&tft);

TFT_eSprite canvas_P = TFT_eSprite(&tft);

TFT_eSprite canvas_H = TFT_eSprite(&tft);

TFT_eSprite canvas_SH = TFT_eSprite(&tft);

TFT_eSprite canvas_PO = TFT_eSprite(&tft);

TFT_eSprite canvas_HE = TFT_eSprite(&tft);

TFT_eSprite canvas_BAT = TFT_eSprite(&tft);

TFT_eSprite canvas_NC = TFT_eSprite(&tft);

TFT_eSprite canvas_FIRE = TFT_eSprite(&tft);

TFT_eSprite canvas_BIRD = TFT_eSprite(&tft);

TFT_eSprite canvas_STAR = TFT_eSprite(&tft);

TFT_eSprite scoreSprite= TFT_eSprite(&tft);

TFT_eSprite fpsSprite= TFT_eSprite(&tft);

TFT_eSprite debugSprite= TFT_eSprite(&tft);


image_struct img_R[23];

image_struct img_B[28];

image_struct img_ST[5];

image_struct img_O[3];

image_struct img_AB[2];

image_struct img_AP[2];

image_struct img_S[5];

image_struct img_D[7];

image_struct img_P[4];

image_struct img_H[4];

image_struct img_SH[5];

image_struct img_PO[2];

image_struct img_HE[2];

image_struct img_BAT[5];

image_struct img_NC[11];

image_struct img_FIRE[3];

image_struct img_BIRD[5];

image_struct img_STAR;


short nc_x[][10] = {{254,257,254,254,253,254,254,254,254,254},{268,271,268,268,267,268,268,268,268,268},{287,290,287,287,286,287,287,287,287,287},{301,304,301,301,300,301,301,301,301,301}};
short nc_y[][10] = {{214,214,214,214,214,214,214,214,214,214},{214,214,214,214,214,214,214,214,214,214},{214,214,214,214,214,214,214,214,214,214},{214,214,214,214,214,214,214,214,214,214}};
  

short star_x[] = { 43, 43, 96,139,194,194,234,234,193,193,142,142, 92, 32, 40,   41, 41, 41,129,176,208};
short star_y[] = {158,121,151,147,141,106,137, 64, 61, 28, 56, 23, 50, 45, 11,  183,124,124,120,120, 88};




void im_init(){

  
  canvas_R.createSprite(47,53);
  
  canvas_B.createSprite(22,22);
  
  canvas_ST.createSprite(39,22);
  
  canvas_O.createSprite(18,28);
  
  canvas_AB.createSprite(44,12);
  
  canvas_AP.createSprite(19,12);
  
  canvas_S.createSprite(74,86);
  
  canvas_D.createSprite(64,68);
  
  canvas_P.createSprite(182,10);
  
  canvas_H.createSprite(12,49);
  
  canvas_SH.createSprite(26,38);
  
  canvas_PO.createSprite(16,17);
  
  canvas_HE.createSprite(14,15);
  
  canvas_BAT.createSprite(24,12);
  
  canvas_NC.createSprite(12,22);
  
  canvas_FIRE.createSprite(20,39);
  
  canvas_BIRD.createSprite(13,12);
  
  canvas_STAR.createSprite(9,9);

  
  img_R[0].img  = r1;  img_R[0].w = 31; img_R[0].h = 41; img_R[0].x  = 31; img_R[0].y  = 168;
  img_R[1].img  = r2;  img_R[1].w = 34; img_R[1].h = 39; img_R[1].x  = 26; img_R[1].y  = 131;
  img_R[2].img  = r3;  img_R[2].w = 34; img_R[2].h = 41; img_R[2].x  = 81; img_R[2].y  = 161;
  img_R[3].img  = r4;  img_R[3].w = 34; img_R[3].h = 41; img_R[3].x  =129; img_R[3].y  = 157;
  img_R[4].img  = r5;  img_R[4].w = 34; img_R[4].h = 41; img_R[4].x  =179; img_R[4].y  = 151;
  img_R[5].img  = r6;  img_R[5].w = 34; img_R[5].h = 39; img_R[5].x  =179; img_R[5].y  = 116;
  img_R[6].img  = r7;  img_R[6].w = 30; img_R[6].h = 41; img_R[6].x  =223; img_R[6].y  = 147;
  img_R[7].img  = r8;  img_R[7].w = 35; img_R[7].h = 41; img_R[7].x  =225; img_R[7].y  =  74;
  img_R[8].img  = r9;  img_R[8].w = 33; img_R[8].h = 41; img_R[8].x  =177; img_R[8].y  =  70;
  img_R[9].img  =r10;  img_R[9].w = 37; img_R[9].h = 39; img_R[9].x  =179; img_R[9].y  =  38;
  img_R[10].img =r11; img_R[10].w = 36; img_R[10].h= 41; img_R[10].x =131; img_R[10].y =  65;
  img_R[11].img =r12; img_R[11].w = 34; img_R[11].h= 39; img_R[11].x =131; img_R[11].y =  33;
  img_R[12].img =r13; img_R[12].w = 34; img_R[12].h= 41; img_R[12].x = 77; img_R[12].y =  60;
  img_R[13].img =r14; img_R[13].w = 30; img_R[13].h= 41; img_R[13].x = 23; img_R[13].y =  55;
  img_R[14].img =r15; img_R[14].w = 30; img_R[14].h= 41; img_R[14].x = 30; img_R[14].y =  21;
  img_R[15].img =r16; img_R[15].w = 32; img_R[15].h= 41; img_R[15].x = 32; img_R[15].y = 193;
  img_R[16].img =r17; img_R[16].w = 37; img_R[16].h= 39; img_R[16].x = 40; img_R[16].y = 132;
  img_R[17].img =r18; img_R[17].w = 41; img_R[17].h= 39; img_R[17].x = 36; img_R[17].y = 132;
  img_R[18].img =r19; img_R[18].w = 32; img_R[18].h= 41; img_R[18].x =114; img_R[18].y = 130;
  img_R[19].img =r20; img_R[19].w = 32; img_R[19].h= 41; img_R[19].x =168; img_R[19].y = 130;
  img_R[20].img =r21; img_R[20].w = 34; img_R[20].h= 53; img_R[20].x =199; img_R[20].y = 98;
  img_R[21].img =r22; img_R[21].w = 37; img_R[21].h= 34; img_R[21].x =221; img_R[21].y = 154;
  img_R[22].img =r23; img_R[22].w = 47; img_R[22].h= 39; img_R[22].x =243; img_R[22].y = 199;

  
  img_B[0].img  = b1;  img_B[0].w  = 17; img_B[0].h  = 17; img_B[0].x  =  7; img_B[0].y  = 196;
  img_B[1].img  = b2;  img_B[1].w  = 17; img_B[1].h  = 17; img_B[1].x  = 60; img_B[1].y  = 189;
  img_B[2].img  = b3;  img_B[2].w  = 17; img_B[2].h  = 17; img_B[2].x  =114; img_B[2].y  = 183;
  img_B[3].img  = b4;  img_B[3].w  = 17; img_B[3].h  = 17; img_B[3].x  =163; img_B[3].y  = 177;
  img_B[4].img  = b5;  img_B[4].w  = 17; img_B[4].h  = 17; img_B[4].x  =212; img_B[4].y  = 172;
  img_B[5].img  = b6;  img_B[5].w  = 17; img_B[5].h  = 17; img_B[5].x  =259; img_B[5].y  = 168;
  img_B[6].img  = b7;  img_B[6].w  = 17; img_B[6].h  = 17; img_B[6].x  =258; img_B[6].y  = 104;
  img_B[7].img  = b8;  img_B[7].w  = 17; img_B[7].h  = 17; img_B[7].x  =211; img_B[7].y  =  96;
  img_B[8].img  = b9;  img_B[8].w  = 17; img_B[8].h  = 17; img_B[8].x  =164; img_B[8].y  =  91;
  img_B[9].img  = b10; img_B[9].w  = 17; img_B[9].h  = 17; img_B[9].x  =114; img_B[9].y  =  85;
  img_B[10].img = b11; img_B[10].w = 17; img_B[10].h = 17; img_B[10].x = 60; img_B[10].y =  79;
  img_B[11].img = b12; img_B[11].w = 17; img_B[11].h = 17; img_B[11].x =  6; img_B[11].y =  74;
  img_B[12].img = b13; img_B[12].w = 17; img_B[12].h = 17; img_B[12].x =  6; img_B[12].y =  27;
  img_B[13].img = b14; img_B[13].w = 17; img_B[13].h = 17; img_B[13].x = 13; img_B[13].y = 221;
  img_B[14].img = b15; img_B[14].w = 17; img_B[14].h = 17; img_B[14].x = 60; img_B[14].y = 216;
  img_B[15].img = b16; img_B[15].w = 17; img_B[15].h = 17; img_B[15].x = 91; img_B[15].y = 214;
  img_B[16].img = b17; img_B[16].w = 17; img_B[16].h = 17; img_B[16].x =121; img_B[16].y = 212;
  img_B[17].img = b18; img_B[17].w = 17; img_B[17].h = 17; img_B[17].x =151; img_B[17].y = 210;
  img_B[18].img = b19; img_B[18].w = 17; img_B[18].h = 17; img_B[18].x =179; img_B[18].y = 208;
  img_B[19].img = b20; img_B[19].w = 17; img_B[19].h = 17; img_B[19].x =179; img_B[19].y = 179;
  img_B[20].img = b21; img_B[20].w = 17; img_B[20].h = 17; img_B[20].x =122; img_B[20].y = 179;
  img_B[21].img = b22; img_B[21].w = 17; img_B[21].h = 17; img_B[21].x = 60; img_B[21].y = 180;
  img_B[22].img = b23; img_B[22].w = 22; img_B[22].h = 22; img_B[22].x = 57; img_B[22].y = 124;
  img_B[23].img = b24; img_B[23].w = 22; img_B[23].h = 22; img_B[23].x =117; img_B[23].y = 121;
  img_B[24].img = b25; img_B[24].w = 22; img_B[24].h = 22; img_B[24].x =175; img_B[24].y = 120;
  img_B[25].img = b26; img_B[25].w = 19; img_B[25].h = 18; img_B[25].x = 58; img_B[25].y =  84;
  img_B[26].img = b27; img_B[26].w = 19; img_B[26].h = 18; img_B[26].x =120; img_B[26].y =  84;
  img_B[27].img = b28; img_B[27].w = 19; img_B[27].h = 18; img_B[27].x =177; img_B[27].y =  84;

  
  img_ST[4].img = st1; img_ST[4].w = 37; img_ST[4].h = 21; img_ST[4].x =225; img_ST[4].y  = 25;  
  img_ST[3].img = st2; img_ST[3].w = 38; img_ST[3].h = 21; img_ST[3].x =176; img_ST[3].y  = 20;
  img_ST[2].img = st3; img_ST[2].w = 39; img_ST[2].h = 21; img_ST[2].x =125; img_ST[2].y  = 13;
  img_ST[1].img = st4; img_ST[1].w = 39; img_ST[1].h = 21; img_ST[1].x = 76; img_ST[1].y  =  9;
  img_ST[0].img = st5; img_ST[0].w = 39; img_ST[0].h = 21; img_ST[0].x = 28; img_ST[0].y  =  3;

  
  img_O[0].img  = o;  img_O[0].w = 18; img_O[0].h = 25; img_O[0].x  =136; img_O[0].y  = 212;
  img_O[1].img  = o;  img_O[1].w = 18; img_O[1].h = 25; img_O[1].x  =157; img_O[1].y  = 212;
  img_O[2].img  = o;  img_O[2].w = 18; img_O[2].h = 25; img_O[2].x  =178; img_O[2].y  = 212;

  
  img_AB[0].img  = a;  img_AB[0].w = 44; img_AB[0].h = 8; img_AB[0].x  = 270; img_AB[0].y  = 50;
  img_AB[1].img  = b;  img_AB[1].w = 44; img_AB[1].h = 8; img_AB[1].x  = 270; img_AB[1].y  = 67;

  
  img_AP[0].img  = am;  img_AP[0].w = 19; img_AP[0].h = 10; img_AP[0].x  = 227; img_AP[0].y  = 214;
  img_AP[1].img  = pm;  img_AP[1].w = 18; img_AP[1].h = 10; img_AP[1].x  = 228; img_AP[1].y  = 226;

  
  img_S[0].img  = s1;  img_S[0].w = 74; img_S[0].h = 66; img_S[0].x  = 246; img_S[0].y  = 12;
  img_S[1].img  = s2;  img_S[1].w = 39; img_S[1].h = 75; img_S[1].x  = 237; img_S[1].y  = 92;
  img_S[2].img  = s3;  img_S[2].w = 44; img_S[2].h = 86; img_S[2].x  = 276; img_S[2].y  = 126;
  img_S[3].img  = s4;  img_S[3].w = 62; img_S[3].h = 36; img_S[3].x  = 258; img_S[3].y  = 78;
  img_S[4].img  = s5;  img_S[4].w = 34; img_S[4].h = 41; img_S[4].x  = 281; img_S[4].y  = 191;

  
  img_D[0].img  = d1;  img_D[0].w = 61; img_D[0].h = 50; img_D[0].x  = 38; img_D[0].y  = 23;
  img_D[1].img  = d2;  img_D[1].w = 59; img_D[1].h = 50; img_D[1].x  = 98; img_D[1].y  = 23;
  img_D[2].img  = d3;  img_D[2].w = 61; img_D[2].h = 50; img_D[2].x  =156; img_D[2].y  = 23;
  img_D[3].img  = d4;  img_D[3].w = 48; img_D[3].h = 67; img_D[3].x  = 43; img_D[3].y  =  6;
  img_D[4].img  = d5;  img_D[4].w = 47; img_D[4].h = 68; img_D[4].x  =104; img_D[4].y  =  5;
  img_D[5].img  = d6;  img_D[5].w = 48; img_D[5].h = 67; img_D[5].x  =163; img_D[5].y  =  6;
  img_D[6].img  = d7;  img_D[6].w = 48; img_D[6].h = 57; img_D[6].x  =198; img_D[6].y  =183;

  
  img_P[0].img  = p1;  img_P[0].w =180; img_P[0].h = 10; img_P[0].x  = 34; img_P[0].y  = 75;
  img_P[1].img  = p2;  img_P[1].w = 36; img_P[1].h = 60; img_P[1].x  =  8; img_P[1].y  = 91;
  img_P[2].img  = p3;  img_P[2].w = 24; img_P[2].h = 66; img_P[2].x  = 84; img_P[2].y  = 98;
  img_P[3].img  = p4;  img_P[3].w = 56; img_P[3].h = 28; img_P[3].x  =140; img_P[3].y  =106;

  
  img_H[0].img  = h1;  img_H[0].w = 12; img_H[0].h = 49; img_H[0].x  = 214; img_H[0].y  = 35;
  img_H[1].img  = h2;  img_H[1].w =  9; img_H[1].h = 48; img_H[1].x  = 221; img_H[1].y  = 36;
  img_H[2].img  = h3;  img_H[2].w =  7; img_H[2].h = 48; img_H[2].x  = 229; img_H[2].y  = 36;
  img_H[3].img  = h4;  img_H[3].w =  8; img_H[3].h = 49; img_H[3].x  = 235; img_H[3].y  = 35;

  
  img_SH[0].img  = sh1;  img_SH[0].w = 26; img_SH[0].h = 27; img_SH[0].x  = 228; img_SH[0].y  = 85;
  img_SH[1].img  = sh2;  img_SH[1].w = 18; img_SH[1].h = 34; img_SH[1].x  = 239; img_SH[1].y  = 90;
  img_SH[2].img  = sh3;  img_SH[2].w =  8; img_SH[2].h = 37; img_SH[2].x  = 255; img_SH[2].y  = 93;
  img_SH[3].img  = sh4;  img_SH[3].w = 15; img_SH[3].h = 32; img_SH[3].x  = 263; img_SH[3].y  = 96;
  img_SH[4].img  = sh5;  img_SH[4].w = 22; img_SH[4].h = 21; img_SH[4].x  = 270; img_SH[4].y  = 97;

  
  img_PO[0].img  = po1;  img_PO[0].w = 16; img_PO[0].h = 7; img_PO[0].x  = 28; img_PO[0].y  = 169;
  img_PO[1].img  = po2;  img_PO[1].w = 13; img_PO[1].h =12; img_PO[1].x  = 26; img_PO[1].y  = 150;

  
  img_HE[0].img  = he1;  img_HE[0].w = 14; img_HE[0].h = 15; img_HE[0].x  = 32; img_HE[0].y  = 7;
  img_HE[1].img  = he2;  img_HE[1].w =  8; img_HE[1].h = 10; img_HE[1].x  = 25; img_HE[1].y  =20;

  
  img_BAT[0].img  = bat1;  img_BAT[0].w = 24; img_BAT[0].h = 12; img_BAT[0].x  = 290; img_BAT[0].y  = 31;
  img_BAT[1].img  = bat2;  img_BAT[1].w = 24; img_BAT[1].h = 12; img_BAT[1].x  = 290; img_BAT[1].y  = 31;
  img_BAT[2].img  = bat3;  img_BAT[2].w = 24; img_BAT[2].h = 12; img_BAT[2].x  = 290; img_BAT[2].y  = 31;
  img_BAT[3].img  = bat4;  img_BAT[3].w = 24; img_BAT[3].h = 12; img_BAT[3].x  = 290; img_BAT[3].y  = 31;
  img_BAT[4].img  = bat5;  img_BAT[4].w = 24; img_BAT[4].h = 12; img_BAT[4].x  = 290; img_BAT[4].y  = 31;

  
  img_NC[0].img   = n0;  img_NC[0].w  = 10; img_NC[0].h = 22; img_NC[0].x   = 254; img_NC[0].y  = 214;
  img_NC[1].img   = n1;  img_NC[1].w  =  4; img_NC[1].h = 22; img_NC[1].x   = 257; img_NC[1].y  = 214;
  img_NC[2].img   = n2;  img_NC[2].w  = 10; img_NC[2].h = 22; img_NC[2].x   = 254; img_NC[2].y  = 214;
  img_NC[3].img   = n3;  img_NC[3].w  = 10; img_NC[3].h = 22; img_NC[3].x   = 254; img_NC[3].y  = 214;
  img_NC[4].img   = n4;  img_NC[4].w  = 12; img_NC[4].h = 22; img_NC[4].x   = 253; img_NC[4].y  = 214;
  img_NC[5].img   = n5;  img_NC[5].w  = 10; img_NC[5].h = 22; img_NC[5].x   = 254; img_NC[5].y  = 214;
  img_NC[6].img   = n6;  img_NC[6].w  = 10; img_NC[6].h = 22; img_NC[6].x   = 254; img_NC[6].y  = 214;
  img_NC[7].img   = n7;  img_NC[7].w  = 10; img_NC[7].h = 22; img_NC[7].x   = 254; img_NC[7].y  = 214;
  img_NC[8].img   = n8;  img_NC[8].w  = 10; img_NC[8].h = 22; img_NC[8].x   = 254; img_NC[8].y  = 214;
  img_NC[9].img   = n9;  img_NC[9].w  = 10; img_NC[9].h = 22; img_NC[9].x   = 254; img_NC[9].y  = 214;
  img_NC[10].img  = nc;  img_NC[10].w = 3; img_NC[10].h = 12; img_NC[10].x  = 281; img_NC[10].y = 219;

  
  img_FIRE[0].img = f1; img_FIRE[0].w = 20; img_FIRE[0].h = 39; img_FIRE[0].x  = 2; img_FIRE[0].y  = 167;
  img_FIRE[1].img = f2; img_FIRE[1].w = 20; img_FIRE[1].h = 39; img_FIRE[1].x  = 3; img_FIRE[1].y  = 167;
  img_FIRE[2].img = f3; img_FIRE[2].w = 20; img_FIRE[2].h = 39; img_FIRE[2].x  = 3; img_FIRE[2].y  = 167;

  
  img_BIRD[0].img = bi1; img_BIRD[0].w = 11; img_BIRD[0].h = 12; img_BIRD[0].x = 8; img_BIRD[0].y = 105;
  img_BIRD[1].img = bi2; img_BIRD[1].w = 13; img_BIRD[1].h = 11; img_BIRD[1].x = 8; img_BIRD[1].y = 105;
  img_BIRD[2].img = bi3; img_BIRD[2].w = 12; img_BIRD[2].h =  8; img_BIRD[2].x = 8; img_BIRD[2].y = 105;
  img_BIRD[3].img = bi4; img_BIRD[3].w = 11; img_BIRD[3].h =  9; img_BIRD[3].x = 8; img_BIRD[3].y = 105;
  img_BIRD[4].img = bi5; img_BIRD[4].w = 12; img_BIRD[4].h =  8; img_BIRD[4].x = 8; img_BIRD[4].y = 105;

  
  img_STAR.img = star; img_STAR.w = 9; img_STAR.h = 9; img_STAR.x = 43; img_STAR.y = 158;

}

#endif
