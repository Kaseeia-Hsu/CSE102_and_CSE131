#include <stdio.h>
#include <stdlib.h>

// No, it only changes the value of a, but not b.
// We do like this

int a=0, b=1;

void myswitch(void);

int main()
{
	myswitch();
	printf("a=%d, b=%d", a, b);
	
	return 0;	
}

void myswitch(void)
{
	int tmp;
	tmp=a;
	a=b;
	b=tmp;
}
