//B101020021 徐子群 
//開發環境: Dev-C++ 5.11 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number, i, j, k, l;
    char primeone, primetwo;
    
    printf("請輸入大於二的偶數:");
    scanf("%d",&number);
    
    if(number%2==0, number>2)	//If number is an even and >2.
	{
    	for (i = 3; i < number/2; i += 2)	//開始判斷第一個質數i. 
    		{
        	primeone = 1;
        	
        	for (k = 2; k < sqrt(i); k++)	//判斷k(範圍從2~至根號i)能否整除i. 
            	if (i % k == 0)	//如果能整除, 說明i非質數 
               		primeone = 0;	//因此把primeone設為0 
        	if (primeone)	//倘若primeone非零(則為1, 也就是i為質數的情況) 
        		{
        		j = number - i;	//設另一數j必須要等於number-i 
				primetwo = 1;
				
                	for (l = 2; l < j; l++)	 
                    	if (j % l == 0)	//若j非質數之情況 
                        	primetwo = 0;
                	if (primetwo)	//若j為質數, 且i+j=number 
                    	{
                        	printf("\n%d = %d + %d", number, i, j);
                        	return 0;
                    	}
            	}
        	}
    }
	
	else	//當使用者輸入大於二的偶數以外的東西時便跳出 
	printf("請確認輸入的值為大於二的偶數, 再試一次");
	
	return 0;
}
