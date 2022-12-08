#include <stdio.h>

int main()
{
	int num;
	printf("請輸入1~13之間的整數:");
	scanf("%d", &num);
	
	if(num>7)
	printf("該數大於7");
	
	else if(num<7)
	printf("該數小於七");
	
	else
	printf("該數等於七");
	
	return 0;
}
