
//�}�o����: Visual Studio

#define _CRT_SECURE_NO_WARNINGS	//����N�X�Ω����Visual Studio��"scanf"�R�O�o�X��ĵ�i
#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	//�ŧi��,���P���n����ƫ��A��float
	//Declaring the data type of these variables is float.
	float base, height, area;	

	//�n�D�ϥΪ̿�J�T���Ϊ����M��
	//Requesting users to enter the length of base and height.
	printf("�п�J�T���Ϊ��������:");
	scanf("%f", &base);
	printf("�п�J�T���Ϊ�����:");
	scanf("%f", &height);
	
	//�w�q�T���Ϊ����n
	//Defining the area of triangle.
	area = base*height/2;

	//�L�X�T���Ϊ����n
	//Printing out the area of triangle
	printf("�T���Ϊ����n��:%f", area);

	return 0;
}
