#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char string[100];
	
	printf("請輸入一個字串:");
	scanf("%s", string);
	
	for(i=0; i<3; i++)
	{
		printf("該字串為: %s\n", string);
	}
	
	fflush(stdin);
	
	int j;
	char string1[100];
		
	puts("請輸入一個字串:");
	gets(string1);
	
	for(j=0; j<3; j++)
	{
		puts("該字串為: ");
		puts(string1);
	}
	
	return 0;
}
