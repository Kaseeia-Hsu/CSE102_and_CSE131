#include <stdio.h>

int main()
{
	char character;
	printf("�п�J�@�Ӧr��:");
	scanf("%c", &character);
	
	switch(character){
		case 'A':
		case 'a':	
			printf("�i�J�s�W�\��");
			break;
		case 'D':
		case 'd':
			printf("�i�J�R���\��");
			break;
		case 'U':
		case 'u':
			printf("�i�J�ק�\��");
			break;
		case 'Q':
		case 'q':
			printf("���}�t��");
			break;
		default:
			printf("�S���o�ӿﶵ"); 
			break;	
}
return 0;
}
