#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	char string[100];
	
	printf("�п�J�@�Ӧr��:");
	scanf("%s", string);
	
	for(i=0; i<3; i++)
	{
		printf("�Ӧr�ꬰ: %s\n", string);
	}
	
	fflush(stdin);
	
	int j;
	char string1[100];
		
	puts("�п�J�@�Ӧr��:");
	gets(string1);
	
	for(j=0; j<3; j++)
	{
		puts("�Ӧr�ꬰ: ");
		puts(string1);
	}
	
	return 0;
}
