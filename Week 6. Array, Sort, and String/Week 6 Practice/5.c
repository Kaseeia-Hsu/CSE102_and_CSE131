#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr1[2][3];
	int arr2[3][2];
	int i, j, temp;

	
	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("Please enter a number:");
			scanf("%d", &arr1[i][j]);
		}
	}

	for(j=0; j<3; j++){
		for(i=0; i<2; i++){
			temp = arr2[j][i];
			arr2[j][i] = arr1[i][j];
			arr1[i][j] = temp;
			printf("%3d", arr2[j][i]);
		}
		printf("\n");
	}
	return 0;
}
