#ifndef __SHOW_H__
#define __SHOW_H__

#include "universe.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_universe_info(Universe *universe, char **univ_board);
void show_galaxy_info(Galaxy *galaxy, char **galaxy_board);
void show_planet_info(Planet *planet);


char **makeBoard(void);

void setBoardToSquare(char **board, Galaxy *galaxy);
void Galaxy_coordToSquare(char **board, Universe *universe);
void setBoardToCircle_ver2(char **board, Planet *planet);
void Planet_coordToCircle(char **board, Galaxy *galaxy);
void show_Board(char **board);

#endif