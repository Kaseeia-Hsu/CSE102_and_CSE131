# C Language Design & Experiment (I)

## Week 10

## Introduction of Stack

Why we need stack? Since "insert" and "delete" is really inefficient in array, that is to say–doing copying takes too much time. And that's why we need to learn more about stack and link. Talking about stack, every point of stack is a node like this:

## Push

```c
struct node
{
    int data;	// The value of a plate
    struct node *ptr;	// The address(number) of a plate
}

// The first plate is called "top", also where the address is

push(struct node *top, int value);	// Push
{	// Memory allocation
    struct node *new;	// New will save an address of a struct--node.
    new = malloc(sizeof(struct node));	// How many bytes that struct node needs
    new->data=value;	// line.3
    new->ptr=NULL;	// line.4

	// Top will always be the top value
	// When there's a new plate, ptr=NULL points to the value below it
	// First link: Address points to the value below
	new->ptr=top;	//	Top saves the upmost value's address, once we stack another plate above the original one, the 	new one become the new top, and the ptr points to last top
    
	top=new;	// Save the address of new to top
    
    // What if there's no plate?(top points to no one)
    The result will still be right.
```

## Pop

 ```c
 int pop(struct node *top)
 {
     if(top==NULL)	//Error
         
     else
     {
     struct node *temp;
     temp=top;	// Points to the one that's going to be pop(address)
     int data=temp->value;	// Points to the one that's going to be pop(value)
     top=top->ptr;
     
     free(temp);	// Retun the memory back to computer
     return data;
     }
 }
 ```

## Traversal

```c
int Traversal(struct node *ptr)
{
    struct node *current=top;
    int count=0;
    
    while(current!=0);
    {
        count++;
        current=current->ptr;
    }
    return count;
}
```





