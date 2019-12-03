/*예외처리용 함수*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#include "util.h"

//문자열 입력받기. 최대 maxLen자
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


//scanf(%d) 대신 숫자 입력받기
//정수 받기 실패 했을 떄 -1 반환.
int get_Integer(char *strArr)
{
    int num, numLen;
    int i;

    printf("숫자 입력 : ");
    numLen = get_String(strArr, INT_LEN);
    printf("\n");
    
    i=0;
    while(i < numLen && isdigit(strArr[i++]));
    if(i != numLen)
        return -1;

    num = atoi(strArr);
    return num;
}

//begin<= x <= end까지 숫자 입력받기.
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

// begin에서 end까지 랜덤한 숫자 리턴.
int get_Rand_Btw(int begin, int end)
{
    int num;
    num = rand() % (end - begin) + begin;
    return num;
}