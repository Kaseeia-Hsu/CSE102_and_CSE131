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
		printf("�п�J�q��:�d��%d~%d:", low, high);
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
			printf("�q��F!");
			break;
		}
	}
	
	return 0;
}


