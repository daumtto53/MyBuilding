#pragma once
#include <stdio.h >
#include <stdlib.h >
#include <string.h>
#include <memory.h>
#include <time.h>

#include "datatype.h"
#include "function.h"
#include "util.h"

//갤럭시 생성
//전체 은하 개수 초기화 => p_addr에 저장.
int makeGalaxy(Planet*** p_addr)
{
	int galaxy_num;

	printf("How many galaxy will you construct : "); scanf("%d", &galaxy_num);
	printf("\n");
	*p_addr = (Planet**)malloc(sizeof(Planet*) * galaxy_num);
	memset(*p_addr, 0x0, sizeof(Planet*) * galaxy_num);

	return galaxy_num;
}

//갤럭시들에 행성 생성
void makePlanet(Planet** p, int galaxy)
{
	int planet;

	printf("How many planets will you construct in galaxy %d : ", galaxy); scanf("%d", &planet);
	*p = (Planet*)malloc(sizeof(Planet) * planet);
	memset(*p, 0x0, sizeof(Planet) * planet);

	printf("%d planets were constructed in galaxy %d", planet, galaxy);
}

void make_Universe()
{
	//***p: Universe
	//**p: galaxy
	//*p:planet?
	Planet** p;

	int i;
	int cgn; //본인이 플레이하려는 은하
	int cpn; //본인이 플레이하려는 행성
	int planet_num;        //본인이 선택한 은하의 행성 개수
	int galaxy_num = 0;	//전체 은하 개수.

	galaxy_num = makeGalaxy(&p);	//전체 은하 개수 초기화
	
	//각 은하 안에 행성 개수 초기화
	for (i = 0; i < galaxy_num; i++)	//은하 개수에 따라 각 은하에 들어갈 행성을 만든다. 은하1: 행성 x개,,, 은하2: 행성 y개...
	{
		makePlanet(&p[i], i + 1);	//갤럭시 초기화.
		printf(" (Total %d bytes) \n\n", _msize(p[i]));
	}
	show_Universe(p, galaxy_num);
	press_anyKey_continue();

	cgn = choose_Galaxy(p, galaxy_num);
	press_anyKey_continue();

	race_info();
	planet_num = input_planet_info(&p[cgn]);
	press_anyKey_continue();

	cpn = choose_planet(&p[cgn]);
	press_anyKey_continue();

	cosmic_war(&p[cgn], cpn, planet_num);
}

//은하당 행성 몇개 있나 표기
void show_Universe(Planet** p, int galaxy)
{
	int i, k;

	for (i = 0; i < galaxy; i++)
	{
		printf("galaxy %d : ", i + 1);
		for (k = 0; k < (_msize(p[i]) / sizeof(Planet)); k++)
		{
			printf("○ ");
		}
		printf("\n");
	}
}

//플레이할 은하 선택
int choose_Galaxy(Planet** p, int galaxy_num)
{
	int num;

	while (1)
	{
		printf("What galaxy will you play on : "); scanf("%d", &num);
		
		if ((_msize(p[num-1]) / sizeof(Planet)) < 2)
		{
			printf("There is only 1 planet, you can't play your game. Choose another galaxy!! \n");
			continue;
		}
		printf("You will play on galaxy %d!!!", num);
		printf("(%d planets) \n", (_msize(p[num - 1]) / sizeof(Planet)));
		break;
	}

	return num - 1;
}

//종족별 특성들 설명해주는 함수
void race_info()
{
	printf("*****************************************************************************\n");
	printf("Zerg : attk 1, def 1 per 100 population / population increase rate 3000 \n");
	printf("Terran : attk 2, def 2 per 100 population / population increase rate 2000 \n");
	printf("Protoss : attk 3, def 3 per 100 population / population increase rate 1000 \n");
	printf("*****************************************************************************\n\n");
}

//선택한 갤럭시의 행성 수 리턴
int input_planet_info(Planet** p)
{
	int i, k;
	char name[20];

	printf("Input planets info. \n");
	for (i = 0; i < (_msize(*p) / sizeof(Planet)); i++)
	{
		printf("================================= \n");
		printf("Input planet %d's name : ", i+1); scanf("%s", name);
		k = strlen(name);
		p[i]->name = (char*)malloc(sizeof(char) * (k + 1));
		strcpy(p[i]->name, name);
		printf("1.Zerg   2.Terran   3.Protoss \n");
		printf("Choose planet's race : "); scanf("%d", &p[i]->race);
	}
	printf("================================= \n");

	return (_msize(*p) / sizeof(Planet));
}

//본인이 플레이할 행성 선택
int choose_planet(Planet **p)
{
	int i;
	int num;

	printf("Choose the planet you'll own. \n");
	for (i = 0; i < (_msize(*p) / sizeof(Planet)); i++)
	{
		printf("%d : %s", i+1, p[i]->name);
		switch (p[i]->race)
		{
		case 1:
			printf("(Zerg)  ");
			break;
		case 2:
			printf("(Terran)  ");
			break;
		case 3:
			printf("(Protoss)  ");
			break;
		}
	}
	printf("\n");
	printf("Your pick : "); scanf("%d", &num);
	printf("\n");
	printf("You're going to play with planet %d!!\n", num);
	return num - 1;
}

//행성에 인구 값 초기화
void planet_init(Planet** p, int planet_num)
{
	int i;

	for (i = 0; i < planet_num; i++)
	{
		switch (p[i]->race)
		{
		case 1:
			p[i]->population = 2000;
			p[i]->attk_p = 0;
			p[i]->a_or_d = 0;
			p[i]->dead = 0;
			p[i]->race_name = "Zerg";
			break;
		case 2:
			p[i]->population = 2000;
			p[i]->attk_p = 0;
			p[i]->a_or_d = 0;
			p[i]->dead = 0;
			p[i]->race_name = "Terran";
			break;
		case 3:
			p[i]->population = 2000;
			p[i]->attk_p = 0;
			p[i]->a_or_d = 0;
			p[i]->dead = 0;
			p[i]->race_name = "Protoss";
			break;
		}
	}
}

//매판 종족별로 인구수 증가시키는 함수
void change_planet_population(Planet** p, int planet_num)
{
	int i;

	for (i = 0; i < planet_num; i++)
	{
			//디펜스 모드이면 인구수 증가량이 2배(존버 가능)
			switch (p[i]->race)
			{
			case 1:
				p[i]->population += 2000 * p[i]->a_or_d;
				break;
			case 2:
				p[i]->population += 1500 * p[i]->a_or_d;
				break;
			case 3:
				p[i]->population += 1000 * p[i]->a_or_d;
				break;
			}
	}
}

//매판 인구수에 비례한 공/방 올려주는 함수
void change_planet_status(Planet** p, int planet_num)
{
	int i;
	int k = 0;

	for (i = 0; i < planet_num; i++)
	{
		//인구수 100당 증가량
		k = p[i]->population / 100;
		p[i]->attk_p = p[i]->race * k;
		p[i]->def_p = p[i]->race * k;
		//과도한 존버 방지
		switch (p[i]->a_or_d)
		{
		case 1:
			p[i]->attk_p += 20;
			break;
		case 2:
			p[i]->attk_p -= 10;
			break;
		default:
			break;
		}
	}
}

//매 판 행성들의 상태를 표시해주는 함수
void show_planet_status(Planet** p, int cpn, int planet_num)
{
	int i;

	for (i = 0; i < planet_num; i++)
	{
		printf("##########################################################\n");
		printf("○ %d (name : %s, race : %s) ",i+1, p[i]->name, p[i]->race_name);
		if (i == cpn) printf("-> Your planet \n");
		else printf("\n");
		printf("population : %d \n", p[i]->population);
		printf("attack point : %d \n", p[i]->attk_p);
		printf("deffence point : %d \n", p[i]->def_p);
		if (p[i]->dead == 1) printf("Planet Doomed. \n");
		switch (p[i]->a_or_d)
		{
		case 1:
			printf("Attack mode \n");
			if (p[i]->fight != -1)
				printf("Going to war with planet %d \n", p[i]->fight + 1);
			break;
		case 2:
			printf("Deffence mode \n");
			break;
		default :
			break;
		}
	}
	printf("##########################################################\n\n");
}

//공격할지 방어할지 선택 및 공격 대상 선정
void choose_attk_def(Planet** p, int cpn, int planet_num)
{
	int i, k;
	int ai_enemy = 0;
	int enemy = 0;
	int count = 0;
	int ad; //공격하거나 수비하거나 선택

	srand((unsigned)time(NULL));

	printf("Choose your next act 1.Attack or 2.Deffence : "); scanf("%d", &ad);
	p[cpn]->a_or_d = ad;

	//나머지 ai들은 임의로 attack 또는 deffence 설정
	for (i = 0; i < planet_num; i++)
	{
		if (p[i]->dead == 0 && i != cpn)
		{
			k = (rand() % 2) + 1;
			p[i]->a_or_d = k;
		}
	}
	//컴퓨터들은 공격할 대상을 랜덤으로 정해줌
	for (i = 0; i < planet_num; i++)
	{
		count = 0;
		//플레이어가 공격할 대상은 랜덤화하면 안됨
		if (p[i]->dead == 0 && p[i]->a_or_d == 1 && i != cpn)
		{
			//자기 자신과 싸우면 안되므로
			while (1)
			{
				if (count == 1) break;
				
				ai_enemy = rand() % planet_num;
				if (ai_enemy == i) continue;
				//이미 죽은 행성은 공격 불가
				if (p[i]->dead == 1) continue;
				p[i]->fight = ai_enemy;

				count++;
			}
		}
	}
	if (p[cpn]->a_or_d == 1 && p[cpn]->dead == 0)
	{
		while (1)
		{
			printf("Choose the planet you want to fight : "); scanf("%d", &enemy);
			if (p[enemy]->population <= 0)
			{
				printf("The planet is already doomed \n");
				continue;
			}
			p[cpn]->fight = enemy - 1;
			break;
		}
	}
}

//전쟁 함수
void  battle(Planet** p, int cpn, int planet_num)
{
	int i;
	int enemy = 0;
	
	for (i = 0; i < planet_num; i++)
	{
		if (p[i]->a_or_d == 1)
		{
			enemy = p[i]->fight;
			printf("Planet %d", i+1);
			if (i == cpn) printf("(your planet)");
			printf(" ==(Attack)==> Planet % d \n", enemy + 1);
			
			if (p[i]->attk_p > p[i][enemy].def_p)
			{
				printf("Planet %d", i + 1);
				if (i == cpn) printf("(your planet)");
				printf(" : win ====> Planet % d : lose \n", enemy + 1);

				p[i]->population += 300;
				p[i][enemy].population -= 500;
			}
			if (p[i]->attk_p < p[i][enemy].def_p)
			{
				printf("Planet %d", i + 1);
				if (i == cpn) printf("(your planet)");
				printf(" : lose ====> Planet % d : win \n", enemy + 1);

				p[i]->population -= 500;
			}
			if (p[i]->attk_p == p[i][enemy].def_p)
			{
				printf("Planet %d", i + 1);
				if (i == cpn) printf("(your planet)");
				printf(" : Draw ====> Planet % d : Draw \n", enemy + 1);
			}
			p[i]->fight = -1;
		}
		p[i]->a_or_d = 0;
	}
}

//행성의 인구가 500이하로 줄면 멸망
void planet_dead(Planet** p, int planet_num)
{
	int i;

	for (i = 0; i < planet_num; i++)
	{
		if (p[i]->population <= 500)
		{
			p[i]->population = 0;
			p[i]->a_or_d = 0;
			p[i]->dead = 1;
		}
	}
}

int game_over(Planet** p, int planet_num)
{
	int i;
	int winner;
	int count = 0;

	for (i = 0; i < planet_num; i++)
	{
		if (p[i]->dead == 1) count++;
	}
	if (count == planet_num - 1)
	{
		for (i = 0; i < planet_num; i++)
		{
			if (p[i]->dead == 0) winner = i;
		}
		printf("Planet %d Ruled the Universe! \n", winner + 1);
		return 1;
	}
	return 0;
}

//우주 전쟁
void cosmic_war(Planet **p, int cpn, int planet_num)
{
	int gameover;

	planet_init(p, planet_num);
	change_planet_status(p, planet_num);
	
	while (1)
	{
		show_planet_status(p, cpn, planet_num);
		choose_attk_def(p, cpn, planet_num);
		press_anyKey_continue();
		
		change_planet_status(p, planet_num);
		show_planet_status(p, cpn, planet_num);
		
		battle(p, cpn, planet_num);
		planet_dead(p, planet_num);
		
		change_planet_population(p, planet_num);
		change_planet_status(p, planet_num);
		press_anyKey_continue();

		gameover = game_over(p, planet_num);

		if (gameover == 1) break;
	}
}