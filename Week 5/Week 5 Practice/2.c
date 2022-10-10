#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int random, i, j;
	printf("請輸入一個數字(1~100):");
	scanf("%d", &i);
	
	srand(time(NULL));
	for(j=1; j<=i; j++)
	{
		random= rand() % 500+1;
		printf("第%d個隨機數字是%d\n", j, random);
	}
	
	return 0;
}
