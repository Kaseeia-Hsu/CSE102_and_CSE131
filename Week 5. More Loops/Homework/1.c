//B101020021 �}�l�s 
//�}�o����: Dev-C++ 5.11 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int number, i, j, k, l;
    char primeone, primetwo;
    
    printf("�п�J�j��G������:");
    scanf("%d",&number);
    
    if(number%2==0, number>2)	//If number is an even and >2.
	{
    	for (i = 3; i < number/2; i += 2)	//�}�l�P�_�Ĥ@�ӽ��i. 
    		{
        	primeone = 1;
        	
        	for (k = 2; k < sqrt(i); k++)	//�P�_k(�d��q2~�ܮڸ�i)��_�㰣i. 
            	if (i % k == 0)	//�p�G��㰣, ����i�D��� 
               		primeone = 0;	//�]����primeone�]��0 
        	if (primeone)	//�խYprimeone�D�s(�h��1, �]�N�Oi����ƪ����p) 
        		{
        		j = number - i;	//�]�t�@��j�����n����number-i 
				primetwo = 1;
				
                	for (l = 2; l < j; l++)	 
                    	if (j % l == 0)	//�Yj�D��Ƥ����p 
                        	primetwo = 0;
                	if (primetwo)	//�Yj�����, �Bi+j=number 
                    	{
                        	printf("\n%d = %d + %d", number, i, j);
                        	return 0;
                    	}
            	}
        	}
    }
	
	else	//��ϥΪ̿�J�j��G�����ƥH�~���F��ɫK���X 
	printf("�нT�{��J���Ȭ��j��G������, �A�դ@��");
	
	return 0;
}
