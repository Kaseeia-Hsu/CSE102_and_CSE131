#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int data;
	struct node *next;
}NODE;

int main(){
	NODE node1, node2, node3;
	node1.data=1;
	node1.next=&node2;
	node2.data=2;
	node2.next=&node3;
	node3.data=3;
	node3.next=NULL;
	
	NODE *ptr;
	ptr=malloc(sizeof(NODE));
	ptr=&node1;
	
	printf("Finding data in node 3 with node 1:\n");
	while(1){
		if(ptr->next!=NULL){
			ptr=ptr->next;
		}
		else if(ptr->next==NULL){
			int res;
			res=ptr->data;
			printf("Data in node 3 is:%d", res);
			return 0;
		}
	}
	
	return 0;
}
