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
			fscanf(file, "%d", &binaryimage[loady][loadx]);	// fscanf讀取32x32個整數(0 or 1) 
			printf("%d ", binaryimage[loady][loadx]);	// 將讀取到的數字呈現在DOS上 
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
				binaryimage[y][x]=1;	//若forward pass四點內有一點為0, 最小值必為0, P(x,y)更新為0+1=1 
				
				else if(binaryimage[y][x-1]>=1 && binaryimage[y-1][x]>=1 && binaryimage[y-1][x-1]>=1 && binaryimage[y-1][x+1]>=1)
				{	//四點內不出現0之情形 
					if(binaryimage[y][x-1]==1 || binaryimage[y-1][x]==1 || binaryimage[y-1][x-1]==1 || binaryimage[y-1][x+1]==1)
					binaryimage[y][x]=2;	//若四點內有一點為1 (最小值) P(x,y)更新為 1+1=2 
					
					else if(binaryimage[y][x-1]==2 || binaryimage[y-1][x]==2 || binaryimage[y-1][x-1]==2 || binaryimage[y-1][x+1]==2)
					binaryimage[y][x]=3;	//若四點內最小值為2 P(x,y)更新為 2+1=3 
					
					else if(binaryimage[y][x-1]==3 || binaryimage[y-1][x]==3 || binaryimage[y-1][x-1]==3 || binaryimage[y-1][x+1]==3)
					binaryimage[y][x]=4;	//若四點內最小值為3 P(x,y)更新為 3+1=4
				}
				printf("%d ", binaryimage[y][x]);
            }
            else
            {
            binaryimage[y][x]==0;	//0則直接印出 
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
            if(binaryimage[y][x]!=0)	//該點不為0的話: 
            {
				if(binaryimage[y][x]==1)
				binaryimage[y][x]=1;	//為1 說明該點做Backward pass也只能為1 (其他點能找到的最小值為0) 
				
				else if(binaryimage[y][x]>1)
				{
					min=binaryimage[y][x];	//設最小值為P(x,y)本身 
					
					if(binaryimage[y][x+1]<min)	//逐一比較自己與自己以外四點的最小值 
					min=binaryimage[y][x+1];
					
					if(binaryimage[y+1][x-1]<min)
					min=binaryimage[y+1][x-1];
					
					if(binaryimage[y+1][x]<min)
					min=binaryimage[y+1][x];
					
					if(binaryimage[y+1][x+1]<min)
					min=binaryimage[y+1][x+1];
					
					binaryimage[y][x]=min+1;	//更新P(x,y)為Backward pass後最小值 
				}
				
				printf("%d ", binaryimage[y][x]);
            }
            else
            {
            binaryimage[y][x]==0;	//0則直接印出
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
			fprintf(file, "%d ", binaryimage[y][x]);	//利用fprintf功能, 寫入Result.txt 
		}
		fprintf(file, "\n");
	}
	fclose(file);
}

// Q.5
int locate(xcord, ycord){
	
	char ans;
	
	while(1)	//重複執行 
	{
		printf("\n\n請問是否要查詢pixel值?(Y/N)\n");
		scanf("%c", &ans);
		
		if(ans=='Y')
		{
				printf("請輸入要查詢的座標:\nx = ");
				scanf("%d", &xcord);
				printf("y = ");
				scanf("%d", &ycord);
				
				while(xcord<0 || ycord<0 || xcord>31 || ycord>31)	//當x or y超出範圍時, 要求重新輸入 
				{
					printf("請輸入正確座標:\n x = ");
					scanf("%d", &xcord);
					printf("y = ");
					scanf("%d", &ycord);
				}
				printf("pixel value : %d", binaryimage[ycord][xcord]);
		}
		else if(ans=='N')	//當輸入N, 斷開while loop 
		{
			break;
		}
		fflush(stdin);
	}

}
