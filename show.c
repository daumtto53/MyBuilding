#include "show.h"

//create_all ���� ���� �����Ǿ��� �� ���� ���� ������ ���� ������.

void show_universe_info(Universe *universe, char **univ_board){
    int i;
    printf("��ü ������ �� : %d \n", universe->galaxy_num);
    show_Board(univ_board);
    
    printf("\n");
    for(i=0; i < universe->galaxy_num; i++)
    {
        printf("���� %d�� �̸� : %s\n",i,  universe->galaxy_arr[0]->name);
    }
}

void show_galaxy_info(Galaxy *galaxy, char **galaxy_board){
    int i;
    printf("��ü �༺�� �� : %d \n", galaxy->planet_num);
    printf("\n");
    for(i=0; i < galaxy->planet_num; i++)
    {
    printf("���� %d�� �̸� : %s\n",i,  galaxy->planet_arr[0]->name);
    }

    show_Board(galaxy_board);

    
}

//���� �༺�� info��
void show_planet_info(Planet *planet){
    Planet *p;
    char *name;
	int brood;

	int population;
	double power;
	double armor;
	int attack_or_defense;
	int x,y;

    printf("@@@@@@@@@@@@   �༺ %s   @@@@@@@@@@\n", p->name);
    printf("�̸�: %s\n", p->name);
    printf("����: ");   showBroodName(brood);

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
    printf("�α� ��: %s\n", population);
    printf("���ݷ�: %s\n", power);
    printf("����: %s\n",  armor);
    printf("���� ��/�� ����: ");    showAttackORDefense(attack_or_defense);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@\n");
    
}


//����, �༺ �ð�ȭ�� ����.
char **makeBoard(void){
	char **board = (char **)malloc(sizeof(char *) * MAX_Y_COORD + MAX_RADIUS );
	if(!board){
		printf("�޸� �Ҵ� ����!\n");
	}
	for(int i = 0; i < MAX_Y_COORD+MAX_RADIUS; i++)
	{
		board[i] = (char *)malloc(sizeof(char) * MAX_X_COORD +MAX_RADIUS);
		memset (board[i], ' ' , MAX_X_COORD+4);
		board[MAX_X_COORD + MAX_RADIUS -1] = '\0';
	}
	return board;
}

//���� �ð�ȭ��
void setBoardToSquare(char **board, Galaxy *galaxy){
	int sizeDiv2 = rand() % MAX_RADIUS;

	int x,y;

	x = galaxy->x - sizeDiv2;
	y = galaxy->y - sizeDiv2;

	for(int i = x; i <= x + 2*sizeDiv2; i++)
	{
		for(int j = y; j <= y + 2 * sizeDiv2; j++)
		{
			board[i][j] = '@';
		}
	}
}

void galaxyCoordToSquare(char **board, Universe *universe){
	int i;
	Galaxy *temp;
	for(i=0; i < universe->galaxy_num;)
	{
		temp = universe->galaxy_arr[i];
		setBoardToSquare(board, temp);
	}
}

void setBoardToCircle_ver2(char **board, Planet *planet){
	int radius = planet->population / (MAX_POPULATION/5);
	int x,y;
	int center_x, center_y;

	center_x = planet->x;
	center_y = planet->y;

	x = planet->x - radius;
	y = planet->y - radius;

	for(int i = x; i <= x + 4*radius; i++)
	{
		for(int j = y; j <= y + 2 * radius; j++)
		{
			if(2 * (i-center_x)*(i-center_x) + (j-center_y)*(j-center_y) <= radius * radius)
			{
				board[i][j] = '*';
			}
		}
	}
}

void Planet_coordToCircle(char **board, Galaxy *galaxy){
	int i;
	Planet *temp;
	for(i=0; i < galaxy->planet_num;)
	{
		temp = galaxy->planet_arr[i];
		setBoardToCircle_ver2(board, temp);
	}
}

void show_Board(char **board){
	int i;
	int j;

	for(i=0; i < MAX_Y_COORD ; i++)
	{
		for(j=0; j < MAX_X_COORD ; j++){
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}


/*
*�ʱ� �༺ �ð�ȭ�� ����
void setBoardToCircle(char **board, Planet *planet){
	int x,y;
	x = planet->x;
	y = planet->y;

	board[x+1][y] = '*';	board[x-1][y] = '*';
	board[x+2][y] = '*';	board[x-2][y] = '*';
	board[x+3][y] = '*';	board[x+3][y] = '*';

	board[x][y+1] = '*';	board[x][y-1] = '*';
	board[x][y+2] = '*';	board[x][y-2] = '*';
	board[x][y+3] = '*';	board[x][y+3] = '*';
}
*/