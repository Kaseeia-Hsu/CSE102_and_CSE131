#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int a = 500;
	printf("Value of a = %d\n", a);
	printf("Address of a = %p\n", &a);
	printf("Value of address '&a'=%d\n", *&a);
	
	return 0;
} 
