#include "show.h"

//create_all 이후 우주 생성되었을 떄 우주 안의 은하의 정보 보여줌.

void show_universe_info(Universe *universe, char **univ_board){
    int i;
    printf("전체 은하의 수 : %d \n", universe->galaxy_num);
    show_Board(univ_board);
    
    printf("\n");
    for(i=0; i < universe->galaxy_num; i++)
    {
        printf("은하 %d의 이름 : %s\n",i,  universe->galaxy_arr[0]->name);
    }
}

void show_galaxy_info(Galaxy *galaxy, char **galaxy_board){
    int i;
    printf("전체 행성의 수 : %d \n", galaxy->planet_num);
    printf("\n");
    for(i=0; i < galaxy->planet_num; i++)
    {
    printf("은하 %d의 이름 : %s\n",i,  galaxy->planet_arr[0]->name);
    }

    show_Board(galaxy_board);

    
}

//단일 행성의 info들
void show_planet_info(Planet *planet){
    Planet *p;
    char *name;
	int brood;

	int population;
	double power;
	double armor;
	int attack_or_defense;
	int x,y;

    printf("@@@@@@@@@@@@   행성 %s   @@@@@@@@@@\n", p->name);
    printf("이름: %s\n", p->name);
    printf("종족: ");   showBroodName(brood);

    printf("@@@@@@@@@@@@@@@@@@@@@@@@@\n\n");
    printf("인구 수: %s\n", population);
    printf("공격력: %s\n", power);
    printf("방어력: %s\n",  armor);
    printf("현재 공/방 상태: ");    showAttackORDefense(attack_or_defense);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@\n");
    
}


//은하, 행성 시각화용 보드.
char **makeBoard(void){
	char **board = (char **)malloc(sizeof(char *) * MAX_Y_COORD + MAX_RADIUS );
	if(!board){
		printf("메모리 할당 실패!\n");
	}
	for(int i = 0; i < MAX_Y_COORD+MAX_RADIUS; i++)
	{
		board[i] = (char *)malloc(sizeof(char) * MAX_X_COORD +MAX_RADIUS);
		memset (board[i], ' ' , MAX_X_COORD+4);
		board[MAX_X_COORD + MAX_RADIUS -1] = '\0';
	}
	return board;
}

//은하 시각화용
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
*초기 행성 시각화용 버전
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