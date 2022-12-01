# C Language Design & Experiment (I)

## Week 13

## Linked List

There's a pointer __Last__, we do __insert__ and __delete__(Find the node with the value) to the linked list.



## Insert

```c
struct Node{
    int data;
    struct Node *next;
}

insert(int value){
    struct node *new, *current=last;
    new=malloc(sizeof(struct Node));
    new->data = value;
    new->next = NULL;
    // 1. The biggest one, 2. The smallest one, 3. Empty list, 4. Only one node in the list
    
    // 2
    if(new->data<last->data){
        new->next=last;
        last=new;
    }
    
    // 3
    if(last=NULL){
        last = new;
        return last;
    }
    
    // 4
    if(last->next=NULL){
        if(new->data>last->data){
            last->next=new;
        }
        else{
            new->next=last;
            last=new;
        }
    }
    
    while(!(current->data<new->data && current->next->data>new->data)){
        current = current->next;	// The last one is smaller than the new one, the next one is bigger than it.
        if(current->next=NULL){
            break;	// 1
        }
    }
    
    new->next=current->next;	// Link 1
    current->next=new;	// Link 2
}
```



## Delete

```c
struct * search(last, key){
    struct Node * current = last;
    while(current !=NULL && current->data !=key){	// Can't reverse the while condition, if current is NULL already, then current->data will occur error
        current = current->next;	// Keep searching
    }
    return current;
}

delete(last, key){
    if(last=NULL){
        return;	//Empty
    }
    
    if(last==found){
        last=found->next;
        free(found);
    }
    
    struct node * found = search(last, key);	// Find a current
    if(found=NULL){
        return;
    }
    
    struct node * current = last;
    while(current->next!=found){
        current = current->next;
    }
    
    current->next=found->next;
    free(found);
}
```



## Double Linked List

```c
struct node{
    struct node *back;
    int data;
    struct node *front;
}

insert(head, tail, value){
    struct node *new, *current=tail;
    new=malloc(sizeof(struct node));
    new->data = value;
    new->back = NULL;
    new->front = NULL;
    while(!(current->data<new->data && current->front->data>new->data)){
        current = current->front;
    }
    
    current->front->back=new; // Link 1
    new->front=current->front;	// Link 2
    current->front=new;	// Link 3
    new->back=current; // Link 4
    
```





