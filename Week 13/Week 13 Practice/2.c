#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int n1, n2;
	int * ptr1;
	int * ptr2;
	
	printf("n1=");
	scanf("%d", &n1);
	printf("n2=");
	scanf("%d", &n2);
	
	ptr1=&n1;
	ptr2=&n2;
	
	printf("%d x %d = %d", *ptr1, *ptr2, *ptr1 * *ptr2);
	return 0;
} 
