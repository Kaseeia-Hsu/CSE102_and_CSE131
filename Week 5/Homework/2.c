//B101020021 徐子群 
//開發環境: Dev-C++ 5.11 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int number, digit, sum=0, digit2, sum2=0;
	
	printf("請輸入一正整數:");
	scanf("%d", &number);
	
	if(number<=2*pow(10, 9) && number>0)	//限定輸入數字須為正整數,且小於2x10^9 
	{
		while(number>0)	
		{
			digit = number % 10;	//由%10來取個位數的值 
			sum += digit;	//將個位數的值加總 
			number /= 10;	//在取完個位數的值後, 將輸入數字除以十(將十位移至個位, 直至除到0為止)[^1]
		}
		if(sum>9)	//判斷while迴圈結束後, 加總值sum是否>9(大於一位數) 
		{
			while(sum>0)	 
			{
			digit2 = sum % 10;	//取sum的個位數值 
			sum2 += digit2;	//將sum的個位數值加總 
			sum /=10;	//將sum的十位數移至個位, 直至sum=0, 迴圈結束 
			}
			printf("%d", sum2);	//若sum>9, 則輸出總和為sum2 
			return 0;
		}
		printf("%d", sum);	//若sum僅為一個位數, 則輸出sum本身 
	}
	
	else	//當輸入值>2x10^9 或<=0時呈現 
	printf("輸入的值超出範圍! 請再試一次");
	return 0;
}
