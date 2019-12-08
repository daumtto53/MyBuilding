#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "function.h"
#include "type.h"
#include "util.h"

//���� �� �ִ� ��� object��
#define MAX_OBJECT 30
#define MIN_OBJECT 1

#define MAX_X_COORD 1000
#define MAX_Y_COORD 1000
#define MIN_X_COORD 10
#define MIN_Y_COORD 10

#define MIN_POPULATION 10
#define MAX_POPULATION 10
#define MIN_POWER 10
#define MAX_POWER 10
#define MIN_ARMOR 10
#define MAX_ARMOR 10
#define ATTACK_MODE 2
#define DEFENSE_MODE 1

void create_Universe(Universe *universe){
	universe = (Universe *)malloc(sizeof(Universe));
	memset(universe, 0x0, sizeof(Universe));
	
	universe->galaxy_num = get_Rand_Btw(MIN_OBJECT,MAX_OBJECT);
	printf("�� ������ ���� �� : %d\n\n", universe->galaxy_num);

	universe->galaxy_arr = (Galaxy *)malloc(sizeof(Galaxy) * universe->galaxy_num);
	memset(universe->galaxy_arr, 0x0, _msize(universe->galaxy_arr) * universe->galaxy_num);
}

void create_Galaxy(Galaxy *galaxy){

	galaxy->planet_num = get_Rand_Btw(MIN_OBJECT, MAX_OBJECT);
	printf("�� ������ �༺ �� : %d\n\n", galaxy->planet_num);

	galaxy->planet_arr = (Planet *)malloc(sizeof(Planet) * galaxy->planet_num);
	memset(galaxy->planet_arr, 0x0, _msize(galaxy->planet_arr) * galaxy->planet_num);
}

void create_Planet(Planet *planet){

	planet = (Planet *)malloc(sizeof(Planet));
	memset(planet, 0x0, _msize(planet));

}

void init_Planet(Planet *planet){
	planet->brood = get_Rand_Btw(TERRAN,PROTOSS);
	planet->population = get_Rand_Btw(MIN_POPULATION, MAX_POPULATION);	
	planet->power = get_Rand_Btw(MIN_POWER, MAX_POWER);	
	planet->armor = get_Rand_Btw(MIN_ARMOR, MAX_ARMOR);	
	planet->attack_or_defense = get_Rand_Btw(ATTACK_MODE, DEFENSE_MODE);
	planet->x = get_Rand_Btw(MIN_X_COORD, MAX_X_COORD);	
	planet->y = get_Rand_Btw(MIN_Y_COORD, MAX_Y_COORD);
	planet->armor = get_Rand_Btw(MIN_ARMOR, MAX_ARMOR);	

}


void create_all(Universe *universe){
	int i, j;
	Galaxy *current_galaxy;
	printf("#########���� �ʱ�ȭ��..#########");
	create_Universe(universe);

	for(i=0; i < universe->galaxy_num; i++){
		printf("#########���� �ʱ�ȭ��..#########");
		create_Galaxy((universe->galaxy_arr) + i);
		current_galaxy = universe->galaxy_arr + i;

		for(j=0; j < current_galaxy->planet_num; j++){
			printf("#########�༺ �ʱ�ȭ��..#########");
			create_Planet((current_galaxy->planet_arr) + j);
			init_Planet((current_galaxy->planet_arr) + j);
		}
	}

	printf("######\t���� ���� �Ϸ�!!!\t######\n");
}

int main(){
	Universe *universe;
	create_all(universe);
	printf("�ʱ�ȭ ����!\n");
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