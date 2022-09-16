
//開發環境: Visual Studio
//作者: B101020021 徐子群

#define _CRT_SECURE_NO_WARNINGS //此行代碼用於取消Visual Studio對"scanf"命令發出的警告
#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
    //宣告a, b與之後的變數皆為單精度浮點數
    //Declaring that a, b and all the variables afterwards are float.
    float a, b, minus, multiply, plus, divide;

    printf("請輸入a的值:");
    scanf("%f", &a);
    printf("請輸入b的值:");
    scanf("%f", &b);

    //以下為解此方程式每一步的結果
    //The followings are step-by-step solutions of the equation per se.
    minus = a - b;
    multiply = b * (a - b);
    plus = a + b * (a - b);
    divide = plus / b;

    //印出方程式每一步驟的解
    //Printing out the solutions of every steps.
    printf("a-b = %f\n", minus);
    printf("b*(a-b) = %f\n", multiply);
    printf("a+b*(a-b) = %f\n", plus);
    printf("[a+b*(a-b)]/b = %f", divide);

    return 0;
}