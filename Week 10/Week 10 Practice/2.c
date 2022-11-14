#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *file = fopen("test.txt", "w");
	char user[100];
	gets(user);
	
	fputs(user, file);
	fclose(file);
	
	printf("Writting finished.");
	return 0;
}
