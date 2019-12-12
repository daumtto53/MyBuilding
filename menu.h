#include <stdio.h>
#include <Windows.h>
#include "universe.h"
#include "player.h"
#include "show.h"


enum MenuType {
	MOVE_GALAXY,
	EARTHQUAKE,
	PLAUGE,
	NEW_CIVIL,
	REBEL,
	COLLISION,
	PEACE,
	END_GAME
};

void show_intro(void);
void showAllMenu();
