#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include <Windows.h>
//#include "function.h"

#include "util.h"
#include "universe.h"
#include "player.h"
#include "show.h"
#include "menu.h"

//컨셉 : 
int main() {

	enum menuType menu;

	srand(time(NULL));

	Player *player = (Player *)malloc(sizeof(Player));

	char **planetBoard = makeBoard();
	char **galaxyBoard = makeBoard();

	Universe *universe = NULL;
	universe = create_all(universe);

	//초기 은하 보여주고 몇번째 은하를 볼건지 물어봄.
	Galaxy_coordToSquare(galaxyBoard, universe);
	show_universe_info(universe, galaxyBoard);
	getPlayerGalaxy(player, universe);
	Sleep(3000);
	system("cls");
	//선택한 은하의 행성을 보여줌.
	Planet_coordToCircle(planetBoard, player->player_galaxy);
	show_galaxy_info(player->player_galaxy, planetBoard);

	//모든 초기화 과정 끝.

	printf("게임을 시작하시려면 키를 입력하세요\n");
	press_anyKey_continue();
	//게임의 인트로 부분 보여줌.
	show_intro();
	showAllMenu();

		while (1)
		{
			switch (menu)
			{
				case MOVE_GALAXY:
					move_galaxy();
					break;
				case EARTHQUAKE:
					earthquake();
					break;
				case PLAUGE:
					plauge();
					break;
				case NEW_CIVIL:
					new_civil();
					break;
				case REBEL:
					rebel();
					break;
				case COLLISION:
					collision();
					break;
				case PEACE:
					peace();
					break;
				case END_GAME:
					end_game();	
					break;
			}
		}
}


void race_info()
{
	printf("*****************************************************************************\n");
	printf("Zerg : attk 1, def 1 per 100 population / population increase rate 3000 \n");
	printf("Terran : attk 2, def 2 per 100 population / population increase rate 2000 \n");
	printf("Protoss : attk 3, def 3 per 100 population / population increase rate 1000 \n");
	printf("*****************************************************************************\n\n");
}

/*
int main()
{
	Universe *universe;
	Galaxy* g;
	Planet* p;

	int galaxy_num;
	int planet_num;
	int selection;

	int terran;
	int protoss;
	int zerg;

	char brood;
	int population;
	

	init_Universe(universe, galaxy_num);

	//은하별 행성 초기화
	for (int i = 0; i < galaxy_num; i++)
	{
		g = &(universe.galaxies[i]);
		printf("%d번 은하의 행성 수를 결정하세요 : ", i+1);
		scanf("%d", &planet_num);

		init_Galaxy(g, planet_num);

		printf("직접 설정할 행성의 수를 결정하세요 : ");
		scanf("%d", &selection);
		printf("자동 생성될 테란 행성의 수를 결정하세요 : ");
		scanf("%d", &terran);
		printf("자동 생성될 프로토스 행성의 수를 결정하세요 : ");
		scanf("%d", &protoss);
		printf("자동 생성될 저그 행성의 수를 결정하세요 : ");
		scanf("%d", &zerg);

		//종족별 초기 인구수 설정
		for (int j = 0; j < terran; j++)
		{
			init_Planet(&(universe.galaxies[i].planets[j]), 'T', 100);
		}
		for (int j = terran; j < terran+protoss; j++)
		{
			init_Planet(&(universe.galaxies[i].planets[j]), 'P', 90);
		}
		for (int j = terran+protoss; j < (planet_num)-selection; j++)
		{
			init_Planet(&(universe.galaxies[i].planets[j]), 'Z', 110);
		}

		//행성 직접 설정
		printf("직접 생성할 행성의 정보를 입력합니다\n");
		for (int j = 0; j < selection; j++)
		{
			printf("#%d\n", j + 1);
			printf("brood : ");
			getchar();
			scanf("%c", &brood);
			printf("population : ");
			scanf("%d", &population);
			init_Planet(&(universe.galaxies[i].planets[planet_num - selection + j]), brood, population);
		}
	}

	broodwar(&universe);


	return 0;
}

*/