//�}�o����: Dev-C++ 5.11 

#include <stdio.h>

int main()
{
	int num;
	
	//�q�ϥΪ̤�������N�Ʀr
	//Getting a value from the users 
	printf("How much is it:");
	scanf("%d", &num);
	
	//�Q�Ψ��l�Ƥΰ��k�\���{�����������\�� 
	//Using modulo and division to realized the feature 
	printf("NT 100: %d\n", num/100);
	printf("NT 50: %d\n", (num%100)/50);
	printf("NT 10: %d\n", (num%100)%50/10);
	printf("NT 5: %d\n", (num%100)%50%10/5);
	printf("NT 1: %d\n", (num%100)%50%10%5/1);

	return 0;
 } 
