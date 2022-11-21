#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int load[1000];
int i=0;
int ret, len, key, val;

void bubble(int arr[], int);	// Recursive Bubble Sort
void swap(int*, int*);	// Recursive swap
int binary(int, int, int, int arr2[]);	// Recursive binary search

int main(){
	
	FILE *file = fopen("test.txt", "r");
	
	//fscanf test.txt
    while(1)
    {
    	fscanf(file, "%d", &load[i]);	// 執行fscanf時 
        ret=fscanf(file, "%d", &load[i+1]);	// 順便對下一位做fscanf 
        
        if(ret == EOF)	// 如果下一位是EOF, 則在此終止(本輪數值已存入&load[i]) 
        break;
        
        len=i;	//長度 
        i++;
    }
	fclose(file);
	
	//Bubble sort
	file = fopen("sorted.txt", "w");
	
	bubble(load, len);
	
	for(i=0; i<len; i++){
		fprintf(file, "%d\n", load[i]);	//寫入檔案 
		printf("%d\n", load[i]);
	}
	fclose(file);
	
	printf("請輸入要搜尋的key:");
	scanf("%d", &key);
	val = binary(key, 0, len-1, load);	//val=binary function return的值(第幾位數) 
	
	if(val==-1)
	printf("此key不存在");
	
	else
	printf("key:%d在第%d個位置", key, val+1); //val+1 since 位數從0開始 
	
	return 0;
}

void swap(int *fir, int *sec){
	int temp;
	temp = *fir;	// fir=&arr[j], sec=&arr[j+1]
	*fir = *sec;
	*sec = temp; 
}

void bubble(int arr[], int size){
	
	int j;
	if(size==1){	//if size==1 無須排序 
		return;
	}

	for(j=0; j<size-1; j++){	 
		if(arr[j]>arr[j+1])
		swap(&arr[j], &arr[j+1]); // swap function 
	}
	
	bubble(arr, size-1);	//每輪size-1, 相當於原本雙層for迴圈變體 e.g for(k=0; k<size-1; k++){for(j condition...)} 
}

int binary(int num, int low, int high, int arr2[]){
	
	if(low>high)
	return -1;	//若low > high 說明找不到 
	
	int mid = (low+high)/2;	 
	if(num==arr2[mid])
	return mid;	
	
	else if(num>arr2[mid])
	return binary(num, mid+1, high, arr2);	// recursive, 當num>mid時(更改下界) 
	
	else if(num<arr2[mid])
	return binary(num, low, mid-1, arr2);	// 同上, 但當num<mid時(更改上界) 

}
