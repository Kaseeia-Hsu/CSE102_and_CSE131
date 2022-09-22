#include<stdio.h>
#define Pi 3.1415926 

int main()
{
	int r;
	float v1;
	double v2;
	
	printf("Enter the value 'r':");
	scanf("%d", &r);
	
	v1 = r*r*r*Pi*4/3;
	v2 = r*r*r*Pi*4/3;
	
	printf("Åé¿nf: %.12f\n", v1);
	printf("Åé¿nd: %.12lf\n", v2);
	return 0;
 } 
