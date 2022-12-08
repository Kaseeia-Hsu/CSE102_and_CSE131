#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

int data[1000];
int i, len, next, key, val;

int binary(int num, int arr2[], int low, int high)
{
	if(low > high)
		return -1;
	int mid = (low + high) / 2;
	if(num == arr2[mid])
		return mid;
	else if(num > arr2[mid])
		return binary(num, arr2, mid+1, high);
	else if(num < arr2[mid])
		return binary(num, arr2, low, mid-1);
}

void swap(int*a, int*b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int size)
{
	int j;
	if(size == 1) //�u���@�Ӥ��α� 
		return;
		
	for(j=0;j<size-1;j++)
	{
		if(arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);
	}
	
	return bubbleSort(arr, size-1); //�C����֤@��(�w�g�Ʀn��) 
}

int main()
{
	//Ū��test�ɮפ���
	FILE *file = fopen("test.txt", "r");
	
	while(1)
	{
		fscanf(file, "%d", &data[i]);
		next = fscanf(file, "%d", &data[i+1]); //�O���U�@��
		
		if(next == EOF)
			break;
		
		len=i; //�����`���� 
		i++;
	}
	fclose(file);
	
	//�w�j�ƧǪk
	bubbleSort(data, len);

	//�g�Jsorted
	file = fopen("sorted.txt", "w");
	
	for(i=0;i<len;i++)	
	{
		fprintf(file, "%d\n", data[i]);
		printf("%d\n", data[i]);
	}
	fclose(file);
	
	//BinarySearch
	printf("�п�J�n�j�M��key: ");
	scanf("%d", &key); 
	
	val = binary(key, data, 0, len-1);
	if(val == -1)
		printf("��key���s�b");
	
	else 
		printf("key: %d �b��%d�Ӧ�m", key, val+1);
		
	return;
}

