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
	
	printf("�п�J�n���檺�B��:");
	scanf("%c", &op);
	printf("�п�J�n�B�⪺�Ʀr:");
	scanf(" %d %d", &num1, &num2);
	
	switch(op){
		case '+': printf("�����Ƭۥ[�禡");
				res=plus(&num1, &num2);
				printf("\nAnswer: %d", res);
				break;
		case '-': printf("�����Ƭ۴�禡");
				res=minus(&num1, &num2);
				printf("\nAnswer: %d", res);
				break;
		case '*': printf("�����Ƭۭ��禡");
				res=cross(&num1, &num2);
				printf("\nAnswer: %d", res);
				break;
		case '/': printf("�����Ƭ۰��禡");
				res=divide(&num1, &num2);
				printf("\nAnswer: %d", res);
				break;
	}
	
	return 0;
} 
