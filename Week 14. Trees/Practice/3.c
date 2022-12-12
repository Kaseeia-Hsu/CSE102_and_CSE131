#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	int grade;
	char name[100];
}DATA;

int main(){
	DATA structArray[3];
	int i;
	
	for(i=0; i<3; i++){
		printf("Enter your math grade:");
		scanf("%d", &structArray[i].grade);
		getchar();
		printf("Enter your name:");
		gets(structArray[i].name);
	}
	
	printf("\n\n");
	
	for(i=0; i<3; i++){
		printf("---------------\n");
		printf("Name:%s\n", structArray[i].name);
		printf("Score:%d\n", structArray[i].grade);
	}
	printf("---------------\n");
			
	return 0;
}
