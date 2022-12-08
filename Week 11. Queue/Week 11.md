# C Language Design & Experiment (I)

## Week 11

## Queue

Entering from the rear, leaving from the front.

```c
struct node{
    int data;
    struct node *next
}
```



## EnQueue

```c
EnQueue(*front, *rear, value)
{
    struct node *new;
    new = malloc(sizeof(struct node));
    new -> data = value;
    new -> next = NULL;
    
    if(front==NULL){
        front= new;	// Front is also the rear.
    }
    
    new -> next = rear;	// Point to the last one.
    rear = new;	// The address of the rear now updated to the one which just entered
    
    
}
```



## DeQueue

```c
int DeQueue(*front, *rear){
    
    if(front==NULL){
        return 0;
    }
    
    else if(front==rear){
        struct node *temp = front;
    	int value = temp -> data;
    	struct node *current = rear;
        rear=front;
    }
    
    else{
 	   struct node *temp = front;
    	int value = temp -> data;
    	struct node *current = rear;
    
    	while(current->next != front){
        	current=current->next;
    	}
        
        front=current;
  	    front->next=NULL;
    }
    
    free(temp);	// temp still exist, but the value inside(which should be an address will be freed)
    return value;
}
```



But Dequeue is too slow in this structure, so next time, we're going to see double link list: a structure with 3 rooms–front, value, and rear. And it's going to cost 12 bytes when one trying to store an integer. (one int pointer is also 4 bytes).



stack!!!