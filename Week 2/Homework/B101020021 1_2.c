
//�}�o����: Visual Studio
//�@��: B101020021 �}�l�s

#define _CRT_SECURE_NO_WARNINGS //����N�X�Ω����Visual Studio��"scanf"�R�O�o�X��ĵ�i
#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
    //�ŧia, b�P���᪺�ܼƬҬ����ׯB�I��
    //Declaring that a, b and all the variables afterwards are float.
    float a, b, minus, multiply, plus, divide;

    printf("�п�Ja����:");
    scanf("%f", &a);
    printf("�п�Jb����:");
    scanf("%f", &b);

    //�H�U���Ѧ���{���C�@�B�����G
    //The followings are step-by-step solutions of the equation per se.
    minus = a - b;
    multiply = b * (a - b);
    plus = a + b * (a - b);
    divide = plus / b;

    //�L�X��{���C�@�B�J����
    //Printing out the solutions of every steps.
    printf("a-b = %f\n", minus);
    printf("b*(a-b) = %f\n", multiply);
    printf("a+b*(a-b) = %f\n", plus);
    printf("[a+b*(a-b)]/b = %f", divide);

    return 0;
}