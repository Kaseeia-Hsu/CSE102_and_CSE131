#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main()
{
	srand(time(NULL));
	int arr[10];
	int i, random, sum;
	
	for(i=0; i<=9; i++){
		random = rand() %100 +1;
		sum=0;
		arr[i]= random;
		sum += arr[i];
	}
	
	printf("�[�`��:%d\n", sum);
	printf("������:%d",sum/10);
	
	return 0;
}
