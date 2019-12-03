#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#include "header.h"
#include "type.h"

void init_Planet(Planet *p, char brood, int population)
{
	p->brood = brood;
	p->population = population;
	set_Ability(p);
}

void init_Galaxy(Galaxy* g, int planet_num)
{
	g->planets = (Planet*)malloc(sizeof(Planet) * planet_num);
	g->planet_num = planet_num;
}

void init_Universe(Universe* u, int galaxy_num)
{
	u->galaxies = (Galaxy*)malloc(sizeof(Galaxy) * galaxy_num);
	u->galaxy_num = galaxy_num;
}

void set_Ability(Planet* p)
{
	//종족별 능력치 설정
	if (p->brood == TERRAN)
	{
		p->power = p->population * 1;
		p->armor = p->population * 1;
	}
	else if (p->brood == ZERG)
	{
		p->power = p->population * 1.2;
		p->armor = p->population * 0.8;
	}
	else if (p->brood == PROTOSS)
	{
		p->power = p->population * 0.8;
		p->armor = p->population * 1.2;
	}
}

void add_Planet(Galaxy* g, char brood, int population)
{
	if (g->planets == NULL)
	{
		printf("No galaxy\n");
		return;
	}

	g->planets = (Planet*)realloc(g->planets, sizeof(Planet) * ((g->planet_num) + 1));

	if (g->planets == NULL)
	{
		printf("Planet Addition Failure\n");
		return;
	}

	(g->planet_num)++;
	init_Planet(&(g->planets[g->planet_num - 1]), brood, population);
}

void war(Planet* p1, Planet* p2)
{
	double planet1;
	double planet2;

	planet1 = p1->armor - p2->power;
	planet2 = p2->armor - p1->power;
	
	//승부의 결과
	if (planet1 > planet2)
	{
		p2->brood = p1->brood;
		p2->population /= 2;
		set_Ability(p2);
	}
	else if (planet1 < planet2)
	{
		p1->brood = p2->brood;
		p1->population /= 2;
		set_Ability(p1);
	}
	else//비긴경우
	{
		return;
	}
}

void winner(Galaxy* g)
{
	int terran = 0;
	int protoss = 0;
	int zerg = 0;

	for (int i = 0; i < g->planet_num; i++)
	{
		if (g->planets[i].brood == TERRAN) terran++;
		else if (g->planets[i].brood == PROTOSS) protoss++;
		else if (g->planets[i].brood == ZERG) zerg++;
	}

	//행성 수가 같을 경우 여러 문장 출력
	if (terran >= protoss && terran >= zerg)
	{
		printf("이 은하에서 가장 우세한 종족은 Terran입니다\n");
	}
	if (protoss >= terran && protoss >= zerg)
	{
		printf("이 은하에서 가장 우세한 종족은 Protoss입니다\n");
	}
	if (zerg >= terran && zerg >= protoss)
	{
		printf("이 은하에서 가장 우세한 종족은 Zerg입니다\n");
	}
}

void print_Planet(Planet* p)
{
	if (p->brood == TERRAN)printf("brood : Terran\n");
	else if (p->brood == PROTOSS)printf("brood : Protoss\n");	
	else if (p->brood == ZERG)printf("brood : Zerg\n");
	printf("population : %d\n", p->population);
	printf("power : %.2lf\n", p->power);
	printf("armor : %.2lf\n", p->armor);
}

void print_Galaxy(Galaxy* g)
{
	winner(g);
	for (int i = 0; i < g->planet_num; i++)
	{
		print_Planet(&(g->planets[i]));
		printf("\n");
	}
}

void print_Universe(Universe* u)
{
	for (int i = 0; i < u->galaxy_num; i++)
	{
		print_Galaxy(&(u->galaxies[i]));
		printf("\n\n");
	}
}

void broodwar(Universe* u)
{
	print_Universe(u);
}