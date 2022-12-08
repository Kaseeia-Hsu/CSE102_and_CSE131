#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *n1, int *n2, int *n3){
	int min=*n1;
	int temp;
	if(*n1>*n2){
		temp=*n1;
		*n1=*n2;
		*n2=temp;
	}
	if(*n1>*n3){
		temp=*n1;
		*n1=*n3;
		*n3=temp;
	}
	if(*n2>*n3){
		temp=*n2;
		*n2=*n3;
		*n3=temp;
	}
}

int main(){
	int n1, n2, n3;
	int * ptr1;
	int * ptr2;
	int * ptr3;
	
	printf("請輸入3變數(e.g 3 1 12):");
	scanf("%d %d %d", &n1, &n2, &n3);
	printf("n1=%d\n", n1);
	printf("n2=%d\n", n2);
	printf("n3=%d\n", n3);
	
	ptr1=&n1;
	ptr2=&n2;
	ptr3=&n3;
	
	swap(ptr1, ptr2, ptr3);
	
	printf("三數由小排到大:\n");
	printf("n1=%d\n", n1);
	printf("n2=%d\n", n2);
	printf("n3=%d\n", n3);
	return 0;
} 
