#include <stdio.h>

int main()
{
	int year;
	printf("�п�J�~��:");
	scanf("%d", &year);
	
	if(year%4==0 && year%100 !=0)
	printf("%d�~�O�|�~", year);
	
	else if(year%400==0 && year%3200 !=0)
	printf("%d�~�O�|�~", year);
	
	else
	printf("%d�~���O�|�~", year);
	
	return 0;
}
