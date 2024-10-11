#include<stddef.h>
#include<string.h>
#include "datamanager.h"
#include "kbdattchmnt.h"

//for kannada
static uint16_t kannadaUnicodeList[256]={0};
static uint8_t dualchnumList[37][3]={0};
static uint8_t singchnumList[256]={0};

//for hindi
static uint16_t hindiUnicodeList[256]={0};
static uint8_t hindualchnum[37][3]={0};
static uint8_t hinsingchnum[256]={0};

static language Kan;
static layout Kan1;

layout* selectedlayout(void)
{
    return &Kan1;
}

language *selectedlanguage(void)
{
    return &Kan;
}

void data_init_all()
{

kannadaUnicodeList[128] = 3201;
kannadaUnicodeList[126] = 3202;
kannadaUnicodeList[127] = 3203;
kannadaUnicodeList[81]  = 3205;
kannadaUnicodeList[82]  = 3206;
kannadaUnicodeList[83]  = 3207;
kannadaUnicodeList[84]  = 3208;
kannadaUnicodeList[85]  = 3209;
kannadaUnicodeList[86]  = 3210;
kannadaUnicodeList[94]  = 3211;
kannadaUnicodeList[87]  = 3214;
kannadaUnicodeList[88]  = 3215;
kannadaUnicodeList[89]  = 3216;
kannadaUnicodeList[90]  = 3218;
kannadaUnicodeList[91]  = 3219;
kannadaUnicodeList[92]  = 3220;
kannadaUnicodeList[11]  = 3221;
kannadaUnicodeList[12]  = 3222;
kannadaUnicodeList[13]  = 3223;
kannadaUnicodeList[14]  = 3224;
kannadaUnicodeList[15]  = 3225;
kannadaUnicodeList[21]  = 3226;
kannadaUnicodeList[22]  = 3227;
kannadaUnicodeList[23]  = 3228;
kannadaUnicodeList[24]  = 3229;
kannadaUnicodeList[25]  = 3230;
kannadaUnicodeList[31]  = 3231;
kannadaUnicodeList[32]  = 3232;
kannadaUnicodeList[33]  = 3233;
kannadaUnicodeList[34]  = 3234;
kannadaUnicodeList[35]  = 3235;
kannadaUnicodeList[41]  = 3236;
kannadaUnicodeList[42]  = 3237;
kannadaUnicodeList[43]  = 3238;
kannadaUnicodeList[44]  = 3239;
kannadaUnicodeList[45]  = 3240;
kannadaUnicodeList[51]  = 3242;
kannadaUnicodeList[52]  = 3243;
kannadaUnicodeList[53]  = 3244;
kannadaUnicodeList[54]  = 3245;
kannadaUnicodeList[55]  = 3246;
kannadaUnicodeList[61]  = 3247;
kannadaUnicodeList[62]  = 3248;
kannadaUnicodeList[70]  = 3249;
kannadaUnicodeList[63]  = 3250;
kannadaUnicodeList[69]  = 3251;
kannadaUnicodeList[64]  = 3253;
kannadaUnicodeList[65]  = 3254;
kannadaUnicodeList[66]  = 3255;
kannadaUnicodeList[67]  = 3256;
kannadaUnicodeList[68]  = 3257;
kannadaUnicodeList[112] = 3262;
kannadaUnicodeList[113] = 3263;
kannadaUnicodeList[114] = 3264;
kannadaUnicodeList[115] = 3265;
kannadaUnicodeList[116] = 3266;
kannadaUnicodeList[124] = 3267;
kannadaUnicodeList[117] = 3270;
kannadaUnicodeList[118] = 3271;
kannadaUnicodeList[119] = 3272;
kannadaUnicodeList[120] = 3274;
kannadaUnicodeList[121] = 3275;
kannadaUnicodeList[122] = 3276;
kannadaUnicodeList[110] = 3277;
kannadaUnicodeList[95]  = 3296;
kannadaUnicodeList[0]   = 3302;
kannadaUnicodeList[1]   = 3303;
kannadaUnicodeList[2]   = 3304;
kannadaUnicodeList[3]   = 3305;
kannadaUnicodeList[4]   = 3306;
kannadaUnicodeList[5]   = 3307;
kannadaUnicodeList[6]   = 3308;
kannadaUnicodeList[7]   = 3309;
kannadaUnicodeList[8]   = 3310;
kannadaUnicodeList[9]   = 3311;

singchnumList[0x3a]=81; //f1
singchnumList[0x3b]=82; //f2
singchnumList[0x3c]=83; //f3
singchnumList[0x3d]=84; //f4
singchnumList[0x3e]=85; //f5
singchnumList[0x3f]=86; //f6
singchnumList[0x40]=87; //f7
singchnumList[0x41]=88; //f8
singchnumList[0x42]=89; //f9
singchnumList[0x43]=90; //f10
singchnumList[0x44]=91; //f11
singchnumList[0x45]=92; //f12
singchnumList[0x06]=124; //c
singchnumList[0x27]=0; //0
singchnumList[0x1e]=1; //1
singchnumList[0x1f]=2; //2
singchnumList[0x20]=3; //3
singchnumList[0x21]=4; //4
singchnumList[0x22]=5; //5
singchnumList[0x23]=6; //6
singchnumList[0x24]=7; //7 
singchnumList[0x25]=8; //8
singchnumList[0x26]=9; //9
singchnumList[0x04]=61; //a
singchnumList[0x16]=62; //s
singchnumList[0x07]=63; //d
singchnumList[0x09]=64; //f
singchnumList[0x0a]=65; //g
singchnumList[0x0b]=66; //h
singchnumList[0x0d]=67; //j
singchnumList[0x0e]=68; //k
singchnumList[0x0f]=69; //l
singchnumList[0x1d]=94; //z
singchnumList[0x1b]=95; //x
singchnumList[0x19]=70; //v 
singchnumList[0x05]=126; //b
singchnumList[0x11]=127; //n
singchnumList[0x10]=128; //m


dualchnumList[0][0] = 110; dualchnumList[0][1] = 0x02; dualchnumList[0][2] = 0x3a; // shift+f1
dualchnumList[1][0] = 112; dualchnumList[1][1] = 0x02; dualchnumList[1][2] = 0x3b; // shift+f2
dualchnumList[2][0] = 113; dualchnumList[2][1] = 0x02; dualchnumList[2][2] = 0x3c; // shift+f3
dualchnumList[3][0] = 114; dualchnumList[3][1] = 0x02; dualchnumList[3][2] = 0x3d; // shift+f4
dualchnumList[4][0] = 115; dualchnumList[4][1] = 0x02; dualchnumList[4][2] = 0x3e; // shift+f5
dualchnumList[5][0] = 116; dualchnumList[5][1] = 0x02; dualchnumList[5][2] = 0x3f; // shift+f6
dualchnumList[6][0] = 117; dualchnumList[6][1] = 0x02; dualchnumList[6][2] = 0x40; // shift+f7
dualchnumList[7][0] = 118; dualchnumList[7][1] = 0x02; dualchnumList[7][2] = 0x41; // shift+f8
dualchnumList[8][0] = 119; dualchnumList[8][1] = 0x02; dualchnumList[8][2] = 0x42; // shift+f9
dualchnumList[9][0] = 120; dualchnumList[9][1] = 0x02; dualchnumList[9][2] = 0x43; // shift+f10
dualchnumList[10][0] = 121; dualchnumList[10][1] = 0x02; dualchnumList[10][2] = 0x44; // shift+f11
dualchnumList[11][0] = 122; dualchnumList[11][1] = 0x02; dualchnumList[11][2] = 0x45; // shift+f12
dualchnumList[12][0] = 11; dualchnumList[12][1] = 0x14; dualchnumList[12][2] = 0x1c; // q+y
dualchnumList[13][0] = 12; dualchnumList[13][1] = 0x14; dualchnumList[13][2] = 0x18; // q+u
dualchnumList[14][0] = 13; dualchnumList[14][1] = 0x14; dualchnumList[14][2] = 0x0c; // q+i
dualchnumList[15][0] = 14; dualchnumList[15][1] = 0x14; dualchnumList[15][2] = 0x12; // q+o
dualchnumList[16][0] = 15; dualchnumList[16][1] = 0x14; dualchnumList[16][2] = 0x13; // q+p
dualchnumList[17][0] = 21; dualchnumList[17][1] = 0x1a; dualchnumList[17][2] = 0x1c; // w+y
dualchnumList[18][0] = 22; dualchnumList[18][1] = 0x1a; dualchnumList[18][2] = 0x19; // w+u
dualchnumList[19][0] = 23; dualchnumList[19][1] = 0x1a; dualchnumList[19][2] = 0x0c; // w+i
dualchnumList[20][0] = 24; dualchnumList[20][1] = 0x1a; dualchnumList[20][2] = 0x12; // w+o
dualchnumList[21][0] = 25; dualchnumList[21][1] = 0x1a; dualchnumList[21][2] = 0x13; // w+p
dualchnumList[22][0] = 31; dualchnumList[22][1] = 0x08; dualchnumList[22][2] = 0x1c; // e+y
dualchnumList[23][0] = 32; dualchnumList[23][1] = 0x08; dualchnumList[23][2] = 0x18; // e+u
dualchnumList[24][0] = 33; dualchnumList[24][1] = 0x08; dualchnumList[24][2] = 0x0c; // e+i
dualchnumList[25][0] = 34; dualchnumList[25][1] = 0x08; dualchnumList[25][2] = 0x12; // e+o
dualchnumList[26][0] = 35; dualchnumList[26][1] = 0x08; dualchnumList[26][2] = 0x13; // e+p
dualchnumList[27][0] = 41; dualchnumList[27][1] = 0x15; dualchnumList[27][2] = 0x1c; // r+y
dualchnumList[28][0] = 42; dualchnumList[28][1] = 0x15; dualchnumList[28][2] = 0x18; // r+u
dualchnumList[29][0] = 43; dualchnumList[29][1] = 0x15; dualchnumList[29][2] = 0x0c; // r+i
dualchnumList[30][0] = 44; dualchnumList[30][1] = 0x15; dualchnumList[30][2] = 0x12; // r+o
dualchnumList[31][0] = 45; dualchnumList[31][1] = 0x15; dualchnumList[31][2] = 0x13; // r+p
dualchnumList[32][0] = 51; dualchnumList[32][1] = 0x17; dualchnumList[32][2] = 0x1c; // t+y
dualchnumList[33][0] = 52; dualchnumList[33][1] = 0x17; dualchnumList[33][2] = 0x18; // t+u
dualchnumList[34][0] = 53; dualchnumList[34][1] = 0x17; dualchnumList[34][2] = 0x0c; // t+i
dualchnumList[35][0] = 54; dualchnumList[35][1] = 0x17; dualchnumList[35][2] = 0x12; // t+o
dualchnumList[36][0] = 55; dualchnumList[36][1] = 0x17; dualchnumList[36][2] = 0x13; // t+p

Kan.langID=1;
Kan.charnumToUnico=kannadaUnicodeList;

Kan1.langID=1;
Kan1.singkeyList=singchnumList;
Kan1.dualkeyList=dualchnumList;
Kan1.dualkeylen=37;
Kan1.restrkeylen=1;
Kan1.restrkeyList=NULL;
}