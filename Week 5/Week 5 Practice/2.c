#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int random, i, j;
	printf("�п�J�@�ӼƦr(1~100):");
	scanf("%d", &i);
	
	srand(time(NULL));
	for(j=1; j<=i; j++)
	{
		random= rand() % 500+1;
		printf("��%d���H���Ʀr�O%d\n", j, random);
	}
	
	return 0;
}
