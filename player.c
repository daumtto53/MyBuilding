#include "player.h"

void getPlayerGalaxy(Player *player, Universe *universe) {
	printf("�� ������ ��ȣ��  ������ �ֽʽÿ�\n");
	int player_galaxy = askNumBtw(0, (universe->galaxy_num)-1);
	player->player_galaxy = universe->galaxy_arr[player_galaxy];
	printf("%d ������ ��ȣ�� �����߽��ϴ�!\n", player_galaxy);
}

void getPlayerPlanet(Player *player, Galaxy *galaxy) {
	printf("�� �༺�� ��ȣ��  ������ �ֽʽÿ�\n");
	int player_planet = askNumBtw(0, galaxy->planet_num - 1);
	player->player_planet = galaxy->planet_arr[player_planet];
	printf("�༺�� ��ȣ�� �����߽��ϴ�!\n");
}