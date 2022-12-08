#include <stdio.h>
#include <stdlib.h>

int fib(int);

int main(){
	int i, num, value;
	printf("請輸入一個數字:");
	scanf("%d", &num);	
	
	for(i=1; i<=num; i++){
		value=fib(i);
		printf("%4d", value);
	}
	
	return 0;
}

int fib(int i){
	if(i<=2){
		return 1;
	}
	else
	return fib(i-1)+fib(i-2);
}
