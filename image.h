#ifndef _IMAGE_H
#define _IMAGE_H

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

void im_init(){
  canvas_R.createSprite(47,53);
  canvas_B.createSprite(22,22);
  canvas_ST.createSprite(39,22);
  canvas_O.createSprite(18,28);
  canvas_AB.createSprite(43,12);
  canvas_AP.createSprite(16,12);
  canvas_S.createSprite(73,84);
  canvas_D.createSprite(64,65);
  canvas_P.createSprite(182,10);
  canvas_H.createSprite(11,49);
  canvas_SH.createSprite(26,38);
  canvas_PO.createSprite(13,17);
  canvas_HE.createSprite(12,14);

  // 結構-主角.
  img_R[0].img  = r1;  img_R[0].w = 30; img_R[0].h = 38; img_R[0].x  = 27; img_R[0].y  = 171;
  img_R[1].img  = r2;  img_R[1].w = 30; img_R[1].h = 35; img_R[1].x  = 30; img_R[1].y  = 136;
  img_R[2].img  = r3;  img_R[2].w = 30; img_R[2].h = 38; img_R[2].x  = 84; img_R[2].y  = 165;
  img_R[3].img  = r4;  img_R[3].w = 28; img_R[3].h = 36; img_R[3].x  =132; img_R[3].y  = 161;
  img_R[4].img  = r5;  img_R[4].w = 27; img_R[4].h = 37; img_R[4].x  =183; img_R[4].y  = 155;
  img_R[5].img  = r6;  img_R[5].w = 28; img_R[5].h = 37; img_R[5].x  =183; img_R[5].y  = 121;
  img_R[6].img  = r7;  img_R[6].w = 31; img_R[6].h = 36; img_R[6].x  =228; img_R[6].y  = 150;
  img_R[7].img  = r8;  img_R[7].w = 32; img_R[7].h = 36; img_R[7].x  =225; img_R[7].y  =  79;
  img_R[8].img  = r9;  img_R[8].w = 26; img_R[8].h = 37; img_R[8].x  =183; img_R[8].y  =  73;
  img_R[9].img  =r10;  img_R[9].w = 30; img_R[9].h = 32; img_R[9].x  =182; img_R[9].y  =  41;
  img_R[10].img =r11; img_R[10].w = 29; img_R[10].h= 36; img_R[10].x =132; img_R[10].y =  70;
  img_R[11].img =r12; img_R[11].w = 28; img_R[11].h= 31; img_R[11].x =133; img_R[11].y =  35;
  img_R[12].img =r13; img_R[12].w = 28; img_R[12].h= 37; img_R[12].x = 81; img_R[12].y =  63;
  img_R[13].img =r14; img_R[13].w = 29; img_R[13].h= 36; img_R[13].x = 29; img_R[13].y =  58;
  img_R[14].img =r15; img_R[14].w = 33; img_R[14].h= 38; img_R[14].x = 28; img_R[14].y =  24;
  img_R[15].img =r16; img_R[15].w = 30; img_R[15].h= 38; img_R[15].x = 30; img_R[15].y = 198;
  img_R[16].img =r17; img_R[16].w = 36; img_R[16].h= 38; img_R[16].x = 42; img_R[16].y = 139;
  img_R[17].img =r18; img_R[17].w = 42; img_R[17].h= 34; img_R[17].x = 36; img_R[17].y = 139;
  img_R[18].img =r19; img_R[18].w = 35; img_R[18].h= 34; img_R[18].x =114; img_R[18].y = 138;
  img_R[19].img =r20; img_R[19].w = 33; img_R[19].h= 36; img_R[19].x =164; img_R[19].y = 135;
  img_R[20].img =r21; img_R[20].w = 35; img_R[20].h= 50; img_R[20].x =198; img_R[20].y = 100;
  img_R[21].img =r22; img_R[21].w = 32; img_R[21].h= 37; img_R[21].x =223; img_R[21].y = 153;
  img_R[22].img =r23; img_R[22].w = 31; img_R[22].h= 38; img_R[22].x =246; img_R[22].y = 198;

  // 結構-滾筒.
  img_B[0].img  = b1;  img_B[0].w  = 16; img_B[0].h  = 18; img_B[0].x  =  8; img_B[0].y  = 196;
  img_B[1].img  = b2;  img_B[1].w  = 16; img_B[1].h  = 17; img_B[1].x  = 61; img_B[1].y  = 189;
  img_B[2].img  = b3;  img_B[2].w  = 16; img_B[2].h  = 17; img_B[2].x  =114; img_B[2].y  = 183;
  img_B[3].img  = b4;  img_B[3].w  = 16; img_B[3].h  = 19; img_B[3].x  =163; img_B[3].y  = 176;
  img_B[4].img  = b5;  img_B[4].w  = 16; img_B[4].h  = 18; img_B[4].x  =213; img_B[4].y  = 171;
  img_B[5].img  = b6;  img_B[5].w  = 17; img_B[5].h  = 17; img_B[5].x  =259; img_B[5].y  = 167;
  img_B[6].img  = b7;  img_B[6].w  = 16; img_B[6].h  = 18; img_B[6].x  =259; img_B[6].y  = 104;
  img_B[7].img  = b8;  img_B[7].w  = 16; img_B[7].h  = 18; img_B[7].x  =212; img_B[7].y  =  96;
  img_B[8].img  = b9;  img_B[8].w  = 17; img_B[8].h  = 18; img_B[8].x  =164; img_B[8].y  =  90;
  img_B[9].img  = b10; img_B[9].w  = 16; img_B[9].h  = 17; img_B[9].x  =115; img_B[9].y  =  85;
  img_B[10].img = b11; img_B[10].w = 16; img_B[10].h = 18; img_B[10].x = 61; img_B[10].y =  78;
  img_B[11].img = b12; img_B[11].w = 16; img_B[11].h = 18; img_B[11].x =  7; img_B[11].y =  73;
  img_B[12].img = b13; img_B[12].w = 17; img_B[12].h = 17; img_B[12].x =  6; img_B[12].y =  27;
  img_B[13].img = b14; img_B[13].w = 15; img_B[13].h = 19; img_B[13].x = 14; img_B[13].y = 221;
  img_B[14].img = b15; img_B[14].w = 14; img_B[14].h = 17; img_B[14].x = 61; img_B[14].y = 217;
  img_B[15].img = b16; img_B[15].w = 15; img_B[15].h = 18; img_B[15].x = 92; img_B[15].y = 214;
  img_B[16].img = b17; img_B[16].w = 15; img_B[16].h = 17; img_B[16].x =122; img_B[16].y = 212;
  img_B[17].img = b18; img_B[17].w = 14; img_B[17].h = 18; img_B[17].x =153; img_B[17].y = 210;
  img_B[18].img = b19; img_B[18].w = 14; img_B[18].h = 18; img_B[18].x =180; img_B[18].y = 207;
  img_B[19].img = b20; img_B[19].w = 15; img_B[19].h = 17; img_B[19].x =180; img_B[19].y = 179;
  img_B[20].img = b21; img_B[20].w = 14; img_B[20].h = 17; img_B[20].x =124; img_B[20].y = 178;
  img_B[21].img = b22; img_B[21].w = 15; img_B[21].h = 18; img_B[21].x = 61; img_B[21].y = 179;
  img_B[22].img = b23; img_B[22].w = 18; img_B[22].h = 20; img_B[22].x = 59; img_B[22].y = 125;
  img_B[23].img = b24; img_B[23].w = 18; img_B[23].h = 19; img_B[23].x =120; img_B[23].y = 122;
  img_B[24].img = b25; img_B[24].w = 17; img_B[24].h = 19; img_B[24].x =179; img_B[24].y = 122;
  img_B[25].img = b26; img_B[25].w = 19; img_B[25].h = 19; img_B[25].x = 58; img_B[25].y =  84;
  img_B[26].img = b27; img_B[26].w = 19; img_B[26].h = 18; img_B[26].x =120; img_B[26].y =  84;
  img_B[27].img = b28; img_B[27].w = 19; img_B[27].h = 18; img_B[27].x =177; img_B[27].y =  84;

  // 結構-鋼架.
  img_ST[4].img = st1; img_ST[4].w = 39; img_ST[4].h = 22; img_ST[4].x =224; img_ST[4].y  = 23;
  img_ST[3].img = st2; img_ST[3].w = 39; img_ST[3].h = 21; img_ST[3].x =175; img_ST[3].y  = 19;
  img_ST[2].img = st3; img_ST[2].w = 39; img_ST[2].h = 20; img_ST[2].x =125; img_ST[2].y  = 13;
  img_ST[1].img = st4; img_ST[1].w = 39; img_ST[1].h = 21; img_ST[1].x = 76; img_ST[1].y  =  8;
  img_ST[0].img = st5; img_ST[0].w = 39; img_ST[0].h = 20; img_ST[0].x = 28; img_ST[0].y  =  3;

  // 結構-隻數.
  img_O[0].img  = o;  img_O[0].w = 18; img_O[0].h = 28; img_O[0].x  =136; img_O[0].y  = 210;
  img_O[1].img  = o;  img_O[1].w = 18; img_O[1].h = 28; img_O[1].x  =157; img_O[1].y  = 210;
  img_O[2].img  = o;  img_O[2].w = 18; img_O[2].h = 28; img_O[2].x  =177; img_O[2].y  = 210;

  // 結構-GAME A、GAME B.
  img_AB[0].img  = a;  img_AB[0].w = 43; img_AB[0].h = 11; img_AB[0].x  = 271; img_AB[0].y  = 48;
  img_AB[1].img  = b;  img_AB[1].w = 43; img_AB[1].h = 12; img_AB[1].x  = 271; img_AB[1].y  = 65;

  // 結構-AM、PM.
  img_AP[0].img  = am;  img_AP[0].w = 16; img_AP[0].h = 12; img_AP[0].x  = 212; img_AP[0].y  = 205;
  img_AP[1].img  = pm;  img_AP[1].w = 16; img_AP[1].h = 12; img_AP[1].x  = 212; img_AP[1].y  = 221;

  // 結構-下架子.
  img_S[0].img  = s1;  img_S[0].w = 73; img_S[0].h = 67; img_S[0].x  = 247; img_S[0].y  = 11;
  img_S[1].img  = s2;  img_S[1].w = 35; img_S[1].h = 73; img_S[1].x  = 241; img_S[1].y  = 92;
  img_S[2].img  = s3;  img_S[2].w = 43; img_S[2].h = 84; img_S[2].x  = 277; img_S[2].y  = 127;
  img_S[3].img  = s4;  img_S[3].w = 62; img_S[3].h = 35; img_S[3].x  = 258; img_S[3].y  = 79;
  img_S[4].img  = s5;  img_S[4].w = 29; img_S[4].h = 38; img_S[4].x  = 281; img_S[4].y  = 195;

  // 結構-大金剛.
  img_D[0].img  = d1;  img_D[0].w = 62; img_D[0].h = 43; img_D[0].x  = 37; img_D[0].y  = 28;
  img_D[1].img  = d2;  img_D[1].w = 57; img_D[1].h = 44; img_D[1].x  = 99; img_D[1].y  = 26;
  img_D[2].img  = d3;  img_D[2].w = 64; img_D[2].h = 44; img_D[2].x  =153; img_D[2].y  = 27;
  img_D[3].img  = d4;  img_D[3].w = 45; img_D[3].h = 64; img_D[3].x  = 47; img_D[3].y  =  7;
  img_D[4].img  = d5;  img_D[4].w = 38; img_D[4].h = 64; img_D[4].x  =109; img_D[4].y  =  6;
  img_D[5].img  = d6;  img_D[5].w = 51; img_D[5].h = 65; img_D[5].x  =160; img_D[5].y  =  6;
  img_D[6].img  = d7;  img_D[6].w = 45; img_D[6].h = 53; img_D[6].x  =200; img_D[6].y  =183;

  // 結構-平台.
  img_P[0].img  = p1;  img_P[0].w =182; img_P[0].h = 10; img_P[0].x  = 32; img_P[0].y  = 75;
  img_P[1].img  = p2;  img_P[1].w = 34; img_P[1].h = 57; img_P[1].x  = 10; img_P[1].y  = 90;
  img_P[2].img  = p3;  img_P[2].w = 21; img_P[2].h = 62; img_P[2].x  = 85; img_P[2].y  =101;
  img_P[3].img  = p4;  img_P[3].w = 47; img_P[3].h = 24; img_P[3].x  =145; img_P[3].y  =108;

  // 結構-勾子.
  img_H[0].img  = h1;  img_H[0].w = 11; img_H[0].h = 49; img_H[0].x  = 214; img_H[0].y  = 35;
  img_H[1].img  = h2;  img_H[1].w =  7; img_H[1].h = 47; img_H[1].x  = 221; img_H[1].y  = 37;
  img_H[2].img  = h3;  img_H[2].w =  8; img_H[2].h = 47; img_H[2].x  = 228; img_H[2].y  = 37;
  img_H[3].img  = h4;  img_H[3].w =  8; img_H[3].h = 49; img_H[3].x  = 235; img_H[3].y  = 35;

  // 結構-移動勾子.
  img_SH[0].img  = sh1;  img_SH[0].w = 26; img_SH[0].h = 26; img_SH[0].x  = 228; img_SH[0].y  = 85;
  img_SH[1].img  = sh2;  img_SH[1].w = 17; img_SH[1].h = 34; img_SH[1].x  = 239; img_SH[1].y  = 90;
  img_SH[2].img  = sh3;  img_SH[2].w =  8; img_SH[2].h = 38; img_SH[2].x  = 255; img_SH[2].y  = 92;
  img_SH[3].img  = sh4;  img_SH[3].w = 15; img_SH[3].h = 31; img_SH[3].x  = 263; img_SH[3].y  = 96;
  img_SH[4].img  = sh5;  img_SH[4].w = 19; img_SH[4].h = 19; img_SH[4].x  = 272; img_SH[4].y  = 98;

  // 結構-桿子.
  img_PO[0].img  = po1;  img_PO[0].w = 13; img_PO[0].h = 7; img_PO[0].x  = 30; img_PO[0].y  = 169;
  img_PO[1].img  = po2;  img_PO[1].w = 12; img_PO[1].h =17; img_PO[1].x  = 22; img_PO[1].y  = 150;

  // 結構-愛心.
  img_HE[0].img  = he1;  img_HE[0].w = 12; img_HE[0].h = 14; img_HE[0].x  = 31; img_HE[0].y  = 8;
  img_HE[1].img  = he2;  img_HE[1].w =  8; img_HE[1].h = 11; img_HE[1].x  = 22; img_HE[1].y  =19;

}

#endif
