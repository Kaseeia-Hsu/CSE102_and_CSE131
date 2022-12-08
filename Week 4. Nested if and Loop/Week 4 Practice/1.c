#include <stdio.h>

int main()
{
	int num;
	printf("請輸入一個整數字(0~100):");
	scanf("%d", &num);
	
	if(num>=0 && num<=33){
		printf("幸運區");
}
	if(num<72 && num>33){
		printf("GG了");
}
		
	if(num>=72 && num<=100){
		printf("幸運區");
}
	
	if(num>100 || num<0){
		printf("輸入的值不在範圍，請重新輸入");
}
	return 0;
 } 
