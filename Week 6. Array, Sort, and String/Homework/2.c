#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
	float a, b, c, d;	// 方程式之值 
	int x, y, i, j, xl=0, yl=0, k, end;	// x, y為方程式內部之值, i, j為結尾printf所需要loop之值, xl, yl負責指定xy軸, k, end負責指定換行 
	char array[61][61];	// 宣告一個大小61x61的二維陣列 
	printf("請輸入a:");
	scanf("%f", &a);
	printf("請輸入b:");
	scanf("%f", &b);
	printf("請輸入c:");
	scanf("%f", &c);
	printf("請輸入d:");
	scanf("%f", &d);
	
	printf("繪製 y=%fx^3 + %fx^2 + %fx + %f", a, b, c, d);
	
	memset(array, ' ', sizeof(array));	// 在最開始將array內的所有元素initialized為空白鍵 
	
	for(x=-30; x<=30; x++)	// x在-30~30的範圍內 
	{
		y = a*(x*x*x) + b*(x*x)+ c*x + d;
		y = (int)y;	 // y無條件捨去小數點 
		
		if(y>=-30 && y<0)	// y落在 -30~0
		{
		array[abs(-30-y)][x+30]='*'; 
		}
		if(y>0 && y<=30)	// y落在 1~30 
		{
		array[30+y][x+30]='*';
		}
	}
	
	while(xl<61)	// 建立x軸 
	{
		array[30][xl]='_';	//在row 30之處, 將所有該列元素設為'_' 
		xl++;
	}
	
	while(yl<61)	// 建立y軸 
	{
		array[yl][30]='|';	//在column 30之處, 將所有該欄元素設為'|' 
		yl++;
	}
	
	for(k=0; k<61; k++)	// 將column 60(每row最後一位元素)設為換行符 
	{
		array[k][60]='\n';
	}
	
	for(i=0; i<=60; i++)	// 印出該陣列 
	{
		for(j=0; j<=60; j++)
		printf("%c", array[i][j]);
	}

	return 0;
 } 
