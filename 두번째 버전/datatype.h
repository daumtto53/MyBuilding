#pragma once
#include <stdio.h >


typedef struct planet {
	
	char* name;
	int race;
	char* race_name;
	int population;
	int attk_p;
	int def_p;
	int fight; //싸우는 상대방
	int dead;  //
	int a_or_d; //공격 상태 or 방어 상태

}Planet;
