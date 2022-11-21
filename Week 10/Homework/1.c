#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node_t {
  char val;
  struct Node_t *next;
} Node;	//�S�wdata type Node(a specific structure) 

Node *stk = NULL;	//stk(�ΦsNode�a�}��pointer)��l�Ƭ�0 

char *polishreverse(const char *);	//polishreverse function���@���w ���Vchar���O����� 

int main(){
    char expression[100];	//�̦h�i��J100�Ӧr���@��string 
    scanf("%s", expression);
    char *res= polishreverse(expression);	//res�P���@address �N��polishreverse���s���a�} 
    printf("\n\n%s\n", res);
} 

int precedence(const char op){	//for operators
    switch(op){
        case '*': case '/':	//�u���׳̰� 
            return 2;
        case '+': case '-':	//���� 
            return 1;
        case '(': case ')':	//�A�� 
            return 0;
    }
    return -1;	//�̫�(�Ʀr/�N��) �D�B��l���r�� 
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
    Node *newNode = calloc(sizeof(Node), 1);	//newNode�i�H�s�@��Node����} 
    newNode->val = c;	//newNode->val �spush�i��c 
    newNode->next = stk;	//newNode->next = stk �Ĥ@����NULL 
    stk = newNode; 	//��sstk = newnode 
}

char *polishreverse(const char *expression){	//�޼Ƭ�expression���a�} 
    char *res= calloc(strlen(expression)+1, sizeof(char));	//��l��res���O����j�p 
    int t=0;
    int i;
    
    for(i=0; expression[i]; ++i){
        const char c= expression[i];
        int p = precedence(c);	//�P�_�r���u���� 
        
        if(p==-1)
        {
            res[t++]=c;
        }
        else if(c==')')	//�����A������ 
        {
            while(!empty() && top() != '(')	//��stack�D�� �B���ݪ�value�����W�A���� 
            {
                res[t++]=top();	//�Ntop��Jres[t++]�� 
                pop();	//���_pop, ���ܹJ���W�A�� 
            }
            pop();	//�W�A����top��, ����Jres[t++]��, ����pop��, �]�f�i����ܦ������a�A�� 
        }
        else	//�J���B��l��(���t�U�A��) 
        {
            while(!empty() && precedence(top())>=p)	//�Ystack�D�� �B�����s���B��l�u���פj�󥻽��p��l�� 
            {
                res[t++]=top();	//�Ntop��value��Jres[t++]�� 
                pop();	
            }
            push(c);	//�N�����B��lpush�istack�� 
        }

    }
    
    while(!empty())	//��stack�D�Ů� 
    res[t++]= top(), pop();	//��ѤU�bstack����value��Jres�� 
    
    return res;
}
