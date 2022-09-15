#include <stdio.h>

int main()
{
	int price, quantity, sum, change, pay, thousand, fivehun, hundred, ten, five, one;
	
	printf("歡迎來到找錢系統!\n");
	printf("單價:");
	scanf("%d", &price);
	printf("數量:");
	scanf("%d", &quantity);
	sum=price*quantity;
	printf("金額: %d\n", sum);
	printf("實收:");
	scanf("%d", &pay);
	
	//找零計算流程 
	thousand=(pay-sum)/1000;
	hundred=(pay-sum)%1000%500/100;
	fivehun=(pay-sum)%1000/500;
	ten=(pay-sum)%1000%500%100/10;
	five=(pay-sum)%1000%500%100%10/5;
	one=(pay-sum)%1000%500%100%10%5/1;
	 
	printf("找零如下:\n");
	printf("1000元: %d\n", thousand);
	printf("500元: %d\n", fivehun);
	printf("100元: %d\n", hundred);
	printf("10元: %d\n", ten);
	printf("5元: %d\n", five);
	printf("1元: %d\n", one);
	
	return 0;
 } 
