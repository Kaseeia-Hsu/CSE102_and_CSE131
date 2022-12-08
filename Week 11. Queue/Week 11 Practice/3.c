#include <stdio.h>
#include <stdlib.h>
#define AREA(r) 3.1415926*r*r

int main(){
	double r, area;
	printf("請輸入圓的半徑:");
	scanf("%lf", &r);
	printf("面積為: %lf", AREA(r));
	
	return 0; 
}
