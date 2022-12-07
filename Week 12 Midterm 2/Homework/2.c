#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

typedef struct queue{
	NODE *head;
	NODE *tail;
}QUEUE;

typedef struct DoubleQueue{
	QUEUE *q1;
	QUEUE *q2;
}DQUEUE;

void enqueue(QUEUE **q, int data){
	
    NODE *new;
    new = malloc(sizeof(NODE));
    new->data=data;
    new->next=NULL;
    
    if(q->tail !=NULL){
		q->tail->next=new;
    }
    
    q->tail=new;
    
    if(q->head==NULL){
    	q->head=new;
	}
}

int dequeue(QUEUE **q){
	
	NODE *temp = q->head;
	int result = temp->data;
	q->head = q->head->next;
	
	return result;
}

void push(DQUEUE *ptr, int x){
	
	int temp;
	
	while(ptr->q1!=NULL){
		temp=dequeue(&ptr->q1);
		enqueue(&ptr->q2, temp);
	}
	
	if(ptr->q1==NULL){
		enqueue(&ptr->q1, x);
	}
	
	while(ptr->q2!=NULL){
		temp=dequeue(&ptr->q2);
		enqueue(&ptr->q1, temp);
	}
}

void pop(DQUEUE *ptr){
	
	if(ptr->q1==NULL){
		printf("Queue is empty!\n");
		return;
	}
	dequeue(&ptr->q1);
}

void display(struct node **top1){
	
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
	
	DQUEUE *ptr = malloc(sizeof(DQUEUE));
	
	int ans, val;
	ptr->q1=NULL;
	ptr->q2=NULL;
	
	while(1){
		printf("Please choose what you want to do: 1. Push 2. Pop 3. Exit\n");
		scanf("%d", &ans);
		
		switch(ans){
			case 1: printf("Please enter a value to push: ");
					scanf(" %d", &val);
					push(ptr, val);
					display(ptr->q1);
					break;
					
			case 2: dequeue(ptr);
					display(ptr->q1);
					break;
					
			case 3: return 0;
		}
	}
}
