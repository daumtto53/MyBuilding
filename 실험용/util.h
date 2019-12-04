/*예외처리용 함수*/

#ifndef __UTIL_H__
#define __UTIL_H__

#define MAXBUFF 100
#define INT_LEN 10

int get_String(char *strArr, int maxLen);
int get_Integer(char *strArr);
int get_Integer_Btw(int begin, int end);
int get_Rand_Btw(int begin, int end);

#endif