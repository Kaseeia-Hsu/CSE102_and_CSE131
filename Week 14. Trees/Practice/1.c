#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int plus(int *num1, int *num2){
	return *num1+*num2;
}

int minus(int *num1, int *num2){
	return *num1-*num2;
}

int cross(int *num1, int *num2){
	return (*num1)*(*num2);
}

int divide(int *num1, int *num2){
	return (*num1)/(*num2);
}
int main(){
	char op;
	int num1, num2;
	int res;
	
	printf("請輸入要執行的運算:");
	scanf("%c", &op);
	printf("請輸入要運算的數字:");
	scanf(" %d %d", &num1, &num2);
	
	switch(op){
		case '+': printf("執行兩數相加函式");
				res=plus(&num1, &num2);
				printf("\nAnswer: %d", res);
				break;
		case '-': printf("執行兩數相減函式");
				res=minus(&num1, &num2);
				printf("\nAnswer: %d", res);
				break;
		case '*': printf("執行兩數相乘函式");
				res=cross(&num1, &num2);
				printf("\nAnswer: %d", res);
				break;
		case '/': printf("執行兩數相除函式");
				res=divide(&num1, &num2);
				printf("\nAnswer: %d", res);
				break;
	}
	
	return 0;
} 
