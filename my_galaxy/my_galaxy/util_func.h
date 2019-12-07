#include <stdio.h>

//플레이할려면 아무키나 누르도록 하는 함수. Sleep 대신 사용
void press_anyKey_continue()
{
	printf("\n press any key to continue.");

	system("PAUSE > NULL");

	system("cls");
}
