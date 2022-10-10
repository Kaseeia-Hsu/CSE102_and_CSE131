# C Language Design & Experiment (I)

## Week 5

## While Loops

```c
sum = count =0
    while(scanf("%d"), &x) != EOF&&count <= 100)	/* EOF means end of file, once you use ctrl+V, enter the value automatically(checking if you paste a number or enter a number manually.)*/
    {
        sum += x; count++;	//so once you use ctrl+V or count reach 100, this loop ends.
    }
printf("0.3f\n", (1.0*sum)/count );
```



```c
//Reversing a number.
int x, y = 0;
scanf("%d",&x);
while(x != 0){
    y = (x%10) + (y*10); x /= 10	//get 3+0=3=y, x=x/10=12, and x !=0, get y=32, x=1. Then we get y=321 x=0.
}
printf("\n%d\n",y);
```

X mold 10 is actually doing us acquiring the first digit from a number, and when X%10*10, the second digit of the number will be put into the first position once we plus them together.



 ```c
 #include <stdio.h>
 int score = 0;
 int sum =0;
 int count = -1;	//Using the value -1 since the last value(ending value) will be -1, and we're not going to count that in.
 
 while(score != 1){
     count++;	// Count become 0 when the first score enters
     sum += score;
     printf("Enter your score(enter -1 to end):");
     scanf("%d", &score);
 }
 
 printf("Avg. score: %f\n", (double) sum/count);
 ```



```c
#include <stdio.h>
int main()
{
    int N=10, i=0;
    while(i<=100)
    {
        printf("%d\n", i);
        i=i+N;
    }
}

// This code's final printf is 100, and i=110
```



```c
int main(){
    int input;
    printf("please enter a number");
    scanf("%d", &input);
    int i=1
        while(i <= 1000)
        {
            if(i%input==0)
                printf("%d", i);
            i++;
        }
    return 0;
}

//Finding multiples of input(<=1000).
```



```c
int i = j = 1;
while(i<10 && j<10)
{
    printf("%d x %d = %2d\n", i, j, i*j);
    i++;
    j+=2;
}
```



```c
#include<stdio.h>
int main()
{
    int year = 0, population;
    scanf("%d", &population);
    while(population <=30000)
    {
        printf("%year%d: %d men.\n", year, population);
        year++;
        population *= 1.1;
    }
    printf("It requires %d years to reach 30000 population.\n", year);
}
```



```c
scanf("%c", &ch);
while(ch==' ')
{
    scanf("%c", &ch);
}
```



```c
sum = count = 0
    whule(scanf("%d",&x) != EOF)
{
    sum += x;
    count++;
}
```



```c
int sum = 0;
for(int i = 1; i <= 100; i++)
{sum += i;}

--------------------
    
int sum = 0, i = 1;
while(i <= 100)
{
    sum += i;
    i++;
}
```



## Do While Loops

This loop run the command first and then check if the conditions are true or not.

```c
char   c ;
do {
puts ( "Keep going? (y/n) " ) ; 
c = getchar ( ) ;
} while   ( c  ==  'y' );
```



```c
#include <stdio.h>
int main()
{
    int input = 0, replay = 0;
    do{
        scanf("%d", input);
        getchar();
        printf("odd or not? %c\n", ((input %  2) ? 'Y' : 'N'));
        printf("Keep going?(Y/N)");
        scanf("%d", &replay);
        getchar();
    }
    while(replay);
}
```



```c
//Checking valid response

do{
    printf("Continue? (Y/N)");
    scanf("%c", &response);
}
while(respont != 'Y' && response != 'N');
```



```c
for(int i=3; j<=9; j++)
{
    printf("%d x %d = %2d", i, j, i*j);
}

--------------------
    
for(int i = 3; j <=9; j++)
{
    printf("%d x %d = %2d", j, i, j*i);
}
```



## Nested Loops

```c
#include<stdio.h>

int main()
{
    for(int i=1; i<=9; i++)
    {
    for(int j=1; j<=9; j++)
        printf("%d x %d = %2d", i, j, i*j);
        printf("\n");
    }
    return 0;
}
```



## Infinite Loops

```c
int i=1;
while(i>0)
    i++;
```



## Break & Continue

```c
#define min(a,b) ((a)<(b) ? (a) : (b))

int gcd(int a, int b){
    int i, ret = 1, minval = min(a,b);
    for(i = 2; i <= minval; i++){
        if(a%i)
            continue;	// Skip the rest of innermost loop body, jumping to condition.
    	if(b%i == 0)
        ret = i;
    }
    return ret;
}
```



```c
int main()
{
    int i, j;
    char ch = 'A';
    for(i=1; i<=10; i++)
    {
        if(i == 6)
            break;
        
        j=1;
        while(j<10)
        {
            if(j == 7)
                break;
            printf("%2d%c", i, ch);
            j++;
        }
        ch++;
        printf("\n");
    }
    return 0;
}
```



```c
#include<stdio.h>

int main()
{
    int sum, i;
    while(i <= 100)
    {
        sum += i;
        i++;
    }
    printf("Sum: %d", sum);
    return 0;
}
```



## Goto

goto allows you to jump unconditionally to arbitrary part of your code. Using goto makes code harder to debug.



## Array

Data type + Array name[numbers];

```c
int num[10];
double score[10];
char ascii[10];

int num[5] = {0, 1, 2, 3, 4};
```



```c
#include<stdio.h>

int main()
{
    int i;
    int math[50];
    
    for(i=0; i<50; i++)
        scanf("&d", &math[i]);
}
```



```c
#include<stdio.h>

int main()
{
    int n[10];
    int i;
    for(i=0; i<10; i++)
    {
        n[i]=0;
    }
    for(i=0; i<10; i++)
    {
        printf("element %d: %d", i, n[i])
    }
    return 0;
}
```



## Random Number

```c
#include <stdio.h>
#include <time.h>

int main()
{
    srand(time(0));	// If we don't declare a srand function, the result for rand will be the same everytime.
    
    int number = rand();	// 0~32767
    Int num = rand() % 99 + 1; // 1~99
    Int num = rand() % 30 + 1980; // 1984~2009
    
    return 0;
}

// If you put srand(time(0)); into a loop, it will crash the randomness of the function since there'll be a huge amount of loop being done in a sec(for the situation that you use a time()function as a seed). So just put it outside of any function except main().
```

