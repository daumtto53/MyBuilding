#ifndef __SHOW_H__
#define __SHOW_H__

#include "universe.h"

void show_universe_info(Universe *universe);
char **makeBoard(void);
void setBoardToSquare(char **board, Galaxy *galaxy);
void galaxyCoordToSquare(char **board, Universe *universe);
void setBoardToCircle_ver2(char **board, Planet *planet);
void Planet_coordToCircle(char **board, Galaxy *galaxy);
void show_Board(char **board);

#endif