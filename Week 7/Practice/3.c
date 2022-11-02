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
	
    for(k=0; k<18; k++)
        for(j=0; j<20-1-k; j++)
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
	
	printf("排序後: ");
	for(i=0; i<20; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
