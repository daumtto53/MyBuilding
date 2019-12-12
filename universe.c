
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
	printf("�� ������ ���� �� : %d\n\n", universe->galaxy_num);

	universe->galaxy_arr = (Galaxy **)malloc(sizeof(Galaxy *) * universe->galaxy_num);
	return universe;
}

//���� �����
Galaxy *create_Galaxy(void){
	Galaxy *temp_galaxy = (Galaxy *)malloc(sizeof(Galaxy));
	if(!temp_galaxy)
	{
		printf("���� �޸� �й� ����\n");
	}
	temp_galaxy->planet_num = get_Rand_Btw(MIN_OBJECT, MAX_OBJECT);

	temp_galaxy->x = get_Rand_Btw(MIN_X_COORD,MAX_X_COORD);
	temp_galaxy->y = get_Rand_Btw(MIN_Y_COORD,MAX_Y_COORD);
	temp_galaxy->name = make_Random_Name(NAME_LENGTH);

	printf("�� ������ �༺ �� : %d\n\n", temp_galaxy->planet_num);
	temp_galaxy->planet_arr = (Planet **)malloc(sizeof(Planet *) * temp_galaxy->planet_num);
	
	return temp_galaxy;
}

//�༺ �����
Planet *create_Planet(void){
	Planet *planet = (Planet *)malloc(sizeof(Planet));
	if(!planet)
	{
		printf("�༺ �޸� �й� ����\n");
	}
	return planet;
}

//�༺ ���� �����ϰ� �ʱ�ȭ
Planet *init_Planet(Planet *planet){
	printf("�༺ �ʱ�ȭ\n");
	planet->name = make_Random_Name(NAME_LENGTH);
	planet->brood = get_Rand_Btw(TERRAN,PROTOSS);
	planet->population = get_Rand_Btw(MIN_POPULATION, MAX_POPULATION);	
	planet->power = get_Rand_Btw(MIN_POWER, MAX_POWER);	
	planet->armor = get_Rand_Btw(MIN_ARMOR, MAX_ARMOR);	
	planet->attack_or_defense = get_Rand_Btw(ATTACK_MODE, DEFENSE_MODE);
	planet->x = get_Rand_Btw(MIN_X_COORD, MAX_X_COORD);	
	planet->y = get_Rand_Btw(MIN_Y_COORD, MAX_Y_COORD);
	return planet;
}


//���� �ʱ�ȭ(���� ����, �༺���� ��� �ʱ�ȭ��)
Universe *create_all(Universe *universe){
	int i, j;
	Galaxy *current_galaxy;
	Planet *current_planet;
	printf("#########���� �ʱ�ȭ��..#########\n");
	universe = create_Universe(universe);

	for(i=0; i < universe->galaxy_num; i++){

		current_galaxy = create_Galaxy();
		(universe->galaxy_arr)[i] = current_galaxy;

		for(j=0; j < current_galaxy->planet_num; j++){
			current_planet = create_Planet();
			current_planet = init_Planet(current_planet);
			(current_galaxy->planet_arr)[j] = current_planet;
		}
	}

	printf("######\t���� ���� �Ϸ�!!!\t######\n");
	return universe;
}