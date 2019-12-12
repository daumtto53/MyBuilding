
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#include "util.h"
#include "universe.h"

Universe *create_Universe(Universe *universe){
	universe = (Universe *)malloc(sizeof(Universe));
	
	universe->galaxy_num = get_Rand_Btw(MIN_OBJECT,MAX_OBJECT);
	printf("내 우주의 은하 수 : %d\n\n", universe->galaxy_num);

	universe->galaxy_arr = (Galaxy **)malloc(sizeof(Galaxy *) * universe->galaxy_num);
	return universe;
}

//은하 만들기
Galaxy *create_Galaxy(void){
	Galaxy *temp_galaxy = (Galaxy *)malloc(sizeof(Galaxy));
	temp_galaxy->planet_num = get_Rand_Btw(MIN_OBJECT, MAX_OBJECT);

	printf("이 은하의 행성 수 : %d\n\n", temp_galaxy->planet_num);
	temp_galaxy->planet_arr = (Planet **)malloc(sizeof(Planet *) * temp_galaxy->planet_num);
	
	return temp_galaxy;
}

//행성 만들기
Planet *create_Planet(void){
	Planet *planet = (Planet *)malloc(sizeof(Planet));
	return planet;
}

//행성 정보 랜덤하게 초기화
Planet *init_Planet(Planet *planet){
	planet->brood = get_Rand_Btw(TERRAN,PROTOSS);
	planet->population = get_Rand_Btw(MIN_POPULATION, MAX_POPULATION);	
	planet->power = get_Rand_Btw(MIN_POWER, MAX_POWER);	
	planet->armor = get_Rand_Btw(MIN_ARMOR, MAX_ARMOR);	
	planet->attack_or_defense = get_Rand_Btw(ATTACK_MODE, DEFENSE_MODE);
	planet->x = get_Rand_Btw(MIN_X_COORD, MAX_X_COORD);	
	planet->y = get_Rand_Btw(MIN_Y_COORD, MAX_Y_COORD);
	return planet;
}


//우주 초기화(안의 은하, 행성까지 모두 초기화됨)
Universe *create_all(Universe *universe){
	int i, j;
	Galaxy *current_galaxy;
	Planet *current_planet;
	printf("#########우주 초기화중..#########\n");
	universe = create_Universe(universe);

	for(i=0; i < universe->galaxy_num; i++){

		printf("#########은하 초기화중..#########\n");
		current_galaxy = create_Galaxy();
		(universe->galaxy_arr)[i] = current_galaxy;

		for(j=0; j < current_galaxy->planet_num; j++){
			printf("#########행성 초기화중..#########\n");
			current_planet = create_Planet();
			current_planet = init_Planet(current_planet);
			(current_galaxy->planet_arr)[j] = current_planet;
			
		}
	}

	printf("######\t우주 생성 완료!!!\t######\n");
	return universe;
}

//create_all 이후 우주가 잘 생성되었는지 확인용.
void show_universe_info(Universe *universe){
	Galaxy *current_galaxy;
	Planet *current_planet;
	int i,j;
	for(i=0; i < universe->galaxy_num; i++){
		printf("%d\n",universe->galaxy_num);
		current_galaxy = (universe->galaxy_arr)[i];
		for(j=0; j < (current_galaxy)->planet_num; j++){
			current_planet = (current_galaxy->planet_arr)[j];
			printf("%d번째 은하의 %d번째 행성의 인구 수: %d-----\n", i, j, current_planet->population);
		}
	}
}


//은하 안의 행성들을 표현할 보드. 
char **makeBoard(void){
	char **board = (char **)malloc(sizeof(char *) * MAX_Y_COORD + MAX_RADIUS );
	if(!board){
		printf("메모리 할당 실패!\n");
	}
	for(int i = 0; i < MAX_Y_COORD+MAX_RADIUS; i++)
	{
		board[i] = (char *)malloc(sizeof(char) * MAX_X_COORD +MAX_RADIUS);
		memset (board[i], ' ' , MAX_X_COORD+4);
		board[MAX_X_COORD + MAX_RADIUS -1] = '\0';
	}
	return board;
}

void setBoardToCircle(char **board, Planet *planet){
	int x,y;
	x = planet->x;
	y = planet->y;

	board[x+1][y] = '*';	board[x-1][y] = '*';
	board[x+2][y] = '*';	board[x-2][y] = '*';
	board[x+3][y] = '*';	board[x+3][y] = '*';

	board[x][y+1] = '*';	board[x][y-1] = '*';
	board[x][y+2] = '*';	board[x][y-2] = '*';
	board[x][y+3] = '*';	board[x][y+3] = '*';
}

void setBoardToCircle_ver2(char **board, Planet *planet){
	int radius = planet->population / (MAX_POPULATION/5);
	int x,y;
	int center_x, center_y;

	center_x = planet->x;
	center_y = planet->y;

	x = planet->x - radius;
	y = planet->y - radius;

	for(int i = x; i <= x + 4*radius; i++)
	{
		for(int j = y; j <= y + 2 * radius; j++)
		{
			if(2 * (i-center_x)*(i-center_x) + (j-center_y)*(j-center_y) <= radius * radius)
			{
				board[i][j] = '*';
			}
		}
	}
}

void Planet_coordToCircle(char **board, Galaxy *galaxy){
	int i;
	Planet *temp;
	for(i=0; i < galaxy->planet_num;)
	{
		temp = galaxy->planet_arr[i];
		setBoardToCircle_ver2(board, temp);
	}
}

void show_Board(char **board){
	int i;
	int j;

	for(i=0; i < MAX_Y_COORD ; i++)
	{
		for(j=0; j < MAX_X_COORD ; j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
