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
    	fscanf(file, "%d", &load[i]);	// ����fscanf�� 
        ret=fscanf(file, "%d", &load[i+1]);	// ���K��U�@�찵fscanf 
        
        if(ret == EOF)	// �p�G�U�@��OEOF, �h�b���פ�(�����ƭȤw�s�J&load[i]) 
        break;
        
        len=i;	//���� 
        i++;
    }
	fclose(file);
	
	//Bubble sort
	file = fopen("sorted.txt", "w");
	
	bubble(load, len);
	
	for(i=0; i<len; i++){
		fprintf(file, "%d\n", load[i]);	//�g�J�ɮ� 
		printf("%d\n", load[i]);
	}
	fclose(file);
	
	printf("�п�J�n�j�M��key:");
	scanf("%d", &key);
	val = binary(key, 0, len-1, load);	//val=binary function return����(�ĴX���) 
	
	if(val==-1)
	printf("��key���s�b");
	
	else
	printf("key:%d�b��%d�Ӧ�m", key, val+1); //val+1 since ��Ʊq0�}�l 
	
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
	if(size==1){	//if size==1 �L���Ƨ� 
		return;
	}

	for(j=0; j<size-1; j++){	 
		if(arr[j]>arr[j+1])
		swap(&arr[j], &arr[j+1]); // swap function 
	}
	
	bubble(arr, size-1);	//�C��size-1, �۷��쥻���hfor�j������ e.g for(k=0; k<size-1; k++){for(j condition...)} 
}

int binary(int num, int low, int high, int arr2[]){
	
	if(low>high)
	return -1;	//�Ylow > high �����䤣�� 
	
	int mid = (low+high)/2;	 
	if(num==arr2[mid])
	return mid;	
	
	else if(num>arr2[mid])
	return binary(num, mid+1, high, arr2);	// recursive, ��num>mid��(���U��) 
	
	else if(num<arr2[mid])
	return binary(num, low, mid-1, arr2);	// �P�W, ����num<mid��(���W��) 

}
