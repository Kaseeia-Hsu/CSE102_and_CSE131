#include <stdio.h>
#include <stdlib.h>
#define AREA(r) 3.1415926*r*r

int main(){
	double r, area;
	printf("�п�J�ꪺ�b�|:");
	scanf("%lf", &r);
	printf("���n��: %lf", AREA(r));
	
	return 0; 
}
