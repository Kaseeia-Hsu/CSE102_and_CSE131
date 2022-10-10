#include<stdio.h>

int main()
{
	int number, i;
	printf("請輸入一個數字(0~100):");
	scanf("%d", &number);
	
	for(i=0; i<number; i += 2)
	printf("%d是偶數\n",i);
	
	return 0;
 } 
