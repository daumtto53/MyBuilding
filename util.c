/*?????????? ????*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "util.h"

void press_anyKey_continue()
{
	printf("\n press any key to continue.");

	system("PAUSE > NULL");

	system("cls");
}

//?????? ????????. ???? maxLen??
int get_String(char *strArr, int maxLen)
{
    int i;

    printf("Input String: ");
    for(i=0;i<maxLen-1;i++)
    {
        strArr[i] = getchar();
        if(strArr[i] == '\n')
            break;
    }
    strArr[i] = '\0';
    return i;
}

//start부터 end까지 숫자 입력받고, 미만, 초과면 다시 입력받는 입력용 함수.
int askNumBtw(int start, int end)
{
	int num = -21312313;
	do
	{
		printf("%d부터 %d까지의 숫자를 입력해 주세요\n", start, end);
		scanf("%d", &num);
	} while (!(num >= start && num <= end));

	return num;
}




//scanf(%d) ???? ???? ????????
//???? ???? ???? ???? ?? -1 ????.
int get_Integer(char *strArr)
{
    int num, numLen;
    int i;

    numLen = get_String(strArr, INT_LEN);
    printf("\n");
    
    i=0;
    while(i < numLen && isdigit(strArr[i++]));
    if(i != numLen)
        return -1;

    num = atoi(strArr);
    return num;
}

//begin<= x <= end???? ???? ????????.
int get_Integer_Btw(int begin, int end)
{
    int num;
    char strArr[INT_LEN+1];
    do
    {
        num = get_Integer(strArr);
    } while(num < begin && num > end);

    return num;
}


int get_Rand_Btw(int begin, int end)
{
    int num;
    num = rand() % (end - begin) + begin;
    return num;
}

char *make_Random_Name(int len){
    char *temp_name = malloc(sizeof(char) * len + 1);
    temp_name[len] = '\0';

    int num;
    int i;
    //srand(time(NULL));
    for(i=0; i < len; i ++){
		num = (rand() % 74) + 48;
        temp_name[i] = num;
    }
    return temp_name;
}

/*
#define TERRAN 1
#define ZERG 2
#define PROTOSS 3
*/
void showBroodName(int i){
    switch(i){
        case 1:
            printf("Terran\n");
            break;
        case 2:
            printf("ZERG\n");
            break;
        case 3:
            printf("Protoss\n");
            break;
    }
}

void showAttackORDefense(int i){
    switch(i){
        case 1:
            printf("공격\n");
            break;
        case 2:
            printf("방어\n");
            break;
    }
}