#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char array[100];
	char *ptr[100];
	int i, len;
	
	printf("¿é¤J¦r¦ê:");
	gets(array);
	
	len=0;
	while(array[len]!=NULL){
		++len;
	}
	for(i=0; i<=len; i++){
		ptr[i]=&array[len-i];
	}
	
	printf("¿é¥X¦r¦ê:");
	for(i=0; i<=len; i++){
		printf("%c", *ptr[i]);
	}
	
	return 0;
}
