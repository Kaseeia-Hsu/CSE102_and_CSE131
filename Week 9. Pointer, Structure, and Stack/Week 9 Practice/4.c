#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str1[100];
	int i, len, compare=1;
	
	printf("�п�J�r��:");
	scanf("%s", str1);
	
	len=strlen(str1);
		
	for(i=0; i<=len; i++)
	{
		if(str1[i]!=str1[len-i-1])	//-1 since that the end of string is at len-1(0~len-1)
		{
			compare=0;
			break;
		}
	}
	
	if(compare==1)
	{
		printf("�O�j��");
	}
		
	else
	{
		printf("���O�j��");
	}
		
	
	return 0;
}
