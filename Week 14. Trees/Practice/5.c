#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct character{
	char name[100];
	int age;
	int money;
	int debt;
}Ch;

void createCharacter(Ch *ptr, char NAME[]){
	ptr->age=rand()%51+10;
	ptr->debt=rand()%150001+150000;
	ptr->money=rand()%50001+50000;
	strcpy(ptr->name, NAME);
}

int main(){
	srand(time(NULL));
	Ch newone;
	char NAME[100];
	
	printf("Enter Your Name:");
	gets(NAME);
	
	createCharacter(&newone, NAME);
	
	printf("Name: %s", newone.name);
	printf("\nAge: %d", newone.age);
	printf("\nMoney: %d", newone.money);
	printf("\nDebt: %d", newone.debt);
	
	return 0;
}
