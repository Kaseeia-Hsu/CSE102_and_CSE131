#include <stdio.h>

int main()
{
	int num;
	char character;
	printf("�п�J�@�ӼƦr:");
	scanf("%d", &num);
	printf("�п�J�@�Ӧr��:");
	fflush(stdin);
	scanf("%c", &character);
	printf("�ڦ�%d��%c", num, character);
	
	return 0;
}
