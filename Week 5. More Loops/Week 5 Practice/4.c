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
		printf("�п�J�@�ӼƦr:");
		scanf("%d", &number);
		if(number != random)
		printf("�q���F!\n");
		else
		{
			printf("�q��F!");
			break;
		}
		getchar();
	}
	
	return 0;
}
