#include <stdio.h>

int main()
{
	int num;
	printf("輸入一個整數:");
	scanf("%d", &num);
	
	switch(num){
	case 99:
		printf("輸入了99");
		break;
	default:
		printf("輸入了例外數字:%d", num);
	}
	
	return 0;
}
