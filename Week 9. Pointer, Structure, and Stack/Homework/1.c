#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binaryimage[32][32];
int xcord, ycord;

void loadimage();	// Q1
void forwardpass();	// Q2
void backwardpass();	//Q3
void result();	//Q4
int locate(int, int);	//Q5

int main(){
	
	printf("Binary image:\n\n");
	loadimage();	//Q1

	printf("\n\nForwardpass: \n\n");
	forwardpass();	//Q2
	
	printf("\n\nBackwardpass: \n\n");
	backwardpass();	//Q3
	
	result();	//Q4
	
	locate(xcord, ycord);	//Q5

	return 0;
}

// Q.1
void loadimage(){
	
	int loadx, loady;
	
	FILE *file = fopen("Binaryimage.txt", "r");
	for(loady=0; loady<32; loady++)
	{
		for(loadx=0; loadx<32; loadx++)
		{
			fscanf(file, "%d", &binaryimage[loady][loadx]);	// fscanfŪ��32x32�Ӿ��(0 or 1) 
			printf("%d ", binaryimage[loady][loadx]);	// �NŪ���쪺�Ʀr�e�{�bDOS�W 
		}
		printf("\n");	
	}
	fclose(file);
}

// Q.2
void forwardpass(){

    int x, y;

    for(y=0; y<32; y++)
    {
        for(x=0; x<32; x++)
        {
            if(binaryimage[y][x]==1)
            {
				if(binaryimage[y][x-1]==0 || binaryimage[y-1][x]==0 || binaryimage[y-1][x-1]==0 || binaryimage[y-1][x+1]==0)
				binaryimage[y][x]=1;	//�Yforward pass�|�I�����@�I��0, �̤p�ȥ���0, P(x,y)��s��0+1=1 
				
				else if(binaryimage[y][x-1]>=1 && binaryimage[y-1][x]>=1 && binaryimage[y-1][x-1]>=1 && binaryimage[y-1][x+1]>=1)
				{	//�|�I�����X�{0������ 
					if(binaryimage[y][x-1]==1 || binaryimage[y-1][x]==1 || binaryimage[y-1][x-1]==1 || binaryimage[y-1][x+1]==1)
					binaryimage[y][x]=2;	//�Y�|�I�����@�I��1 (�̤p��) P(x,y)��s�� 1+1=2 
					
					else if(binaryimage[y][x-1]==2 || binaryimage[y-1][x]==2 || binaryimage[y-1][x-1]==2 || binaryimage[y-1][x+1]==2)
					binaryimage[y][x]=3;	//�Y�|�I���̤p�Ȭ�2 P(x,y)��s�� 2+1=3 
					
					else if(binaryimage[y][x-1]==3 || binaryimage[y-1][x]==3 || binaryimage[y-1][x-1]==3 || binaryimage[y-1][x+1]==3)
					binaryimage[y][x]=4;	//�Y�|�I���̤p�Ȭ�3 P(x,y)��s�� 3+1=4
				}
				printf("%d ", binaryimage[y][x]);
            }
            else
            {
            binaryimage[y][x]==0;	//0�h�����L�X 
            printf("%d ", binaryimage[y][x]);
        	}
        }
        printf("\n");
    }
    
}

// Q.3
void backwardpass(){
	
	int x, y, min;

    for(y=0; y<32; y++)
    {
        for(x=0; x<32; x++)
        {
            if(binaryimage[y][x]!=0)	//���I����0����: 
            {
				if(binaryimage[y][x]==1)
				binaryimage[y][x]=1;	//��1 �������I��Backward pass�]�u�ର1 (��L�I���쪺�̤p�Ȭ�0) 
				
				else if(binaryimage[y][x]>1)
				{
					min=binaryimage[y][x];	//�]�̤p�Ȭ�P(x,y)���� 
					
					if(binaryimage[y][x+1]<min)	//�v�@����ۤv�P�ۤv�H�~�|�I���̤p�� 
					min=binaryimage[y][x+1];
					
					if(binaryimage[y+1][x-1]<min)
					min=binaryimage[y+1][x-1];
					
					if(binaryimage[y+1][x]<min)
					min=binaryimage[y+1][x];
					
					if(binaryimage[y+1][x+1]<min)
					min=binaryimage[y+1][x+1];
					
					binaryimage[y][x]=min+1;	//��sP(x,y)��Backward pass��̤p�� 
				}
				
				printf("%d ", binaryimage[y][x]);
            }
            else
            {
            binaryimage[y][x]==0;	//0�h�����L�X
            printf("%d ", binaryimage[y][x]);
        	}
        }
        printf("\n");
    }
}

// Q.4
void result(){
	
	int x, y;
	
	FILE *file = fopen("Result.txt", "w");
	for(y=0; y<32; y++)
	{
		for(x=0; x<32; x++)
		{
			fprintf(file, "%d ", binaryimage[y][x]);	//�Q��fprintf�\��, �g�JResult.txt 
		}
		fprintf(file, "\n");
	}
	fclose(file);
}

// Q.5
int locate(xcord, ycord){
	
	char ans;
	
	while(1)	//���ư��� 
	{
		printf("\n\n�аݬO�_�n�d��pixel��?(Y/N)\n");
		scanf("%c", &ans);
		
		if(ans=='Y')
		{
				printf("�п�J�n�d�ߪ��y��:\nx = ");
				scanf("%d", &xcord);
				printf("y = ");
				scanf("%d", &ycord);
				
				while(xcord<0 || ycord<0 || xcord>31 || ycord>31)	//��x or y�W�X�d���, �n�D���s��J 
				{
					printf("�п�J���T�y��:\n x = ");
					scanf("%d", &xcord);
					printf("y = ");
					scanf("%d", &ycord);
				}
				printf("pixel value : %d", binaryimage[ycord][xcord]);
		}
		else if(ans=='N')	//���JN, �_�}while loop 
		{
			break;
		}
		fflush(stdin);
	}

}
