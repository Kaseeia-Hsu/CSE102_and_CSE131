#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
	float a, b, c, d;	// ��{������ 
	int x, y, i, j, xl=0, yl=0, k, end;	// x, y����{����������, i, j������printf�һݭnloop����, xl, yl�t�d���wxy�b, k, end�t�d���w���� 
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
	
	for(x=-30; x<=30; x++)	// x�b-30~30���d�� 
	{
		y = a*(x*x*x) + b*(x*x)+ c*x + d;
		y = (int)y;	 // y�L����˥h�p���I 
		
		if(y>=-30 && y<0)	// y���b -30~0
		{
		array[abs(-30-y)][x+30]='*'; 
		}
		if(y>0 && y<=30)	// y���b 1~30 
		{
		array[30+y][x+30]='*';
		}
	}
	
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
	
	for(k=0; k<61; k++)	// �Ncolumn 60(�Crow�̫�@�줸��)�]������� 
	{
		array[k][60]='\n';
	}
	
	for(i=0; i<=60; i++)	// �L�X�Ӱ}�C 
	{
		for(j=0; j<=60; j++)
		printf("%c", array[i][j]);
	}

	return 0;
 } 
