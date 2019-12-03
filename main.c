#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "header.h"
#include "type.h"

int main()
{
	Universe universe;
	Galaxy* g;
	Planet* p;

	int galaxy_num;
	int planet_num;

	int terran;
	int protoss;
	int zerg;
	
	printf("내 우주의 은하 수를 결정하세요 : ");
	scanf("%d", &galaxy_num);

	init_Universe(&universe, galaxy_num);

	//은하별 행성 초기화
	for (int i = 0; i < galaxy_num; i++)
	{
		g = &(universe.galaxies[i]);
		printf("%d번 은하의 행성 수를 결정하세요 : ", i+1);
		scanf("%d", &planet_num);

		init_Galaxy(g, planet_num);

		printf("테란 행성의 수를 결정하세요 : ");
		scanf("%d", &terran);
		printf("프로토스 행성의 수를 결정하세요 : ");
		scanf("%d", &protoss);
		printf("저그 행성의 수를 결정하세요 : ");
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
		for (int j = terran+protoss; j < planet_num; j++)
		{
			init_Planet(&(universe.galaxies[i].planets[j]), 'Z', 110);
		}
	}

	broodwar(&universe);


	return 0;
}