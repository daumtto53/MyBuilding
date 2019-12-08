/*?????????? ????*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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


//scanf(%d) ???? ???? ????????
//???? ???? ???? ???? ?? -1 ????.
int get_Integer(char *strArr)
{
    int num, numLen;
    int i;

    printf("???? ???? : ");
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