#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

//#include "function.h"
#include "type.h"
#include "util.h"

//���� �� �ִ� ��� object��
#define MAX_OBJECT 30
#define MIN_OBJECT 1

#define MAX_X_COORD 100
#define MAX_Y_COORD 100
#define MIN_X_COORD 10
#define MIN_Y_COORD 10

#define MIN_POPULATION 10
#define MAX_POPULATION 20
#define MIN_POWER 10
#define MAX_POWER 20
#define MIN_ARMOR 10
#define MAX_ARMOR 20
#define ATTACK_MODE 2
#define DEFENSE_MODE 1

Universe *create_Universe(Universe *universe){
	universe = (Universe *)malloc(sizeof(Universe));
	
	universe->galaxy_num = get_Rand_Btw(MIN_OBJECT,MAX_OBJECT);
	printf("�� ������ ���� �� : %d\n\n", universe->galaxy_num);

	universe->galaxy_arr = (Galaxy **)malloc(sizeof(Galaxy *) * universe->galaxy_num);
	return universe;
}

Galaxy *create_Galaxy(void){
	Galaxy *temp_galaxy = (Galaxy *)malloc(sizeof(Galaxy));
	temp_galaxy->planet_num = get_Rand_Btw(MIN_OBJECT, MAX_OBJECT);

	printf("�� ������ �༺ �� : %d\n\n", temp_galaxy->planet_num);
	temp_galaxy->planet_arr = (Planet **)malloc(sizeof(Planet *) * temp_galaxy->planet_num);
	
	return temp_galaxy;
}

Planet *create_Planet(void){
	Planet *planet = (Planet *)malloc(sizeof(Planet));
	return planet;
}

Planet *init_Planet(Planet *planet){
	planet->brood = get_Rand_Btw(TERRAN,PROTOSS);
	planet->population = get_Rand_Btw(MIN_POPULATION, MAX_POPULATION);	
	planet->power = get_Rand_Btw(MIN_POWER, MAX_POWER);	
	planet->armor = get_Rand_Btw(MIN_ARMOR, MAX_ARMOR);	
	planet->attack_or_defense = get_Rand_Btw(ATTACK_MODE, DEFENSE_MODE);
	planet->x = get_Rand_Btw(MIN_X_COORD, MAX_X_COORD);	
	planet->y = get_Rand_Btw(MIN_Y_COORD, MAX_Y_COORD);
}


Universe *create_all(Universe *universe){
	int i, j;
	Galaxy *current_galaxy;
	Planet *current_planet;
	printf("#########���� �ʱ�ȭ��..#########\n");
	universe = create_Universe(universe);

	for(i=0; i < universe->galaxy_num; i++){

		printf("#########���� �ʱ�ȭ��..#########\n");
		current_galaxy = create_Galaxy();
		(universe->galaxy_arr)[i] = current_galaxy;

		for(j=0; j < current_galaxy->planet_num; j++){
			printf("#########�༺ �ʱ�ȭ��..#########\n");
			current_planet = create_Planet();
			current_planet = init_Planet(current_planet);
			(current_galaxy->planet_arr)[j] = current_planet;
			
		}
	}

	printf("######\t���� ���� �Ϸ�!!!\t######\n");
	return universe;
}

void show_universe_info(Universe *universe){
	Galaxy *current_galaxy;
	Planet *current_planet;
	int i,j;
	for(i=0; i < universe->galaxy_num; i++){
		printf("%d\n",universe->galaxy_num);
		current_galaxy = (universe->galaxy_arr)[i];
		for(j=0; j < (current_galaxy)->planet_num; j++){
			current_planet = (current_galaxy->planet_arr)[j];
			printf("%d��° ������ %d��° �༺�� �α� ��: %d-----\n", i, j, current_planet->population);
		}
	}
}

char **makeBoard(void){
	char **board = (char **)malloc(sizeof(char *) * MAX_Y_COORD + 5 );
	if(!board){
		printf("�޸� �Ҵ� ����!\n");
	}
	for(int i = 0; i < MAX_Y_COORD; i++)
	{
		board[i] = (char *)malloc(sizeof(char) * MAX_X_COORD +5);
		memset (board, ' ' ,MAX_X_COORD);
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
/*
void Galaxy_coordToCircle(char **board, Universe *univ){
	
}
*/
void Planet_coordToCircle(char **board, Galaxy *galaxy){
	int i;
	Planet *temp;
	for(i=0; i < galaxy->planet_num;)
	{
		temp = galaxy->planet_arr[i];
		setBoardToCircle(board, temp);
	}
}

void show_Board(char **board){
	int i;
	int j;
	for(i=0; i < MAX_Y_COORD + 5; i++)
	{
		for(j=0; j < MAX_X_COORD;j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}

int main(){
	srand(time(NULL));
	Universe *universe;
	universe = create_all(universe);
	show_universe_info(universe);
	printf("�ʱ�ȭ ����!\n");

	char **board = makeBoard();
	printf("����!\n");
	Planet_coordToCircle(board, universe->galaxy_arr[1]);
	printf("����\n");
	show_Board(board);

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

	//���Ϻ� �༺ �ʱ�ȭ
	for (int i = 0; i < galaxy_num; i++)
	{
		g = &(universe.galaxies[i]);
		printf("%d�� ������ �༺ ���� �����ϼ��� : ", i+1);
		scanf("%d", &planet_num);

		init_Galaxy(g, planet_num);

		printf("���� ������ �༺�� ���� �����ϼ��� : ");
		scanf("%d", &selection);
		printf("�ڵ� ������ �׶� �༺�� ���� �����ϼ��� : ");
		scanf("%d", &terran);
		printf("�ڵ� ������ �����佺 �༺�� ���� �����ϼ��� : ");
		scanf("%d", &protoss);
		printf("�ڵ� ������ ���� �༺�� ���� �����ϼ��� : ");
		scanf("%d", &zerg);

		//������ �ʱ� �α��� ����
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

		//�༺ ���� ����
		printf("���� ������ �༺�� ������ �Է��մϴ�\n");
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