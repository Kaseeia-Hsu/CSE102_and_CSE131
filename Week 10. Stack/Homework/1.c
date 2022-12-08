#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node_t {
  char val;
  struct Node_t *next;
} Node;	//特定data type Node(a specific structure) 

Node *stk = NULL;	//stk(用存Node地址的pointer)初始化為0 

char *polishreverse(const char *);	//polishreverse function為一指針 指向char型別的資料 

int main(){
    char expression[100];	//最多可輸入100個字元作為string 
    scanf("%s", expression);
    char *res= polishreverse(expression);	//res同為一address 代表polishreverse內存的地址 
    printf("\n\n%s\n", res);
} 

int precedence(const char op){	//for operators
    switch(op){
        case '*': case '/':	//優先度最高 
            return 2;
        case '+': case '-':	//次高 
            return 1;
        case '(': case ')':	//再者 
            return 0;
    }
    return -1;	//最後(數字/代數) 非運算子之字元 
}

bool empty(){
    return stk == NULL;
}

char top(){
    return stk->val;
}

void pop(){
    Node *tmp = stk;	// top
    stk = stk->next;	// top become the next one
    free(tmp);
}

void push(const char c){
    Node *newNode = calloc(sizeof(Node), 1);	//newNode可以存一個Node的住址 
    newNode->val = c;	//newNode->val 存push進的c 
    newNode->next = stk;	//newNode->next = stk 第一輪為NULL 
    stk = newNode; 	//更新stk = newnode 
}

char *polishreverse(const char *expression){	//引數為expression的地址 
    char *res= calloc(strlen(expression)+1, sizeof(char));	//初始化res的記憶體大小 
    int t=0;
    int i;
    
    for(i=0; expression[i]; ++i){
        const char c= expression[i];
        int p = precedence(c);	//判斷字元優先度 
        
        if(p==-1)
        {
            res[t++]=c;
        }
        else if(c==')')	//說明括號完成 
        {
            while(!empty() && top() != '(')	//當stack非空 且頂端的value不為上括號時 
            {
                res[t++]=top();	//將top放入res[t++]中 
                pop();	//不斷pop, 直至遇見上括號 
            }
            pop();	//上括號為top時, 不放入res[t++]中, 直接pop掉, 因逆波蘭表示式中不帶括號 
        }
        else	//遇見運算子時(不含下括號) 
        {
            while(!empty() && precedence(top())>=p)	//若stack非空 且內部存的運算子優先度大於本輪計算子時 
            {
                res[t++]=top();	//將top的value放入res[t++]中 
                pop();	
            }
            push(c);	//將本輪運算子push進stack內 
        }

    }
    
    while(!empty())	//當stack非空時 
    res[t++]= top(), pop();	//把剩下在stack內的value放入res中 
    
    return res;
}
