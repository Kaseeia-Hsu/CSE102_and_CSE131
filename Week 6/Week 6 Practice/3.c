#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main()
{
	srand(time(NULL));
	int arr[10];
	int i, random;
	
	for(i=0; i<=9; i++){
		random = rand() %100 +1;
		arr[i]= random;
	}
	
	int max = arr[0], min = arr[0];
	int maxnum = 0 , minnum = 0;
		
	for(i=0; i<=9; i++){
		
		if(max<arr[i]){
		max=arr[i];
		maxnum += 1;
	}
		if(min>arr[i]){
		min=arr[i];
		minnum += 1;
	}
	}
	
	printf("最大值為第%d個數字, 其值為:%d\n",maxnum+1, max);
	printf("最小值為第%d個數字, 其值為:%d",minnum+1, min);
	

	
	return 0;
}
