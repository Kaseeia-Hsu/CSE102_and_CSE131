#include<stdio.h>

int main()
{
	int number, i;
	printf("�п�J�@�ӼƦr(0~100):");
	scanf("%d", &number);
	
	for(i=0; i<number; i += 2)
	printf("%d�O����\n",i);
	
	return 0;
 } 
