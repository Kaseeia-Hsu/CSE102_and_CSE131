#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int *ptr = malloc(sizeof(int[4]));
	// int *ptr = malloc(4*sizeof(int));
	int i;
	
	for(i=0; i<4; i++){
		printf("�п�J��%d�Ӽ�:", i+1);
		scanf("%d", &ptr[i]);
	}
	
	for(i=0; i<4; i++){
		printf("��%d�ӼƬ�:%d\n", i+1, ptr[i]);
	}
	
	free(ptr);
	return 0;
}
