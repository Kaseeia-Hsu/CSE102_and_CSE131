#include <stdio.h>

int main()
{
	int num;
	printf("請輸入一整數:");
	scanf("%d", &num);
	
	if(num<0)
	{
	num = 0 - num;
	printf("絕對值為:%d",num);
	}
	else
	printf("絕對值為:%d",num);
	
	return 0;
}
