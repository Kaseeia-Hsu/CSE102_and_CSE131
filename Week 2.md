

# C Language Designing & Experiment (I)



## Week 2

## Review for Week 1

### Compiler

We would like to turn our .c file, e.g. __HW1.c__ into __HW1.exe__, where a compiler is needed.



### Integer

- Unsigned
- Sight magnitude
- One's complement
- Two's complement



### Code Structure

``` c
#include <stdio.h>					// Preprocessor directive

int main(void)
{												// Entry point
    printf("Hello, world!");
    return 0:
}
```



## String

字串，like

``` c
printf("Hello, world!");			// "Hello, world!" is a string
```



## Declaring Variables

Variable declaration:

int n;                         declare "n" as an integer.

float phi;                   declare "phi" as a float.



Variable initialization:

n = 3;



Initializing at declaration:

float phi = 1.16893573;

int a, b, c = 0, d = 4;



## Data Types

| short       | 2 bytes |
| ----------- | ------- |
| int         | 4       |
| long        | 4       |
| float       | 4       |
| double      | 8       |
| long double | 12      |
| char        | 1       |



Declarations:

- char x;	uninitialized
- char x = 'A';    initialized to 'A'
- char x = 'A', y='B';    multiple variables initialized
- char x=y='Z';    multiple initializations



| Value 值     | number 30          |
| ------------ | ------------------ |
| Address 位址 | &(Ampersand)number |



### Boolean

int ans = 0;	false

int ans = 1;	true (if it's not zero, it's true)



### Characters

char answer='A';

char answer='%';



### ASCII

Stands for "American Standard Code for Information Interchange."

A = 65, a=97



### Examples

```c
int age;
char letter;
double cost, net_pay, avg;
int num=100;
float rate= 0.25;
char flag= '4';							// Not 00000100, but 52(2) = 00110100 from ASCII since it's a char.
```



## Input and Output

```c
printf("I have %d baseball cards.", number);
		// %d means a decimal number(An escape), while 'number' means that spectacular %d.
```



| %d   | decimal   |
| ---- | --------- |
| %ld  | long      |
| %f   | float     |
| %lf  | double    |
| %c   | character |
| %s   | string    |



```c
#include<stdio.h> 
int main ( ) 
{
	int age = 2;
	printf(" %d " , age);
}
```



```c
#include <stdio.h>
int main()
{
    int age1 = 25;
    double age2 = 25.3324;
    printf("My name is Kaseeia. \n");
    printf("I'm %d years old! \n", age1);
    printf("Precisely, I'm %.2lf years old.", age2);		// .2 means two decimal places in "25.3324"
}
```



```c
printf("%c", 65); 		// A
printf("%o", 15);		// 17(octal)
printf("%x", 15);		// 15(hexa)
```



```c
#include <stdio.h>
int main()
{
    int age;
    printf("Hello, please type your age.");		// prompting message
    scanf("%d" &age);		// Scan for a integer, and save it into &age(where the integer age located in)
}
```



```c
#include <stdio.h>
int main()
{
    int number1, number2;
    printf("please enter 2 numbers with space:");
    scanf("%d %d", &number1, &number2);					// type 10 20
    printf("%d %d", number1, number2);					// print 10 20
    printf("please enter 2 numbers with - symbol:");
    scanf("%d-%d", &number1, &number2);					// type 30-40
    printf("%d-%d", number1, number2);					// print 30-40
    return 0;
}
```



## Formatted Output

```c
#include <stdio.h>
int main()
{
    int x = 23;
    printf("*%d \n %3d \n %4d \n ");
    return 0;
}
```

And the output will be:

*23

_23

_ _ 23



```c
#include <stdio.h>
int main()
{
    int x = 23;
    float y =123.45;
    printf("%d\n %8.2f", x, y);		// %8.2f means saving 8 spaces, and 2 spaces for decimal spaces.
    return 0
}
```

And the output will be:

23

_ _ _ 123.45



%-2d	"-" means to put this line on the left side.

%+2d	"+" means to show this number's negative or positive



| %6.2f   |          |
| ------- | -------- |
| -99.42  | -99.42   |
| .123    | _ _ 0.12 |
| 99.999  | 100.000  |
| 999.4   | 999.40   |
| -25.554 | -25.55   |

