//B101020021 �}�l�s 
//�}�o���� Dev-C++ 5.11 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
	float a, b, c, d;	// ��{������ 
	int x, y, z, i, j, xl=0, yl=0, k, end, numbers, points;	// x, y����{����������, i, j������printf�һݭnloop����, xl, yl�t�d���wxy�b, k, end�t�d���w���� ;
	
	char array[61][61];	// �ŧi�@�Ӥj�p61x61���G���}�C 
	printf("�п�Ja:");
	scanf("%f", &a);
	printf("�п�Jb:");
	scanf("%f", &b);
	printf("�п�Jc:");
	scanf("%f", &c);
	printf("�п�Jd:");
	scanf("%f", &d);
	
	printf("ø�s y=%fx^3 + %fx^2 + %fx + %f", a, b, c, d);
	
	memset(array, ' ', sizeof(array));	// �b�̶}�l�Narray�����Ҧ�����initialized���ť��� 

	//Q. A
	
	printf("\nQ. A\n");	
	for(x=-30; x<=30; x++)	// x�b-30~30���d�� 
	{
		y = a*(x*x*x) + b*(x*x)+ c*x + d;
		y = (int)y;	 // y�L����˥h�p���I 
		
		if(y>=-30 && y<0)	// y���b -30~0
		{
		array[abs(-30-y)][x+30]='-'; 
		}
		if(y>0 && y<=30)	// y���b 1~30 
		{
		array[30+y][x+30]='-';
		}
		
		if(y>z)	// �p�Gy>�W�@�I 
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
		
		if(y<z)	// �p�Gy<�W�@�I 
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
		
		z=y;	// �b�C��loop�����x�s�W��y�� 
	}
	
	//���q�|�b���򥴦L�X�ϫe���_����(�קKx, y �P�y�гQ�л\) 
	while(xl<61)	// �إ�x�b 
	{
		array[30][xl]='_';	//�brow 30���B, �N�Ҧ��ӦC�����]��'_' 
		xl++;
	}
	
	while(yl<61)	// �إ�y�b 
	{
		array[yl][30]='|';	//�bcolumn 30���B, �N�Ҧ����椸���]��'|' 
		yl++;
	}
	
	for(numbers=0; numbers<=60; numbers+=5)	//�إ�x, y�y�� 
	{
		points=numbers-30;
		
		if(numbers==25)	//�b-5��+10, ���L0 
		numbers+=10;
		
		sprintf(&array[29][numbers], "%d", points);	//x�y�� 
		sprintf(&array[numbers][31], "%d", points);	//y�y�� 
	}
	
	array[30][30]='0';	//�]array[30][30]��0 
	
	for(i=60; i>=0; i--)	// �L�X�Ӱ}�C 
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
	printf("\n�п�Jx1��:");
	scanf("%d", &x1);
	printf("�п�Jx2��:");
	scanf("%d", &x2);
	
	if(x2>x1)	//�p�Gx2�j��x1 
	{
		if(x2<0)	//��x2<0 
		{
			r=(31/(30+x2));	//�ײv 
			
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
		
		else if(x2==0)	//��x2=0
		{
			q=1;	//�ײv 
			
            for(t=30; t<=60; t+=q)
            {
				p++;
               	array[t][p]='+';
            }	
		}
	
		else if(x2>0)	//��x2<0
		{
			r=(310/(31+x2));	//�ײv*10: (�d��:5~9) 
        	q=(int)(r);
        	
            for(t=30; t<=60||p<=60; t+=q)
           	{
				p+=10;
                array[t][p]='+';
            }
		}
	}
	
	if(x1>x2)	//�p�Gx1>x2 
	{
		if(x1<0)	//��x1<0
		{
			r=(31/(30+x1));	//�ײv 
			
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
		
		else if(x1==0)	//��x1=0
		{
			q=1;	//�ײv 
			
            for(t=30; t<=60; t+=q)
            {
				p++;
               	array[t][p]='+';
            }	
		}
	
		else if(x1>0)	//��x1>0
		{
			r=(310/(31+x1));	//�ײv*10: (�d��:5~9) 
        	q=(int)(r);
        	
            for(t=30; t<=60||p<=60; t+=q)
           	{
				p+=10;
                array[t][p]='+';
            }
		}
	} 
	
	int targ1, targ2;
	
	for(targ1=0; targ1<=60; targ1++)	//�bx��x1�B�аO 
	{
		array[targ1][30+x1]='|';
	}
	
	for(targ2=0; targ2<=60; targ2++)	//�bx��x2�B�аO
	{
		array[targ2][30+x2]='|';
	}
	
	//�L�X�e���� 
	while(xl<61)	// �إ�x�b 
	{
		array[30][xl]='_';	//�brow 30���B, �N�Ҧ��ӦC�����]��'_' 
		xl++;
	}
	
	while(yl<61)	// �إ�y�b 
	{
		array[yl][30]='|';	//�bcolumn 30���B, �N�Ҧ����椸���]��'|' 
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
	
	for(i=60; i>=0; i--)	// �L�X�Ӱ}�C 
	{
		for(j=0; j<=60; j++)
		{
		printf("%c", array[i][j]);
		}
		printf("\n");
	}
	
	// Q. C
	// �ϥ�double�O�G��᪺�ƭȧ󱵪�, ��ǽT 
	
	printf("\nQ. C\n");	 
	int round, absy;
	double x1r=(double)x1, x2r=(double)x2, y1r, y2r, close, r2, q2, intercept;
	
	if(x1>x2)	// ��x2�G��x1, x1>x2�����p 
	for(round=1; round<=10; round++)	// ���ܦh10�����G��	
	{
		x2r=x2r+fabs((x2r-x1r)/2);	// �ϥ�fab�������� 
		close=fabs(x2r-x1r);
		
		if(close<0.1)	//��close=fabs(x2r-x1r)<0.1�� 
		break;	//�ߧYbreak loop 
	}
	
	else if(x2>x1)	// ��x2�G��x1, x2>x1�����p 
	for(round=1; round<=10; round++)	// ���ܦh10�����G��
	{
		x2r=x2r-fabs((x2r-x1r)/2);	// �ϥ�fab�������� 
		close=fabs(x2r-x1r);
		
		if(close<0.1)	//��close=fabs(x2r-x1r)<0.1�� 
		break;	//�ߧYbreak loop 
	}
	
	y1r=a*x1*x1*x1+b*x1*x1+c*x1+d;
	y2r=a*x2r*x2r*x2r+b*x2r*x2r+c*x2r+d;
	r2=(y2r-y1r)/(x2r-x1r);	// r2�������ײv 
	intercept=(0-r2)*x1r+y1r;	//intercept���I�Z�� 
	q2=(int)r2;	//q2�O��Ƥƫ᪺r2, ��K����إߤ��u�ϥ� 
	
	printf("\nx1=%lf\n", x1r);
	printf("x2=%lf\n", x2r);
	printf("y1=%lf\n", y1r);
	printf("y2=%lf\n", y2r);
	printf("(x2-x1)=%lf\n", x2r-x1r);
	printf("(y2-y1)=%lf\n", y2r-y1r);
	printf("�ײv=%lf\n", r2);
	printf("�I�Z=%lf\n", intercept);
	absy=abs(y1r);	//����Ȥƪ�y1r����, �]�O���F��K���򰵤��u�� 
	
	int cuty, cutx;
	cutx=x1+31;	//x1+30�����I����, x1+31�����I�᩵���X���u���Ĥ@��x�� 
	
	if(y1r>=0)
	{
		array[30+absy][x1+30]='@';
		cuty=31+absy;	//absy=absolute y1r, y1r�Y�O���I��y�� 
	}
	
	else if(y1r<0)
	{
		array[30-absy][x1+30]='@';	
		cuty=31-absy;
	}
	
	
	for(i=60; i>=0; i--)	// �L�X�Ӱ}�C 
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
    	cuty+=q2;	//��y+q2��� 
		cutx++;	//x�V�e1��� 
        array[cuty][cutx]='#';	//�Q�θӱײv�إߤ��u 
    }
    
    for(i=60; i>=0; i--)	// �L�X�Ӱ}�C 
	{
		for(j=0; j<=60; j++)
		{
		printf("%c", array[i][j]);
		}
		printf("\n");
	}
	
	return 0;
 } 
