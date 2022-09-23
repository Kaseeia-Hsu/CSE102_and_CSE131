//開發環境: Dev-C++ 5.11 

#include <stdio.h>

int main()
{
	int num;
	
	//從使用者方獲取任意數字
	//Getting a value from the users 
	printf("How much is it:");
	scanf("%d", &num);
	
	//利用取餘數及除法功能實現類似於找錢的功能 
	//Using modulo and division to realized the feature 
	printf("NT 100: %d\n", num/100);
	printf("NT 50: %d\n", (num%100)/50);
	printf("NT 10: %d\n", (num%100)%50/10);
	printf("NT 5: %d\n", (num%100)%50%10/5);
	printf("NT 1: %d\n", (num%100)%50%10%5/1);

	return 0;
 } 
