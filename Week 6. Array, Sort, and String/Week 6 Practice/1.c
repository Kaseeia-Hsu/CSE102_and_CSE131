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
		printf("��%d�ӼƦr��: %d\n", i+1, random);
	}
	return 0;
}
