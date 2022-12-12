#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data{
	int grade;
	char name[100];
}DATA;

int main(){
	DATA student;
	
	printf("Enter your math grade:");
	scanf("%d", &student.grade);
	getchar();
	printf("Enter your name:");
	gets(student.name);
	
	printf("Name:%s\n", student.name);
	printf("Score:%d", student.grade);
	
	return 0;
}
