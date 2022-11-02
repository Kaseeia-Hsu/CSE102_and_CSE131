# C Language Design & Experiment (I)

## Week 7

## Review

```c
rand() % 10;	// 0~9
ranrd() %901 + 100;	// 100~1000
```



We'll found that the random number value will be the same as we repeat the program every single time. That's why we need to "sow" a rand seed, and we only need to execute it once at the beginning of the program. 



```c
#include <stdio.h>
#include <time.h>
int main()
{
    int a;
    srand(time(NULL));
    a = rand() % 500;
    return 0;
}
```



```c
#include <stdio.h>

int main()
{
    int count = 0;
    srand(time(NULL));
    for(int i = 1; i<=10000; i++)
    {
        dice = rand() %6+1;
        if((dice) == 1)
            ++count;
    }
    possibility = count / 10000;
    return 0;
}
```



## File Operation

FILE I/O is included in <stdio.h>. If we want to proceed a file, we need to do "fopen" first. And if we want to close the file, we do "fclose," vice versa.



```c
int main()
{
    char str[20]={'\0'};
    FILE *file=fopen("test.txt","r");	//r means read mode, check if you have the authority to read. After checking it, it save the address of the file into a pointer "*file." While FILE itself is a keyword to tell that *file(address) will save a file. 
    fscanf(file, "s", str);	//loading the data of the file into str.
    system("type test.txt");	//test.txt shows on string.
	printf("\n");
	fclose(file);
	return 0;
}
```



```c
FILE *file=fopen("test.txt","r");
fprintf(file, "%s", "Hello world!");	// Write the data "Hello world!" into the file.
system(pause);
fclose(file);
return 0;
```



```c
int a;	// a is a integer
int *b;	// means that what's inside the pointer(address) *b is a integer, not simply a declaration.
```



```c
include <stdio.h>
    
int main()
{
    int account;
    char name[];
    double balance;
    FILE *cfPtr;
    
    if(cfPtr = fopen("data.txt","w") = NULL)
    {
        printf("File could not be opened\n");
    }
    else
    {
        printf("Enter the account, name, and balance.\n");
            	printf("Enter EOF to end input.\n");
    	printf("? ");
    	scanf("%d%s%lf",&account, name, &balance);   
        
      	while(!feof(stdin))	// not end of file(EOF)
	   { 
          fprintf(cfPtr,"%d %s %.2f\n",account, name, balance);
	      printf("? ");
	      scanf("%d%s%lf", &account, name, &balance);
    	}
    	fclose(cfPtr);	
	}	
   return 0;
}
```



```c
   while(1){
      printf("\n選項？ ");
      scanf("%d", request);
      if(request == 4)
         break;
      switch(request)
      {
         case 1:
            printf("\n所有學生與分數\n");
            break;
         case 2:
            printf("\及格學生與分數\n");
            break;
	      case 3:
            printf("\n不及格學生與分數\n");
            break;
      }
      fscanf(file, "%d\t%s\t%d", &account, name, &score);
     while(!feof(file))
     	{
         if((request == 1) || (request == 2 && score >= 60) || (request == 3 && score < 60))
     	printf ("%d\t%s\t%d\n", account, name, score);
     	fscanf(file, "%d\t%s\t%d", &account, name, &score);      
     	}
    rewind(file);	// Once it's EOF, we rewind the pointer back to the start point of the file.
   }
fclose(file);	// If we choose 4 at the beginning.(leave the while(1) loop.)
return 0;
}
```



## Function

Divide & Conquer, we conquer a one, huge, difficult problem into small pieces so that it's easier for us to solve.



```c
#include <stdio.h>

void FindMax(int num1, int num2, int num3)
{
    int max = num1;
    if( num2 > max )
    	max = num32;
    if( num 3 > max)
        max = num3
}

------------------------------------------------------------
    
#include <stdio.h>

int main()	// Main function is always the entry point.
{
    count(5,10);	// go to count function.
}

void count(int n1, int n2)	// n1 and n2 are local variables, once leaving this function, there's no such a int n1 defined.
{
    printf("%d", n1+n2)	// Go back to count(5,10);
}
```



```c
#include <stdio.h>

void square(int num)
{
    printf("%d" num*num);
}
int main()
{
    square(10);
}
```



### Do Swap with Function

```c
#include <stdio.h>

void swap(int, int);	// Function prototype, if lacks this, C won't know what is "swap" when main function executing swap(a, b) line.
int main()
{
    int a=3, b=5;
    printf("Before swap, a=%d, b=%d", a, b);
    swap(a, b);
    return 0;
}

void swap(int x, int y)	// Define the prototype.
{
	int temp = x;
	x = y;
	y = temp;
	printf("a=%d, b=%d", x, y);
	return 0;
}
```



```c
#include <stdio.h>

void modifyArray(int b[], int size);	// Array's name and its size.
void modifyElement(int e);

int main()
{
    int a[SIZE]={0,1,2,3,4};
    int i;
	printf("Effects of passing entire array by reference: \n");
	printf("The value of the orginal array are: \n");
	for(i=0; i<SIZE; i++){
		printf("%3d",a[i]); }
    	printf("\n");
	modifyArray(a,SIZE);	// First function
	printf("The value of the modified array are: \n");
	for(i=0; i<SIZE; i++){
		printf("%3d",a[i]);}
	printf("\n\n\nEffects of passing array element by vlaue:\n\n");
	printf("The value of a[3] is %d\n",a[3]);
	modifyElement(a[3]);	// Second function
	printf("The value of a[3] is %d",a[3]);
	return 0; }

	void modifyArray(int b[], int size)	// a and SIZE=5, and b become the same as a. (pass-by-address)
    {	
	int j;
	for(j=0; j<size; j++)
    	{
		b[j]*=2;	// Multiple every elements of a array with 2.
		}
	}

	void modifyElement (int e){	// e become 3( from a[3] ) (pass-by-value)
	printf("Value in modifyElement is %d\n", e*=2);	// e*2=6
	}

}
```



```c
void swap(int x, int y);

int main()
{
    int a=3, b=5;
    swap(&a, &b)
    printf("%d %d", a, b);	// Getting 5 3
}

void swap(int *x, int *y)
{
    int temp = *x;	// temp = 3
    *x = *y;	// 5 to &a(*x)
    *y = temp;	// 3 to &b(*y)
}
```



