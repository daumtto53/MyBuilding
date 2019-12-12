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
		printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
		printf("��                                        ��\n");
		printf("��  ��      ��      ��   ��   ��      ��  ��\n");
		printf("��   ��   ��  ��   ��         ���    ��  ��\n");
		printf("��    �� ��    �� ��     ��   ��  ��  ��  ��\n");
		printf("��     ��        ��      ��   ��    ���  ��\n");
		printf("��                                        ��\n");
		printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�\n");
	}
	else {
		printf("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�\n");
		printf("��                                              ��\n");
		printf("��  ��          ���      �����    �����  ��\n");
		printf("��  ��        ��    ��    ��          ��        ��\n");
		printf("��  ��       ��      ��   �����    �����  ��\n");
		printf("��  ��        ��    ��          ��    ��        ��\n");
		printf("��  �����    ���      �����    �����  ��\n");
		printf("��                                              ��\n");
		printf("�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�\n");
	}
	printf("\n               Class-B  group-6\n\n");
	printf("                15�й� õ�μ�\n\n");
	printf("                15�й� ���켮\n\n");
	printf("                16�й� ������\n\n");
	printf("                19�й� ȫ����\n\n\n");
	printf("  Made by Konkuk univ Computer Science and Engineering\n\n\n");
}
