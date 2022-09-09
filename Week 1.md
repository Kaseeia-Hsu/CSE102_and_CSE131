# C Language Designing & Experiment (I)



## Course I

This course will start to cover Pointers in C after midterm. We have 2 midterms/ 1 finales __online__ in this course. No plagiarism is allowed.



### 1.1 Introduction of C

Human language is a so called high-level language e.g. __x=y+1__.

While computer is a binary digital(0&1) system, so that's why we need IDE to turn our language into high-level language. Assembling language is very closed to machine code(Which is really painful according to YW, Jiang.)



High-level language => Compiler => 0101(Machine code). Turning your codes from .c into .exe

C is not a object-oriented language, which is a huge flaw, and C++, objected C, and C# tend to extend C. This kind of low-level language usually runs faster.



#### Digital Logic

0= false 1=true

- AND

  00=0, 01=0, 10=0, 11=1

- OR

  00=0, 01=1, 10=1, 11=1

- NOT

  0=1, 1=0

- Di Morgen

  ~(A U B)=~A anti-U ~B



- 十进位制

  1001= 1x10^3+1x10^0

- 二进位制

  101= 1x2^2+0x2^1+1x2^0

- 十六进位制

  from 0~ABCDEF(0~15)



- 二进位转换十进位(bin to deci)

  101(2)=5(10)

- 十进位转二进位(deci to bin)

  12(10)=1100(2)

  长除法的余数：

```
12/2 =6 ... 0 (a0)

6/2 =3 ... 0 (a1)

3/2 =1.. 1 (a2)

1 (a3) 
```

​	  八进位与十六进位同理



bit=one 0 or 1(2^1), 2^10=1024~~1K, (2^10)^2=IM, (2^10)^3=1G

byte= eight 0 or 1



- 二进位转八进位(bin to octal)

  三个数看一组，vice versa.

  e.g. 101001110.010= 101(5) 001(1) 110(6) .010(2) = 516.2

- 二进位转十六进位(bin to hexa)

  四个数看一组, vice versa.

  

#### Integer

3 is an integer, while 3. is a float.

Unsigned integer, it is a number with no negative mark. （无号整数表示法）

It could only save for 0~(2^n-1) bits, and if the number is larger than n, __overflow__ happens.

In the opposite, __underflow__ is also a kind of error.



So how we're going to perform negative number? __Using sign bit__ in the first position

0 means + and 1 means -, so 0000 means +0, and 1010 means -2. But 0000 and 1000 actually means the same thing, so what should we cope with it?



We use one's complement first（一的补数表示法）

```
0000 +0 <=> 1111 -0

0001 +1 >=> 1110 -1

0010 +2 <=> 1101 -2

0011 +3 <=> 1100 -3
```



Then Two's complement: (One's complement+1)

```
0000 1111 0000 (overflow) finally there's no +-0

0001 1110 1111

0010 1101 1110

0111 1000 1001 
```

回推：1001 to 0110, then we plus 1 and it became 0111, and we could also know that it's a negative number at the same time! So that's why we use Two's complement in our computer.



#### 浮点数

32bits(4bytes) 单精度浮点运算

32bits(8bytes) 双精度浮点运算

e.g. -161.875, S=1(-) (10100001.111)(2)

小数点拉到第一位数后(1.0100001111)(2)x2^7



#### Basic Code Structure - 1

```c
#include<stdio.h> 	/* I would like to use stdio.h to translate my language(标准io程式库)*/
int main()        		   /* int means I will get an integer back after I ran it. main is a function.*/
	{
    return 0;
}
```

```c
//The main() function
int main(void) //entry point
	{
    puts("Hello, 6.087 students"); //putstrings(输出字串)
    return 0;
}
```



#define YEAR 1776(string)



#### Basic Code Structure - 2

- Sequential（线性程序）
- Conditional（条件程序）
- Looping（重复执行）

```c
#include<stdio.h>
int main()
{
    int a = 0;		//a is a integer, and gives 值0.
    int b = 1;	    //same as above.
    int c = a + b;
    printf("c = %d, c"); //escape sequence=> %d(decimal, 十进位数, 一个字串)
    return 0;
}
```



\n change line
