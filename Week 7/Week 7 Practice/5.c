#include <stdio.h>

int main()
{
	int search, i, j;
	int data[11]={2, 5, 8, 12, 13, 18, 21, 29, 37, 49, 97};
	
	printf("�ƦC:");
	for(i=0; i<11; i++)
	{
		printf("%d ",data[i]);
	}
	printf("\n�j�M���:");
	scanf("%d", &search);
	printf("\n");

	int low=0, high=10;

	while(low<=high)
	{
    	int mid = (low+high)/2;
    	printf("�Ѿl���: ");
    	for(j=low; j<=high; j++)
    	{
    		printf("%d ",data[j]);
		}
    	printf("�����: %d",data[mid]);
    	printf(", ��m: %d\n", mid+1);
    	
    	if(data[mid] == search)
    	{
        	printf("�j�M�Ʀr�b��%d�Ӧ�m", mid+1);
        	break;
    	}
    	else if(data[mid] > search)
        	high = mid - 1;
    	else if(data[mid] < search)
        	low = mid + 1;
	}
return 0;
}
