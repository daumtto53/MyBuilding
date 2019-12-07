#pragma once
#include <stdio.h >

#include "datatype.h"

int makeGalaxy(Planet*** p_addr);
void makePlanet(Planet** p, int galaxy);

void make_Universe();
void show_Universe(Planet** p, int galaxy);

int choose_Galaxy(Planet** p, int galaxy_num);
int input_planet_info(Planet* p);
int choose_planet(Planet* p);
void race_info();

void planet_init(Planet* p, int planet_num);
void change_planet_population(Planet* p, int planet_num);
void change_planet_status(Planet * p, int planet_num);
void show_planet_status(Planet* p, int cpn, int planet_num);
void choose_attk_def(Planet* p, int cpn, int planet_num);
void  battle(Planet* p, int cpn, int planet_num);
void planet_dead(Planet* p, int planet_num);
int game_over(Planet* p, int planet_num);

void cosmic_war(Planet* p, int cpn, int planet_num);