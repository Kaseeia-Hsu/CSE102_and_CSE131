#include <stdio.h>

int main()
{
	// main �M sub �}�C�����D�\�P���\���B 
	int main[4]={60, 80, 70, 90};
	int sub[3]={30, 40, 40};
	int ice[3]={1, 2, 3};
	int salt[2]={1, 2};
	int i, j, k, h;
	char discount, ans;
	
	printf("�п�J�z�Q�I���D��: 1.�~�� 2.�縥�� 3.�F�� 4.�q�j�Q��\n");
	scanf("%d", &i);
	printf("�п�J�z�Q�I������: 1.���� 2.���� 3.�@��\n");
	scanf("%d", &j);
	
	if(j==1){	//�Y���\��J1. ���� 
	printf("�������B��: 1.���` 2.�L�B 3.�h�B\n");
	scanf("%d", &k);
	}
	
	if(j==2){	//�Y���\��J2, ���� 
	printf("�����Ы�: 1.���`�Q 2.�h�Q\n");
	scanf("%d", &h);
	}
	
	printf("�аݬO�_���馩�X? �Y���п�J�馩�X, �L�п�J(N)\n");
	scanf(" %c", &discount);
	
	printf("�z���I�����H�U:\n");
	
	if(i>=1 && i<=4)	//�P�_�ȤH�D�\��� 
	switch(i){
		case 1:
			printf("�~��x1\n");
			break;
		case 2:
			printf("�縥��x1\n");
			break;
		case 3:
			printf("�F��x1\n");
			break;
		case 4:
			printf("�q�j�Q��x1\n");
			break;
	}
	
	else{
	printf("��J���~!�Э���\n");
	return 0;	
	}
	
	if(j>=1 && j<=3)	//�P�_�ȤH���\��� 
	switch(j){
		case 1:
			printf("����");
			break;
		case 2:
			printf("����");
			break;
		case 3:
			printf("�@��x1");
			break;
	}
	
	else{
	printf("��J���~!�Э���");
	return 0;	
	}
	
	
	
	if(j==1)	//�P�_�Y�ȤH�I�F����, ��B�q�h�� 
	{
		if(k>=1 && k<=3)
		switch(k){
		case 1:
			printf(" ���`x1\n");
			break;
		case 2:
			printf(" �L�Bx1\n");
			break;
		case 3:
			printf(" �h�Bx1\n");
			break;
		}
		else
		{
		printf("��J���~!�Э���");
		return 0;	
		}
	}

	if(j==2)	//�P�_�Y�ȤH�I�F����, ���Q�q�h�� 
	{
		if(h>=1 && h<=2)
		switch(h){
		case 1:
			printf(" ���`�Qx1\n");
			break;
		case 2:
			printf(" �h�Qx1\n");
			break;
		}
		else
		{
		printf("��J���~!�Э���");
		return 0;	
		}
	}
	
	switch(discount){	//�P�_�O�_���馩�X, �Y�ҥΧ馩�X, �B���O�L��, �h�L�X���Ӫ��B�N���K�� 
		case 'e': case 'E':
			{
			if(main[i-1]+sub[j-1]>=100)	//�P�_���馩�X���p�U�����O���B 
				{
				printf("�`���B��: %.0f\n", (float)(main[i-1]+sub[j-1])*0.8);
				break;
				}
			else
				{
				printf("�`���B��: %d\n", main[i-1]+sub[j-1]);
				break;	
				}
			}
			
		case 'n': case 'N':
			printf("�`���B��: %d\n", main[i-1]+sub[j-1]);
			break;
		
		default:{
			printf("�馩�X��J���~! �Э���");
			return 0;
		}
	}

	printf("�O�_���T?\n");	//�n�D�ȤH�T�{���ӬO�_���T 
	scanf(" %c", &ans);
	
	switch(ans){
		case 'y': case 'Y':
			printf("�T�{"); 
			break;
		case 'n': case 'N':
			printf("����");
			break;
	}
	
	return 0;
}
