#include <stdio.h>

int main()
{
	int num;
	char character;
	printf("請輸入一個數字:");
	scanf("%d", &num);
	printf("請輸入一個字母:");
	fflush(stdin);
	scanf("%c", &character);
	printf("我有%d個%c", num, character);
	
	return 0;
}
