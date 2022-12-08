#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int random, number, low=1, high=99;
	srand(time(NULL));
	random = rand() % 99+1;
	
	while(random !=0)
	{
		printf("請輸入猜測:範圍%d~%d:", low, high);
		scanf("%d", &number);
		
		if(number < random)
		{
		low = number;
		}
		
		else if(number > random)
		{
		high = number;
		} 
		
		else
		{
			printf("猜對了!");
			break;
		}
	}
	
	return 0;
}


