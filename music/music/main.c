//palySound �Լ� �̿� ���� ���� ���
#include "music.h"


void main() {
	int num;
	int def;
	while (1) {
		printf("0. opening    1. terran    2. zerg    3. protoss    4. ending     5. ���α׷� ����   : ");
		scanf("%d", &num);
		if (num == 0) opening_sound();
		else if (num == 1) terran_sound();
		else if (num == 2) zerg_sound();
		else if (num == 3) protoss_sound();
		else if (num == 4) {
			printf("���� ����(�¸�=1, �й�=0): ");
			scanf("%d", &def);
			ending_sound(def);
		}
		else if (num == 5) break;
	}
}
