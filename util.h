/*예외처리용 함수*/

#ifndef __UTIL_H__
#define __UTIL_H__

#define MAXBUFF 100
#define INT_LEN 10

int get_String(char *strArr, int maxLen);
int get_Integer(char *strArr);
int get_Integer_Btw(int begin, int end);
int get_Rand_Btw(int begin, int end);
void press_anyKey_continue();
char *make_Random_Name(int len);
void showBroodName(int i);
void showAttackORDefense(int i);
int askNumBtw(int start, int end);
void gotoxy(int x, int y);


#endif