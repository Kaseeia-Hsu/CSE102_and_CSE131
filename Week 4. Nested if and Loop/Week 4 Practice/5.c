#include <stdio.h>

int main()
{
	int num;
	printf("��J�@�Ӿ��:");
	scanf("%d", &num);
	
	switch(num){
	case 99:
		printf("��J�F99");
		break;
	default:
		printf("��J�F�ҥ~�Ʀr:%d", num);
	}
	
	return 0;
}
