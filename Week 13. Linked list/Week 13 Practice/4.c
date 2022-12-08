#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char array[5]={'a', 'b', 'c', 'd', 'e'};
	char * ptr=array;
	
	printf("陣列一的值為:%c\n", *ptr);
	printf("陣列一的位址為:%p\n", &array[0]);
	printf("指標一指向的位址為:%p\n", ptr);
	printf("*指標一的位址為:%p\n\n", &ptr);
	
	printf("陣列2的值為:%c\n", *ptr+1);
	printf("陣列2的位址為:%p\n", &array[1]);
	printf("指標一指向的位址為:%p\n", ptr+1);
	printf("*指標一的位址為:%p\n\n", &ptr);
	
	printf("陣列3的值為:%c\n", *ptr+2);
	printf("陣列3的位址為:%p\n", &array[2]);
	printf("指標一指向的位址為:%p\n", ptr+2);
	printf("*指標一的位址為:%p\n\n", &ptr);
	
	printf("陣列4的值為:%c\n", *ptr+3);
	printf("陣列4的位址為:%p\n", &array[3]);
	printf("指標一指向的位址為:%p\n", ptr+3);
	printf("*指標一的位址為:%p\n\n", &ptr);
	
	printf("陣列5的值為:%c\n", *ptr+4);
	printf("陣列5的位址為:%p\n", &array[4]);
	printf("指標一指向的位址為:%p\n", ptr+4);
	printf("*指標一的位址為:%p\n\n", &ptr);
	
	return 0;
}
