#include <stdio.h>

int main()
{
	int a=32767;
	short int b=32767;
	
	printf("整數a=%d\n", a);
	printf("短整數b=%d\n", b);
	
	a=a+1;
	printf("a+1=%d\n", a);
	
	b=b+1;
	printf("b+1=%d", b);
	
	return 0;
 } 
