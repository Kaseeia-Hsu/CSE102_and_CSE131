#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int random, number;
	srand(time(NULL));
	random = rand() % 10+1;
	
	while(random != 0)
	{
		printf("請輸入一個數字:");
		scanf("%d", &number);
		if(number != random)
		printf("猜錯了!\n");
		else
		{
			printf("猜對了!");
			break;
		}
		getchar();
	}
	
	return 0;
}
