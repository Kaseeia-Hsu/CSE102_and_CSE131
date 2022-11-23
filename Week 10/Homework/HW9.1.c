#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX]; //������n�������ܼƫŧi?�Ӥ��O�����ŧi
char infix[MAX], postfix[MAX];
int top = -1; //-1��ܥ����V����F��

void push(char);
char pop();
int isEmpty(); //�ˬd�O�_���Ű}�C 
void inToPost(); //�ഫ����Ǫ�� 
int space(char); //�ˬd��J�O�_���Ů� 
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
		symbol = infix[i]; //�N��}�C���ȵ��ܼ�symbol
		//�P�_Ū�����ȫD�ť� 
		if(!space(symbol)) 
		{
			switch(symbol)
			{
				//Ū����A�� 
				case '(':
					push(symbol);
					break;
				case ')':
					while((next = pop()) != '(')
						postfix[j++] = next;
					break;
				//Ū����B��l	
				case '+':
				case '-':
				case '*':
				case '/':
				case '^':
					while(!isEmpty() && precedence(stack[top] >= stack[symbol]))
					//��stack�����D�ťB�̤W�����B��l�u����>=�ثe���B��l 
							postfix[j++] = pop(); //��̤W�����B��l���X�åB�s�J��ǰ}�C
					push(symbol);
					break; 
				//Ū���Ȭ��Ʀr 
				default:
					postfix[j++] = symbol; //Ū����Ʀr�N�����s�J��ǰ}�C 
				
			}
		}
	}
	while(!isEmpty())
		postfix[j++] = pop(); //�������ˬdstack���Y�٦��B��l�h�N�L�̦s�^��ǰ}�C
	postfix[j] = '\0'; //�̫�b�}�C���ݥ[�J\0�@�������Ÿ� 
}

int space(char c)
{
	//�ˬd��J�O�_���Ů�(space or tab)
	if(c == ' ' || c == '\t')
		return 1;
	else
		return 0; 
}

int precedence(char symbol)//�ˬd�u����
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
		printf("%c", postfix[i++]); //�C������i+=1 
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
		exit(1); //�oԣ? 
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

