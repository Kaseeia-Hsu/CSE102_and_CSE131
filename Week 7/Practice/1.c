#include <stdio.h>
#include <time.h>

int main()
{
	int arr[20];
	int k, j, min, temp, i, e;
	srand(time(NULL));
	
	printf("排序前: ");
	for(e=0; e<20; e++)
	{
	arr[e]=rand() % 200 + 1;
	printf("%d ", arr[e]);
	}
	
	printf("\n");
	
	for(k=0; k<20; k++)
	{
    int min = k;
    for(j = k+1; j<20; j++)
        if(arr[j]<arr[min])
          min = j;
    
    if(min != k)
		{	
        temp = arr[min];
        arr[min]=arr[k];
        arr[k]=temp;
    	}
	}
	
	printf("排序後: ");
	for(i=0; i<20; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
