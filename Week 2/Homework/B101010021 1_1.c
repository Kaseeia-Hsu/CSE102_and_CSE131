
//開發環境: Visual Studio

#define _CRT_SECURE_NO_WARNINGS	//此行代碼用於取消Visual Studio對"scanf"命令發出的警告
#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	//宣告底,高與面積的資料型態為float
	//Declaring the data type of these variables is float.
	float base, height, area;	

	//要求使用者輸入三角形的底和高
	//Requesting users to enter the length of base and height.
	printf("請輸入三角形的底邊長度:");
	scanf("%f", &base);
	printf("請輸入三角形的高度:");
	scanf("%f", &height);
	
	//定義三角形的面積
	//Defining the area of triangle.
	area = base*height/2;

	//印出三角形的面積
	//Printing out the area of triangle
	printf("三角形的面積為:%f", area);

	return 0;
}
