#include <stdio.h>

int main()
{
	int num;
	printf("�п�J�@�Ӿ�Ʀr(0~100):");
	scanf("%d", &num);
	
	if(num>=0 && num<=33){
		printf("���B��");
}
	if(num<72 && num>33){
		printf("GG�F");
}
		
	if(num>=72 && num<=100){
		printf("���B��");
}
	
	if(num>100 || num<0){
		printf("��J���Ȥ��b�d��A�Э��s��J");
}
	return 0;
 } 
