#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX]; //為什麼要做全域變數宣告?而不是內部宣告
char infix[MAX], postfix[MAX];
int top = -1; //-1表示未指向任何東西

void push(char);
char pop();
int isEmpty(); //檢查是否為空陣列 
void inToPost(); //轉換成後序表示 
int space(char); //檢查輸入是否為空格 
void print();
int precedence(char); 

int main()
{
	printf("Enter the infix expression: ");
	gets(infix);
	
	inToPost();
	print();
	return 0;
}

void inToPost()
{
	int i, j = 0;
	char next;
	char symbol;
	for(i=0; i<strlen(infix); i++)
	{
		symbol = infix[i]; //將原陣列的值給變數symbol
		//判斷讀取的值非空白 
		if(!space(symbol)) 
		{
			switch(symbol)
			{
				//讀取到括號 
				case '(':
					push(symbol);
					break;
				case ')':
					while((next = pop()) != '(')
						postfix[j++] = next;
					break;
				//讀取到運算子	
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
					while(!isEmpty() && precedence(stack[top] >= stack[symbol]))
					//當stack內部非空且最上面的運算子優先度>=目前的運算子 
							postfix[j++] = pop(); //把最上面的運算子取出並且存入後序陣列
					push(symbol);
					break; 
				//讀取值為數字 
				default:
					postfix[j++] = symbol; //讀取到數字就直接存入後序陣列 
				
			}
		}
	}
	while(!isEmpty())
		postfix[j++] = pop(); //做完後檢查stack內若還有運算子則將他們存回後序陣列
	postfix[j] = '\0'; //最後在陣列尾端加入\0作為結束符號 
}

int space(char c)
{
	//檢查輸入是否為空格(space or tab)
	if(c == ' ' || c == '\t')
		return 1;
	else
		return 0; 
}

int precedence(char symbol)//檢查優先度
{
	switch(symbol)
	{
		case '^':
			return 3; 
		case '*':
			return 2;
		case '/':
			return 2; 
		case '+':
			return 1;
		case '-':
			return 1;
		default:
			return 0; 
	}
}

void print()
{
	int i = 0;
	printf("The equivalent postfix expression is: ");
	while(postfix[i])
		printf("%c", postfix[i++]); //每次做完i+=1 
	printf("\n");
}

void push(char c)
{
	if(top == MAX - 1)
	{
		printf("Stack Overflow\n");
		return;
	}
	top++;
	stack[top] = c;
	return c;
}

char pop()
{
	char c;
	if(top == -1)
	{
		printf("Stack underflow\n");
		exit(1); //這啥? 
	}
	c = stack[top];
	top -= 1;
	return c;
}
int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}

