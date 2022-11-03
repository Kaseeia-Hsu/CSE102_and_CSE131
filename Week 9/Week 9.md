# C Language Design & Experiment (I)

## Week 9

## Function call

```c
#include <stdio.h>

void swap(int, int);	// Forward declaration
int main()
{
    int a=3, b=5;
    printf("Before swap:");
    printf("%d %d\n", a, b);
    printf("After swap:");
    swap(a, b);
    return 0;
}
```



```c
#include <stdio.h>

int square(int num)
{
    return num*num;
}
int main()
{
    printf("%d", square(5));
    return 0;
}
```



```c
int main()
{
    int x = 10;
    ...
    printf("%d\n", increment(&x));	// 2. 把x的地址送給n(n指標到&x)
    printf("%d\n", x); 
    return 0; 
} 
	
int increment(int *n)	// 1. The size of increment is one pointer(在increment內存入n(but not *n), *宣告n是一個專門傳地址的變數)
{ 
	*n = *n + 1;	// *n=10
	return *n; 
}

// n接收到一個地址&a, *n代表一個指標指向一個int值, 來自n接收的地址

```



## Call by Value

```c
#include <stdio.h>

int count(int num1 , int num2)
{
    return num1 + num2;
} 
int main()
{	
    int main_num1=5 , main_num2=10;
	int result=count(main_num1,main_num2);
	printf("%d" , result);
    return 0;
}
```



```c
#include <stdio.h>

int change(int *num1 , int *num2)	// int *num1 means I'll get a integer after point an address.
{
    *num1 = 50;	// The value of address(pointer) become 50.
	*num2 = 100;	// The value of address(pointer) become 50.
} 

int main()
{
    int main_num1=5 , main_num2=10;
	change(&main_num1 , &main_num2);	// Send the address into pointer(the pointer point an address.)
	printf("main_num1：%d\n",main_num1);
	printf("main_num2：%d\n",main_num2);
    return 0;
}
```



```c
#include <stdio.h>
#include <stdlib.h>

void change(int arr[])	//array itself is an address, so we need no pointer here
{
    arr[0] = 50;
	arr[1] = 100;
} 

int main()
{
    int main_arr[2];
	int main_arr[0] = 5;
	int main_arr[1] = 10;
	change(main_arr);
	printf("main_arr[0]:%d\n",main_arr[0]);
	printf("main_arr[1]:%d",main_arr[1]);
}
```



```c
void cubeByReference(int *);

int main()
{
    int number=5;   
	printf("The original number is %d\n",number);
	cubeByReference(&number);
	printf("The new number is %d",number);    
	return 0;
}

void cubeByReference(int *nPtr)
{
	*nPtr=*nPtr * *nPtr * *nPtr;
}
```



## Const

The value of constant can't be changed(will not appear before "=").



```c
#include <stdio.h>

int add(const int* num1,const int* num2)
{
	int result = *num1 + *num2;
	return result;
} 

int main()
{
	int num1=5 , num2=10;
	int result = add(&num1, &num2);
	printf("result = %d \n" ,result);
}

```





## Variadic Function



## Pointers

### Recursion

Successione di Fibonacci:

$F_n=F_{n-1}+F_{n-2}$

$F_{n-1}=F_{n-2}+F_{n-3}$…

![image-20221103100116371](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\image-20221103100116371.png)

This return will keep calling function fib() until n<=1(1 or 0), and this is called recursion.



Tower of Hanoi:

For N plates, we divide it into 2 parts–1 and N-1 plates, and we want to move the bottom part into the right place, then move the upper part onto it. Now, we divide the upper part(N-1) into 2 parts again to know how many steps it takes to stack. And so on, we will keep doing this division until there's only 1 element left in the upper part.



### Intro to Pointers

```c
#include <stdio.h>

int main(void)
{
    int n=10;
    
    printf("%d", n);
    printf("%p", n);	// Print out a pointer
    
    return 0;
}
```



```c
int *x;	// x is a pointer, while *x is an integer
```



```c
int main()
{
    int n=10;
    int *p=&n;
    
    printf("n=%d",n);
    printf("*p=%d", *p);	// These 2 lines' output are both 10 since *p=n
    
    *p=20;
    printf("n=%d",n);
    printf("*p=%d", *p);	// These 2 lines' output are both 20
    
    return 0;
}
```



```c
//各類型態的指標加減

#include <stdio.h>

int main(void) {
    int *p = 0;	//int型態的指標

    printf("p 位置：0X%p\n", p);
    printf("p + 1：0X%p\n", p + 1);
    printf("p + 2：0X%p\n", p + 2);

    return 0;
}

------------------------------------------
#include <stdio.h>

int main(void) {
    double *p = 0;	//double型態的指標

    printf("p 位置：0X%p\n", p);
    printf("p + 1：0X%p\n", p + 1);
    printf("p + 2：0X%p\n", p + 2);

    return 0;
}
```



```c 
FILE *fp;	// Means that fp is a pointer, and *fp is a file
```



## Structure

```c
struct point	// point is like a house, with 2 rooms
{
    int x;
    int y;
};

struct triangle
{
    struct point ptA;
    struct point ptB;
    struct point ptC;
};

struct chain_element	// The first room is an integer, second room is a pointer
{
    int data;
    struct chain_element *next;
};
```



```c
int main()
{
    struct mystruct
    {
        int id;
        char sex;
        float height;
    };
    
    struct mystruct John;
    John.id=1133453;
    John.sex='M';
    John.height='178.3';
    
    printf("%d %c %f", John.id, John.sex, John.height);
    
    return 0;
}
```



```c
struct  point  p ={ 10 , 20 } ;
struct  point ∗ pp=&p ;
(∗pp).x  =10 ;   // Changes  p.x
int y=(∗pp).y;   // Same  as  y=p.y
```



![image-20221103110915708](C:\Users\USER\AppData\Roaming\Typora\typora-user-images\image-20221103110915708.png)

If we want to point into a specific place inside structure:

- structname.room
- (*ptr*).room
- ptr->room



## Intro of Stack

Link list 串列:

- stack 堆疊
- queue 隊列



There's only one opening in stack, same entry and exit. First in last out(FILO) / (LIFO); function call's implement of return address just works like this. Insert–>push, delete–>pop.

