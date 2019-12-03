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
	
	printf("�� ������ ���� ���� �����ϼ��� : ");
	scanf("%d", &galaxy_num);

	init_Universe(&universe, galaxy_num);

	//���Ϻ� �༺ �ʱ�ȭ
	for (int i = 0; i < galaxy_num; i++)
	{
		g = &(universe.galaxies[i]);
		printf("%d�� ������ �༺ ���� �����ϼ��� : ", i+1);
		scanf("%d", &planet_num);

		init_Galaxy(g, planet_num);

		printf("�׶� �༺�� ���� �����ϼ��� : ");
		scanf("%d", &terran);
		printf("�����佺 �༺�� ���� �����ϼ��� : ");
		scanf("%d", &protoss);
		printf("���� �༺�� ���� �����ϼ��� : ");
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
		for (int j = terran+protoss; j < planet_num; j++)
		{
			init_Planet(&(universe.galaxies[i].planets[j]), 'Z', 110);
		}
	}

	broodwar(&universe);


	return 0;
}