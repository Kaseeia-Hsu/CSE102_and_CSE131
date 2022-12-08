# C Language Design & Experiment (I)



## Week 4

## Review of Week 3 

```c
#include <stdio.h>
int main()
{
    char Ansl;
    printf("Would you like to enter the system?(Y/N)");
    scanf("%c" &Ansl);
    if(Ansl = 'Y')
        printf("Welcome!");
    else
        printf("closing the sysyem...");
    return 0;
}
```



## Nesting If

Else follows the nearest if command, so if you want to use two "if"(or above), using curly brakets:

```c
if(x%4 == 0)
{
    if(x%2 == 0)
        y=2;
}
else
    y = 1;
```



Please notice the difference between these two code area below:

```c
int x = 8, y = 4;
if (y<=x)
    if(x>8)
        x++;
else
    y--;

//output: 8, 3
```



```c
int x=8, y=4;
if (y<=x)
{
    if(x>8)
        x++;
}
else
    y--;

//output: 9, 4
```



Using flag:

```c
if(code==0)	//code's zero
{
    scanf("%d",&x);
    flag = (x>=100);	//flag is using to check if a thing is true or false
    if(flag)	//code's zero and flag is true
        printf("3 or more digits\n");
}
else	//codes' not zero
```



```c
#include <stdio.h>
int main()
{
    char ans1, ans2;
    printf("would you like to enter the system?(Y/N)\n");
    scanf("%c", &ans1);
    if(ans1='Y')
    {
        printf("Welcome\n");
        printf("Enter 1, 2, or 3\n");
        scanf("%c", &ans2);
        if(ans2 == '1')
        printf("choose 1");
        else if(ans2 == '2')
        printf("choose 2");
        else
            print("choose 3");
        return 0;
    }
}
```



```c
if(grade == 'A')
    printf("Excellent");
else if(grade == 'B')
    printf("Good");
else if(grade == 'C')
    printf("Average");
else
    printf("Can't find %c", grade);
```



```c
int x=8, y=7, z=6;
if(x>y)
    (
    if(x>z)
    printf("x is the biggest");
    else
    printf("z is the biggest");
    )
else if (y>x)
{
    if(y>z)
        printf("y is the biggest");
    else
        printf("z is the biggest");
}
return 0;
```



## "Switch" Syntax

```c
switch   ( ch )  
{
case  ’Y’ :   / ∗  ch  ==   ’ Y ’   ∗ /
/ ∗  do   something   ∗ /
break ;
case  ’N’ :   / ∗  ch  ==   ’N ’   ∗ /
/ ∗  do   something   else   ∗ /
break;
default :   / ∗  otherwise   ∗ /
/ ∗  do  a   t h i r d   t h i n g   ∗ /
break ;
}
```



```c
#include <stdio.h>

int main()
{
    char a1, a2;
    printf("If you would like to enter the system?");
        scanf"(%c", &a1);
    if(a1 == 'Y'){
        printf("choose 1, 2, or 3");
    scanf("%c", &a2);
    switch(a2){
        case'1':
            printf("1");
    break;
    	case'2':
    		printf("2")
   break;
    	case'3':
    		printf("3");
    break;
    }
    }
    else
        printf("Exiting the system...");
    return 0;
}
```



### Multiple Cases

```c
switch   ( ch )   {
case  ’Y’ :
case  ’y’ :
/ ∗  do   something   i f ch  ==   ’ Y ’   or
ch  ==   ’ y ’   ∗ /
break ;
	}
```



```c
sum = 0
    if(x>=1 && x<=5)
    {
        switch(x)
        {
            case 5: sum = x; x--;	// if x = 5, sum=5, and x becomes 4
            case 4: sum += x; x--;	// 5+4, x becomes 3
            case 3: sum += x; x--;	// 9+3, x becomes 2
            case 2: sum += x; x--;	// 12+2, x becomes 1
            case 1: sum += x;	// 14+1
        }
    }
else
    printf("the number is not in range");
```



## Looping

### "For" Loop

for(初始變數; 判斷條件 ; 增減式)

{

 迴圈主體;

}



```c
#include <stdio.h>
int main()
{
    int i;
    for(i =1 ; 1 <= 10; i++)
        printf("%d", i);
}

// output: 1 2 3 4 5 6 7 8 9 10
```



```c
#include <stdio.h>
int main()
{
    int i;
    for(i = 10; i > 0; i--)
        printf("%d", i);
}
```



Swap, x=1, y=2;

temp=x, x=y, y=temp;

then __x=2, y=1__.



```c
#include <stdio.h>
int main()
{
    int sum;
    for(sum = 0; sum <=100; sum++)
        printf("%d", sum);
}
```



```c
for(x=2; x<=1000; x=x+2)
    sum = sum + x;

// only plus evens
```



```c
fact = 1
for(x=1; x<=1000; x=x++)
    fact = fact * x;
    
// factorial (1000!)
```



```c
int k, i=9;
for(int j=1; j<= 10; ++j)
{
    k=i*j;
        printf("k");
}

// output: 9 18 27...90
```



```c
#include<stdio.h> 
int main ()
{
	int N = 10;
	for(i = 0; i <= 100; i += N) 
		printf("%d \n", i);     
}
```



```c
for(x=0, y=MAX; x<=N; x++)
{
    printf("%d", x+y);
    if((x+1)%5 == 0)
        printf("\n");
}
printf("\n");

// Skip a line after 5 numbers

100 101 102 103 104
105 106 107 108 109
```



```c
#define N 10

for(i=0; i<=100; i+=N)
    printf("%d", i);
printf("\n");

// 10 for loops
```



### "While" Loop

While(判斷條件)

{

 迴圈主體;

 設定增減量;

}

```c
#define SENTINEL -999

int number;
scanf("%d", &number);
while(number != SENTINEL)
{
    printf("%d\n", number);
    scanf("%d", &number);
}

// Print out the number you enter, and it only ends when you type in -999
```



