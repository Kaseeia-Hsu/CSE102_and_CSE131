#include <stdio.h>

int main() 
{
	int n1 = 123;
	float f1 = 123.4567;
	double f2 = 123.4567;
	printf("-------------------\n");
	printf("���n1: %d\n", n1);
	printf("%%8d ���G: %8d\n", n1);
	printf("%%.8d ���G: %.8d\n", n1);
	printf("%%06d ���G: %06d\n", n1);
	printf("---------�ڬO���j�u----------\n");
	printf("���ׯB�I��f1: %f\n", f1);
	printf("����ׯB�I��f2: %lf\n",f2);
	printf("-------------------\n");
	printf("%%.4f ���G: %.4f\n", f1);
	printf("%%10.4f ���G: %10.4f\n", f1);
	printf("%%lf ���G: %lf",f2);
	return 0;
}
