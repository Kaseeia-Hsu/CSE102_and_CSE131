#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main()
{
	srand(time(NULL));
	int arr[10];
	int arr2[10]={9,8,7,6,5,4,3,2,1,0};
	int i, j, k, random;
	
	for(i=0; i<=9; i++){
		random = rand() %100 +1;
		arr[i]= random;
	}
	
	
	for(i=0; i<=8; i++){
		
		j = arr[i]*arr2[i];
		k = arr2[i] -1;
		printf("%dx^%d", j, k);
		if(k>1){
			printf("+");
		}
	}

	return 0;
}
