#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char array[5]={'a', 'b', 'c', 'd', 'e'};
	char * ptr=array;
	
	printf("�}�C�@���Ȭ�:%c\n", *ptr);
	printf("�}�C�@����}��:%p\n", &array[0]);
	printf("���Ф@���V����}��:%p\n", ptr);
	printf("*���Ф@����}��:%p\n\n", &ptr);
	
	printf("�}�C2���Ȭ�:%c\n", *ptr+1);
	printf("�}�C2����}��:%p\n", &array[1]);
	printf("���Ф@���V����}��:%p\n", ptr+1);
	printf("*���Ф@����}��:%p\n\n", &ptr);
	
	printf("�}�C3���Ȭ�:%c\n", *ptr+2);
	printf("�}�C3����}��:%p\n", &array[2]);
	printf("���Ф@���V����}��:%p\n", ptr+2);
	printf("*���Ф@����}��:%p\n\n", &ptr);
	
	printf("�}�C4���Ȭ�:%c\n", *ptr+3);
	printf("�}�C4����}��:%p\n", &array[3]);
	printf("���Ф@���V����}��:%p\n", ptr+3);
	printf("*���Ф@����}��:%p\n\n", &ptr);
	
	printf("�}�C5���Ȭ�:%c\n", *ptr+4);
	printf("�}�C5����}��:%p\n", &array[4]);
	printf("���Ф@���V����}��:%p\n", ptr+4);
	printf("*���Ф@����}��:%p\n\n", &ptr);
	
	return 0;
}
