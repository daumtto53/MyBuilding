#include "music.h"


void opening_sound() {
	PlaySound(TEXT("opening.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void terran_sound() {
	PlaySound(TEXT("terran.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void protoss_sound() {
	PlaySound(TEXT("protoss.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void zerg_sound() {
	PlaySound(TEXT("zerg.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void ending_sound(int def) {
	PlaySound(TEXT("ending.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	system("cls");
	if (def == 1) { 
		printf("¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú\n");
		printf("¡Ú                                        ¡Ú\n");
		printf("¡Ú  ¡á      ¡á      ¡á   ¡á   ¡á      ¡á  ¡Ú\n");
		printf("¡Ú   ¡á   ¡á  ¡á   ¡á         ¡á¡á    ¡á  ¡Ú\n");
		printf("¡Ú    ¡á ¡á    ¡á ¡á     ¡á   ¡á  ¡á  ¡á  ¡Ú\n");
		printf("¡Ú     ¡á        ¡á      ¡á   ¡á    ¡á¡á  ¡Ú\n");
		printf("¡Ú                                        ¡Ú\n");
		printf("¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú¡Ú\n");
	}
	else {
		printf("¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì\n");
		printf("¢Ì                                              ¢Ì\n");
		printf("¢Ì  ¡á          ¡á¡á      ¡á¡á¡á¡á    ¡á¡á¡á¡á  ¢Ì\n");
		printf("¢Ì  ¡á        ¡á    ¡á    ¡á          ¡á        ¢Ì\n");
		printf("¢Ì  ¡á       ¡á      ¡á   ¡á¡á¡á¡á    ¡á¡á¡á¡á  ¢Ì\n");
		printf("¢Ì  ¡á        ¡á    ¡á          ¡á    ¡á        ¢Ì\n");
		printf("¢Ì  ¡á¡á¡á¡á    ¡á¡á      ¡á¡á¡á¡á    ¡á¡á¡á¡á  ¢Ì\n");
		printf("¢Ì                                              ¢Ì\n");
		printf("¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì¢Ì\n");
	}
	printf("\n               Class-B  group-6\n\n");
	printf("                15ÇÐ¹ø Ãµ¹Î¼ö\n\n");
	printf("                15ÇÐ¹ø Àü¿ì¼®\n\n");
	printf("                16ÇÐ¹ø Á¤¿ìÈÖ\n\n");
	printf("                19ÇÐ¹ø È«½ÂÅÃ\n\n\n");
	printf("  Made by Konkuk univ Computer Science and Engineering\n\n\n");
}
