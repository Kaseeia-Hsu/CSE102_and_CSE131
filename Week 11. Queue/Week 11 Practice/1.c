#include <stdio.h>
#include <stdlib.h>

int gcd(int, int);
int lcm(int, int, int);

int main()
{
	int num1, num2, valuegcd, valuelcm;
	printf("Enter 2 positive numbers:");
	scanf("%d %d", &num1, &num2);
	
	valuegcd=gcd(num1, num2);
	valuelcm=lcm(num1, num2, valuegcd);
	
	printf("GCD= %d\n",valuegcd);
	printf("LCM= %d\n",valuelcm);
	
	return 0;
} 

int gcd(int n1, int n2){
	
	int i, gcdv;
	
	for(i=1; i<=n1 && i<=n2; i++){
		if(n1%i==0 && n2%i==0)
		gcdv=i;
	}
	
	return gcdv;
}


int lcm(int n1, int n2, int n3){
	
	int lcmv;
	lcmv=(n1*n2)/n3;
	
	return lcmv;
}
