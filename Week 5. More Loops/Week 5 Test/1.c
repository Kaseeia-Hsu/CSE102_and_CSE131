 #include <stdio.h>
 
 int main()
 {
 	int num, i, j;
 	printf("�п�J�@�ӼƦr:");
 	scanf("%d",&num);
 	
 	for(i=1; i<=num; ++i){
 		j *= i;
	 }
	 printf("%d! = %d", num, j);
	 
	 return 0;
 }
