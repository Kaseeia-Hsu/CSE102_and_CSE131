//B101020021 �}�l�s 
//�}�o����: Dev-C++ 5.11 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int number, digit, sum=0, digit2, sum2=0;
	
	printf("�п�J�@�����:");
	scanf("%d", &number);
	
	if(number<=2*pow(10, 9) && number>0)	//���w��J�Ʀr���������,�B�p��2x10^9 
	{
		while(number>0)	
		{
			digit = number % 10;	//��%10�Ө��Ӧ�ƪ��� 
			sum += digit;	//�N�Ӧ�ƪ��ȥ[�` 
			number /= 10;	//�b�����Ӧ�ƪ��ȫ�, �N��J�Ʀr���H�Q(�N�Q�첾�ܭӦ�, ���ܰ���0����)[^1]
		}
		if(sum>9)	//�P�_while�j�鵲����, �[�`��sum�O�_>9(�j��@���) 
		{
			while(sum>0)	 
			{
			digit2 = sum % 10;	//��sum���Ӧ�ƭ� 
			sum2 += digit2;	//�Nsum���Ӧ�ƭȥ[�` 
			sum /=10;	//�Nsum���Q��Ʋ��ܭӦ�, ����sum=0, �j�鵲�� 
			}
			printf("%d", sum2);	//�Ysum>9, �h��X�`�M��sum2 
			return 0;
		}
		printf("%d", sum);	//�Ysum�Ȭ��@�Ӧ��, �h��Xsum���� 
	}
	
	else	//���J��>2x10^9 ��<=0�ɧe�{ 
	printf("��J���ȶW�X�d��! �ЦA�դ@��");
	return 0;
}
