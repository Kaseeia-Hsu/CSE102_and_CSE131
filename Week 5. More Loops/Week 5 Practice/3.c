#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int lines, i, j;
	printf("�ШϥΪ̿�J�@�ӼƦr(1~100):");
	scanf("%d", &lines);
	
	for(i=1; i<=lines; i++)
	{
		for(j=1; j<=i; j++)
		printf("*");
		printf("\n");
	}
	
	return 0;
}
