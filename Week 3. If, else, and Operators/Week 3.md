# C Language Designing & Experiment (I)



## Week 3

## Review of Week 2

- int  🡪 %d

- char  🡪 %c

- Float 🡪 %f（單精度浮點數）

- Double 🡪 %lf （雙精度浮點數）

%nd 🡪 共輸出n個位元，n為正整數         

%.nf 🡪 可控制小數點後要輸出幾位，n為正整數

### Operators

- Arithmetic operator:

+, -, *, /, %(modulo)

- Relational operator:

<, >, ==, !=(unequal), &&(and), ||(or)

- Bitwise operator:

~(not), &(and), |(or)



## Definitions(contd.)

```c
#include <stdio.h>
int main()
{
    int age;
    char; letter;
    double cose, avg, net_pay;	// didn't initialize
    
    int Sum, SUM, sum;	// Causing confusion between variables
    
    int num = 100;
    float rate = 0.25;
    char flag = '4';
    // not a number, but a character ( int =4  byte= 32x 0 and 1 ). (char = 1 byte = 8x 0 and 1, depends on ASCII)
}
```



## Constant

```c
------------------------------------------
    
const CARDS = 52;
#define Pi 3.14
#define my_name 'K'
#define mult(a,b) // a*b

------------------------------------------
    
#include <stdio.h>
#define PI 3.14159
#define RADIUS 100
#define AREA PI * RADIUS * RADIUS 
int main()
{
    printf(" %f \n", AREA);
    return 0;
}
// output = 31415.900000

------------------------------------------
```



## Operators

- binary operator: 3 __+__ 5

- unary operator: __+__3 / __-__3



20.5 / 5 = 4.1

20 / 5.0 = 4.0

20 / 6 * 2.0 = 6.0 (3.0 x 2.0)

2.0 * 20 / 6 = 6.667 (2.0 x 20.0 / 6.0)

### ++ and --

```c
#include <stdio.h>
int main()
{
    int y, x;
    x = 3;
    y = x++; // y = x, x = x +1, so y = 3 and x = 4.
    y = ++x; // x = x + 1, y = x, sp y = 4 and x = 4.
}
```

```c
x += y	// x=x+y
x -= y	// x=x-y
x *= y // x=x*y
x /= y	// x=x/y
x %= y	//x=x%y
```



### Relational Operators

Using >, <, = to do comparing. And the result will only be 1(true), or 0(false).

| >    | 3 > 2, 1      |
| ---- | ------------- |
| <    | 2.99 < 3, 1   |
| ==   | 3 == 3, 1     |
| >=   | 4 >= 3, 1     |
| <=   | 'A' <= 'B', 1 |
| !=   | 2 != 3, 1     |



### Logical Operators

| !    | Not true=false, not false=true        |
| ---- | ------------------------------------- |
| &&   | AND, 2 true = true(Both are required) |
| \|\| | OR, 1 true = true                     |



```c
------------------------------------------
    
// <<= and >>=
6 0110	// >>1
3 0011	// >>1
1 0001	// <<1
2 0010
    
------------------------------------------
    
x+=1 /∗is  the same as x=x+1∗/
x−=1 /∗is the same as x=x−1∗/
x∗=10 /∗is  the same as x=x∗10 ∗/
x/=2 /∗ is  the same as x=x/2
x%=2 /∗is the same as x=x%2

------------------------------------------

#include <stdio.h>
int main( ) 
{
	unsigned int x , y , z; 
	x = 11; 		//00...001011
	y = x << 1 ;	//00...010110 = 22	
	z = x << 2 ;	//00...101100 = 44
	printf("x = %d , y = %d ,z = %d",x,y,z);
}
// x = 11, y = 22, z = 44

------------------------------------------
```



```c
isupper = (c >= 'A' && c <='Z')?1:0;
// if c is between 'A' and 'Z'(Capital letters), the variable "isupper" will be true

if(!isupper)	// ! means not, so "isupper" needs to be false to make this if true(double not)
    c=c-'a'+'A';	// And if c is not a capital letter, change it into the capital one. (小寫字母-a的ASCII+A的ASCII)
```

In the opposite, if we want to turn a capital letter into a lower case:

```c
if(isupper)
    c=c-'A'+'a';
```



## Blocks and Compound Statements

### Nested Blocks

```c
{
	int temp  =  x+y ; z  =   foo ( temp ) ;
	{
		float temp2  =  x ∗ y ; z  +=   bar ( temp2 ) ;
	}
}
```



## If... else

```c
------------------------------------------
    
if(judgement)	// and if it's true, do the things below, if it's false, it'll skip the commands below
{
    descriptions;
}

------------------------------------------
    
if (x % 2)	// when x is a sigma, the command proceeds, but when x is an even, it skips
    y += x/2;

------------------------------------------
    
if   ( x  %  2  ==  0 )	// if x is an even 
    y  +=  x / 2 ;

else
	y  +=   ( x + 1 ) / 2 ;	//if x is a sigma

------------------------------------------
    
if   ( x  %  2  ==   0 ) // if x modulus 2 = 0? (if it is an even?)
    y  +=  x / 2 ;
else   if   ( x  %  4  ==   1 )	// if x modulus 4 = 1? (or the remainder will be 0, 2, or 3)
    y  +=   2 ∗ ( ( x + 3 ) / 4 ) ;
else // otherwise, do this (Exclude the number with ramainder 0, 2 since it's an even, and remainder 3 left)
	y  +=   ( x + 1 ) / 2 ;

------------------------------------------
```



## If Syntax

Using "if" to tell student if they passed the exam(>60) or not:

```c
#include <stdio.h>

int main()
{
    int grade;
    printf("Enter your grade");
    scanf("%d", &grade);
    if(grade < 60)
    {
        printf("Failed. \n");
    }
    else
    {
        printf("Passed. \n");
    }
    return 0;
}
```

Asking if the user wants to enter the service system:

```c
#include <stdio.h>

int main()
{
    char ans;
    printf("if you'd like to enter the system?(Y/N)");
    scanf("%c", &ans);
    if(ans = 'Y')
        printf("Welcome to the customer service system!");
    return 0;
}
```

Comparing which number's value is bigger:

```c
#include <stdio.h>

int main()
{
    int x = 5;
    int y = 10
        if(x >= y)
            printf("x is bigger than y");
    else if(x == y)
        printf("x equals to y");
    else
        printf("x < y");
    return 0;
}
```



