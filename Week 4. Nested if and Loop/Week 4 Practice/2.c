#include <stdio.h>

int main()
{
	int num;
	printf("�п�J�@���:");
	scanf("%d", &num);
	
	if(num<0)
	{
	num = 0 - num;
	printf("����Ȭ�:%d",num);
	}
	else
	printf("����Ȭ�:%d",num);
	
	return 0;
}
