#include "universe.h"

typedef struct player{
	Galaxy *player_galaxy;
	Planet *player_planet;
} Player;

void getPlayerPlanet(Player *player, Galaxy *galaxy);
void getPlayerGalaxy(Player *player, Universe *universe);