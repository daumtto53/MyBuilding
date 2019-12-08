#pragma once

#define TERRAN 'T'
#define ZERG 'Z'
#define PROTOSS 'P'

typedef struct planet
{
	char brood;
	int population;
	double power;
	double defense;
	double armor;
	int attack_or_defense;
	int x,y;
}Planet;

typedef struct galaxy
{
	Planet* planets;
	int planet_num;
}Galaxy;

typedef struct universe
{
	Galaxy* galaxies;
	int galaxy_num;
}Universe;