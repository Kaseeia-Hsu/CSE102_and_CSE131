#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int *ptr = malloc(sizeof(int[4]));
	// int *ptr = malloc(4*sizeof(int));
	int i;
	
	for(i=0; i<4; i++){
		printf("請輸入第%d個數:", i+1);
		scanf("%d", &ptr[i]);
	}
	
	for(i=0; i<4; i++){
		printf("第%d個數為:%d\n", i+1, ptr[i]);
	}
	
	free(ptr);
	return 0;
}
