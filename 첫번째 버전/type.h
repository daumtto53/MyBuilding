#pragma once

#define TERRAN 1
#define ZERG 2
#define PROTOSS 3

typedef struct planet
{
	char brood;
	int population;
	double power;
	double armor;
	int attack_or_defense;
	int x,y;
}Planet;

typedef struct galaxy
{
	Planet* planet_arr;
	int planet_num;
}Galaxy;

typedef struct universe
{
	Galaxy* galaxy_arr;
	int galaxy_num;
}Universe;