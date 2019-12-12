#pragma once

#include "type.h"

void init_Planet(Planet* p, char brood, int population);
void init_Galaxy(Galaxy* g, int planet_num);
void init_Universe(Universe* u, int galaxy_num);
void set_Ability(Planet* p);

void add_Planet(Galaxy* g, char brood, int population);
void war(Planet* p1, Planet* p2);
void winner(Galaxy* g);

void print_Planet(Planet* p);
void print_Galaxy(Galaxy* g);
void print_Universe(Universe* u);

void broodwar(Universe* u);