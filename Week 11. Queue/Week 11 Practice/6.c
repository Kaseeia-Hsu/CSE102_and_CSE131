#include <stdio.h>
#include <stdlib.h>

int pow(int, int);

int main(){
	int i, num, num1, value;
	printf("請輸入兩數:");
	scanf("%d %d", &num, &num1);	
	value=pow(num, num1);
	printf("%d", value);
	return 0;
}

int pow(int x, int y){
	if(y==0)
	return 1;
	
	if(y==1)
	return x;
	
	return pow(x, y-1)*x;
}
