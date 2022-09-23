//開發環境: Dev-C++ 5.11 

#include <stdio.h>

int main()
{
	//num代表使用者輸入數值, 其餘代表轉為二進位後的位數
	//num stands for the input value from the users,
	//while others are the digits presented in binary form.
	int num, one, two, three, four;
	
	printf("Please enter a number:");
	scanf("%d", &num);
	
	//利用長除法實現二進位轉換
	//Using long division to realize binary transformation. 
	one = num%2;
	two = num/2%2;
	three = num/4%2;
	four = num/8%2;
	
	printf("Output:%d%d%d%d", four, three, two, one);
	
	return 0;
}
