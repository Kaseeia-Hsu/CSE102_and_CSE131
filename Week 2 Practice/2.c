#include <stdio.h>

int main() 
{
	int n1 = 123;
	float f1 = 123.4567;
	double f2 = 123.4567;
	printf("-------------------\n");
	printf("整數n1: %d\n", n1);
	printf("%%8d 結果: %8d\n", n1);
	printf("%%.8d 結果: %.8d\n", n1);
	printf("%%06d 結果: %06d\n", n1);
	printf("---------我是分隔線----------\n");
	printf("單精度浮點數f1: %f\n", f1);
	printf("雙精度浮點數f2: %lf\n",f2);
	printf("-------------------\n");
	printf("%%.4f 結果: %.4f\n", f1);
	printf("%%10.4f 結果: %10.4f\n", f1);
	printf("%%lf 結果: %lf",f2);
	return 0;
}
