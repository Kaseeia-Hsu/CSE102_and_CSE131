#include <stdio.h>

int main()
{
	char character;
	printf("請輸入一個字元:");
	scanf("%c", &character);
	
	switch(character){
		case 'A':
		case 'a':	
			printf("進入新增功能");
			break;
		case 'D':
		case 'd':
			printf("進入刪除功能");
			break;
		case 'U':
		case 'u':
			printf("進入修改功能");
			break;
		case 'Q':
		case 'q':
			printf("離開系統");
			break;
		default:
			printf("沒有這個選項"); 
			break;	
}
return 0;
}
