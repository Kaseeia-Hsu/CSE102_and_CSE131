#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
} NODE;

struct queue{
	NODE *stk1;
	NODE *stk2;
};

void push(struct node ** top, int data){
	NODE *newnode = malloc(sizeof(NODE));
	newnode->data=data;
	newnode->next=*top;
	*top=newnode;
}

int pop(struct node ** top){
	int value;
	NODE *temp;
	temp=*top;
	value=temp->data;
	*top=temp->next;
	free(temp);
	
	return value;
}

void enqueue(struct queue *q, int x){
	int popv;
	
	while(q->stk1!=NULL){
		popv=pop(&q->stk1);
		push(&q->stk2, popv);
	}
	
	if(q->stk1==NULL){
		push(&q->stk1, x);
	}
	
	while(q->stk2!=NULL){
		popv=pop(&q->stk2);
		push(&q->stk1, popv);
	}
}

void dequeue(struct queue *q){
	if(q->stk1==NULL){
		printf("Queue is empty!\n");
		return;
	}
	pop(&q->stk1);
}

void display(struct node *top1){
	
	if(top1==NULL){
		return;
	}
	
	int count=0;
	int valuearr[1000];
	int i;
	
	while(top1!=NULL){
		valuearr[count]=top1->data;
		top1=top1->next;
		count++;
	}
	
	for(i=0; i<count; i++){
		printf("*******");
	}
	printf("*\n");
	
	for(i=0; i<count; i++){
		printf("*      ");
	}
	printf("*\n");
	
	for(i=0; i<count; i++){
	printf("*      ");
	}
	printf("*\n");
	
	for(i=0; i<count; i++){
	printf("* %3d  ", valuearr[i]);
	}
	printf("*\n");
	
	for(i=0; i<count; i++){
		printf("*      ");
	}
	printf("*\n");
	
	for(i=0; i<count; i++){
	printf("*      ");
	}
	printf("*\n");
	
	for(i=0; i<count; i++){
	printf("*******");
	}
	printf("*\n");
}

int main(){
	
	struct queue *ptrq = malloc(sizeof(struct queue));
	
	int ans, val;
	ptrq->stk1=NULL;
	ptrq->stk2=NULL;
	
	while(1){
		printf("Please choose what you want to do: 1. Enqueue 2.Dequeue 3. Exit\n");
		scanf("%d", &ans);
		switch(ans){
			case 1: printf("Please enter a value to enqueue: ");
					scanf(" %d", &val);
					enqueue(ptrq, val);
					display(ptrq->stk1);
					break;
			case 2: dequeue(ptrq);
					display(ptrq->stk1);
					break;
			case 3: return 0;
		}
	}
}
