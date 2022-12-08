#include <stdio.h>

int main()
{
	float num1;
	
	printf("Please enter a number:");
	scanf("%f", &num1);
	printf("%10.1f\n", num1);
	printf("%010.2f\n", num1);
	printf("% +9.4f\n", num1);
	printf("%-f\n", num1);

	return 0;
}
