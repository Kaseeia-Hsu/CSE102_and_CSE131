#include <stdio.h>

int main()
{
	int height, i, j;
	printf("請輸入等腰三角形的高度:");
	scanf("%d", &height);
	
	for(i=1; i<=height; i++)
	{
		for(j=1; j<=height-i; j++)
		printf(" ");
		for(j=1; j<=i*2-1; j++)
		printf("*");
		printf("\n");
	}
	
	return 0;
}
