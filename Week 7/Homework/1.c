//B101020021 徐子群 
//開發環境 Dev-C++ 5.11 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
	float a, b, c, d;	// 方程式之值 
	int x, y, z, i, j, xl=0, yl=0, k, end, numbers, points;	// x, y為方程式內部之值, i, j為結尾printf所需要loop之值, xl, yl負責指定xy軸, k, end負責指定換行 ;
	
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

	//Q. A
	
	printf("\nQ. A\n");	
	for(x=-30; x<=30; x++)	// x在-30~30的範圍內 
	{
		y = a*(x*x*x) + b*(x*x)+ c*x + d;
		y = (int)y;	 // y無條件捨去小數點 
		
		if(y>=-30 && y<0)	// y落在 -30~0
		{
		array[abs(-30-y)][x+30]='-'; 
		}
		if(y>0 && y<=30)	// y落在 1~30 
		{
		array[30+y][x+30]='-';
		}
		
		if(y>z)	// 如果y>上一點 
		{
			if(y>=-30 && y<0)
			{
				array[abs(-30-y)][x+30]='/'; 
			}
			if(y>0 && y<=30)
			{
				array[30+y][x+30]='/';
			}
		}
		
		if(y<z)	// 如果y<上一點 
		{
			if(y>=-30 && y<0)
			{
				array[abs(-30-y)][x+30]='\\'; 
			}
			if(y>0 && y<=30)
			{
				array[30+y][x+30]='\\';
			}
		}
		
		z=y;	// 在每次loop結尾儲存上個y值 
	}
	
	//此段會在後續打印出圖前不斷重複(避免x, y 與座標被覆蓋) 
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
	
	for(numbers=0; numbers<=60; numbers+=5)	//建立x, y座標 
	{
		points=numbers-30;
		
		if(numbers==25)	//在-5時+10, 跳過0 
		numbers+=10;
		
		sprintf(&array[29][numbers], "%d", points);	//x座標 
		sprintf(&array[numbers][31], "%d", points);	//y座標 
	}
	
	array[30][30]='0';	//設array[30][30]為0 
	
	for(i=60; i>=0; i--)	// 印出該陣列 
	{
		for(j=0; j<=60; j++)
		{
		printf("%c", array[i][j]);
		}
		printf("\n");
	}
	
	//Q. B
	
	printf("\nQ. B\n");
	int x1, x2, t, p=0, q, temp;
	float r;
	printf("\n請輸入x1值:");
	scanf("%d", &x1);
	printf("請輸入x2值:");
	scanf("%d", &x2);
	
	if(x2>x1)	//如果x2大於x1 
	{
		if(x2<0)	//當x2<0 
		{
			r=(31/(30+x2));	//斜率 
			
			if(r>=1)
			{
				q=(int)r;
				
            	for(t=30; t<=60; t+=q)
            	{
					p++;
                	array[t][p]='+';
            	}
        	}
 		}
		
		else if(x2==0)	//當x2=0
		{
			q=1;	//斜率 
			
            for(t=30; t<=60; t+=q)
            {
				p++;
               	array[t][p]='+';
            }	
		}
	
		else if(x2>0)	//當x2<0
		{
			r=(310/(31+x2));	//斜率*10: (範圍:5~9) 
        	q=(int)(r);
        	
            for(t=30; t<=60||p<=60; t+=q)
           	{
				p+=10;
                array[t][p]='+';
            }
		}
	}
	
	if(x1>x2)	//如果x1>x2 
	{
		if(x1<0)	//當x1<0
		{
			r=(31/(30+x1));	//斜率 
			
			if(r>=1)
			{
				q=(int)r;
				
            	for(t=30; t<=60; t+=q)
            	{
					p++;
                	array[t][p]='+';
            	}
        	}
 		}
		
		else if(x1==0)	//當x1=0
		{
			q=1;	//斜率 
			
            for(t=30; t<=60; t+=q)
            {
				p++;
               	array[t][p]='+';
            }	
		}
	
		else if(x1>0)	//當x1>0
		{
			r=(310/(31+x1));	//斜率*10: (範圍:5~9) 
        	q=(int)(r);
        	
            for(t=30; t<=60||p<=60; t+=q)
           	{
				p+=10;
                array[t][p]='+';
            }
		}
	} 
	
	int targ1, targ2;
	
	for(targ1=0; targ1<=60; targ1++)	//在x為x1處標記 
	{
		array[targ1][30+x1]='|';
	}
	
	for(targ2=0; targ2<=60; targ2++)	//在x為x2處標記
	{
		array[targ2][30+x2]='|';
	}
	
	//印出前重複 
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
	
	for(numbers=0; numbers<=60; numbers+=5)
	{
		points=numbers-30;
		
		if(numbers==25)
		numbers+=10;
		
		sprintf(&array[29][numbers], "%d", points);
		sprintf(&array[numbers][31], "%d", points);
	}
	
	array[30][30]='0';
	
	for(i=60; i>=0; i--)	// 印出該陣列 
	{
		for(j=0; j<=60; j++)
		{
		printf("%c", array[i][j]);
		}
		printf("\n");
	}
	
	// Q. C
	// 使用double令逼近後的數值更接近, 更準確 
	
	printf("\nQ. C\n");	 
	int round, absy;
	double x1r=(double)x1, x2r=(double)x2, y1r, y2r, close, r2, q2, intercept;
	
	if(x1>x2)	// 做x2逼近x1, x1>x2的情況 
	for(round=1; round<=10; round++)	// 做至多10輪的逼近	
	{
		x2r=x2r+fabs((x2r-x1r)/2);	// 使用fab獲取絕對值 
		close=fabs(x2r-x1r);
		
		if(close<0.1)	//當close=fabs(x2r-x1r)<0.1時 
		break;	//立即break loop 
	}
	
	else if(x2>x1)	// 做x2逼近x1, x2>x1的情況 
	for(round=1; round<=10; round++)	// 做至多10輪的逼近
	{
		x2r=x2r-fabs((x2r-x1r)/2);	// 使用fab獲取絕對值 
		close=fabs(x2r-x1r);
		
		if(close<0.1)	//當close=fabs(x2r-x1r)<0.1時 
		break;	//立即break loop 
	}
	
	y1r=a*x1*x1*x1+b*x1*x1+c*x1+d;
	y2r=a*x2r*x2r*x2r+b*x2r*x2r+c*x2r+d;
	r2=(y2r-y1r)/(x2r-x1r);	// r2為極限斜率 
	intercept=(0-r2)*x1r+y1r;	//intercept為截距值 
	q2=(int)r2;	//q2是整數化後的r2, 方便後續建立切線使用 
	
	printf("\nx1=%lf\n", x1r);
	printf("x2=%lf\n", x2r);
	printf("y1=%lf\n", y1r);
	printf("y2=%lf\n", y2r);
	printf("(x2-x1)=%lf\n", x2r-x1r);
	printf("(y2-y1)=%lf\n", y2r-y1r);
	printf("斜率=%lf\n", r2);
	printf("截距=%lf\n", intercept);
	absy=abs(y1r);	//絕對值化的y1r之值, 也是為了方便後續做切線用 
	
	int cuty, cutx;
	cutx=x1+31;	//x1+30為切點本身, x1+31為切點後延伸出切線的第一位x值 
	
	if(y1r>=0)
	{
		array[30+absy][x1+30]='@';
		cuty=31+absy;	//absy=absolute y1r, y1r即是切點的y值 
	}
	
	else if(y1r<0)
	{
		array[30-absy][x1+30]='@';	
		cuty=31-absy;
	}
	
	
	for(i=60; i>=0; i--)	// 印出該陣列 
	{
		for(j=0; j<=60; j++)
		{
		printf("%c", array[i][j]);
		}
		printf("\n");
	}
	
	//Q. D
	printf("\nQ. D\n");
	
	while(cuty<=60 && cutx<=60)
    {
    	cuty+=q2;	//當y+q2單位 
		cutx++;	//x向前1單位 
        array[cuty][cutx]='#';	//利用該斜率建立切線 
    }
    
    for(i=60; i>=0; i--)	// 印出該陣列 
	{
		for(j=0; j<=60; j++)
		{
		printf("%c", array[i][j]);
		}
		printf("\n");
	}
	
	return 0;
 } 
