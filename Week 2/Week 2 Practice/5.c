#include <stdio.h>

int main()
{
	int price, quantity, sum, change, pay, thousand, fivehun, hundred, ten, five, one;
	
	printf("�w��Ө����t��!\n");
	printf("���:");
	scanf("%d", &price);
	printf("�ƶq:");
	scanf("%d", &quantity);
	sum=price*quantity;
	printf("���B: %d\n", sum);
	printf("�ꦬ:");
	scanf("%d", &pay);
	
	//��s�p��y�{ 
	thousand=(pay-sum)/1000;
	hundred=(pay-sum)%1000%500/100;
	fivehun=(pay-sum)%1000/500;
	ten=(pay-sum)%1000%500%100/10;
	five=(pay-sum)%1000%500%100%10/5;
	one=(pay-sum)%1000%500%100%10%5/1;
	 
	printf("��s�p�U:\n");
	printf("1000��: %d\n", thousand);
	printf("500��: %d\n", fivehun);
	printf("100��: %d\n", hundred);
	printf("10��: %d\n", ten);
	printf("5��: %d\n", five);
	printf("1��: %d\n", one);
	
	return 0;
 } 
