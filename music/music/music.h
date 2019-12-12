#include<stdio.h>
#include<windows.h> //음악 재생시 꼭 필요하다고 합니다.
#include<mmsystem.h> //음악 재생시 꼭 필요하다고 합니다.
#pragma comment(lib, "winmm.lib") //음악 재생시 꼭 필요하다고 합니다.

void opening_sound();
void terran_sound();
void protoss_sound();
void zerg_sound();
void ending_sound();