#include <stdio.h>
#include <stdlib.h>

int main()
{
	char string[3][10];
	int i;
	
	puts("Please enter 3 strings:");
	for(i=0; i<3; i++)
	{
		scanf("%s", string[i]);
	}
	
	printf("�T�r�ꬰ:");
	for(i=0; i<3; i++)
	{
		printf("%s", string[i]);
	}
	
	printf("\n�ϧǬ�:");
	for(i=2; i>=0; i--)
	{
		printf("%s", string[i]);
	}
	
	return 0;
}
