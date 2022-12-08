#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int len;

void show(int arr[]);

int main(){	
	int i;
	printf("請輸入陣列長度:");
	scanf("%d", &len);
	
	int arr[len];
	srand(time(NULL));
	
	for(i=0; i<len; i++){
		arr[i]=rand()%100+1;
	}
	
	show(arr);
	return 0;
}

void show(int arr[]){
	int i;
	for(i=0; i<len; i++){
		printf("%4d", arr[i]);
	}
}
