#ifndef __UNIVERSE_H__
#define __UNIVERSE_H__

#define TERRAN 1
#define ZERG 2
#define PROTOSS 3

#define NAME_LENGTH 8

#define MAX_OBJECT 10
#define MIN_OBJECT 2

#define MAX_X_COORD 150
#define MAX_Y_COORD 150
#define MIN_X_COORD 10
#define MIN_Y_COORD 10

#define MAX_RADIUS 20

#define MIN_POPULATION 100
#define MAX_POPULATION 200
#define MIN_POWER 10
#define MAX_POWER 20
#define MIN_ARMOR 10
#define MAX_ARMOR 20
#define ATTACK_MODE 2
#define DEFENSE_MODE 1


typedef struct planet
{
	char *name;
	int brood;
	int population;
	double power;
	double armor;
	int attack_or_defense;
	int x,y;
}Planet;

typedef struct galaxy
{
	char *name;
	Planet **planet_arr;
	int planet_num;
    int x,y;
}Galaxy;

typedef struct universe
{
	Galaxy **galaxy_arr;
	int galaxy_num;
}Universe;

Universe *create_Universe(Universe *universe);
Galaxy *create_Galaxy(void);
Planet *create_Planet(void);
Planet *init_Planet(Planet *planet);
Universe *create_all(Universe *universe);

#endif