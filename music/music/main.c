//palySound 함수 이용 사운드 파일 재생
#include "music.h"


void main() {
	int num;
	int def;
	while (1) {
		printf("0. opening    1. terran    2. zerg    3. protoss    4. ending     5. 프로그램 종료   : ");
		scanf("%d", &num);
		if (num == 0) opening_sound();
		else if (num == 1) terran_sound();
		else if (num == 2) zerg_sound();
		else if (num == 3) protoss_sound();
		else if (num == 4) {
			printf("승패 여부(승리=1, 패배=0): ");
			scanf("%d", &def);
			ending_sound(def);
		}
		else if (num == 5) break;
	}
}
