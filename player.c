#include "player.h"

void getPlayerGalaxy(Player *player, Universe *universe) {
	printf("볼 은하의 번호를  선택해 주십시오\n");
	int player_galaxy = askNumBtw(0, (universe->galaxy_num)-1);
	player->player_galaxy = universe->galaxy_arr[player_galaxy];
	printf("%d 은하의 번호를 선택했습니다!\n", player_galaxy);
}

void getPlayerPlanet(Player *player, Galaxy *galaxy) {
	printf("볼 행성의 번호를  선택해 주십시오\n");
	int player_planet = askNumBtw(0, galaxy->planet_num - 1);
	player->player_planet = galaxy->planet_arr[player_planet];
	printf("행성의 번호를 선택했습니다!\n");
}