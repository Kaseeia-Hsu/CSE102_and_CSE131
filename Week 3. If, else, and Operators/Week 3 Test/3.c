#include <stdio.h>

int main()
{
	char character;
	int charnum;
	int lower;
	char lowercha;
	printf("Please enter a capital letter:");
	scanf("%c", &character);
	
	charnum = (int) character;
	lower = character - 65 + 97;
	lowercha = (char) lower;
	printf("�A��J���r���p�g�O%c", lowercha);
	return 0;
}
