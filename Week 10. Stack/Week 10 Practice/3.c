#include <stdio.h>
#include <stdlib.h>

int continued_product(int);

int main()
{
	int num, outcome;
	printf("Enter a positive number:");
	scanf("%d", &num);
	
	outcome=continued_product(num);
	
	printf("Outcome is: %d", outcome);
	return 0;
}

int continued_product(int length)
{
	int i, cp=1;
	for(i=1; i<=length; i++)
	{
		cp=cp*i;
	}
	return cp;
}
