#include <stdio.h>
#include <time.h>
#define SIZE 20

int main()
{
    int search = 0;
    int element = -1;
    int a[SIZE];
    int i, j;
    srand(time(NULL));
    
    printf("數列: ");
    for(i=0; i<SIZE; i++)
    {
	     a[i] = rand() % 15 +1;
	     printf("%d ",a[i]);
	}
	printf("\n");

    
    printf("搜尋數字:");
    scanf("%d", &search);
    printf("\n");
    
    printf("搜尋數字在: ");
    for(j=0;j<SIZE; j++)
    {
        if(a[j] == search)
            printf("%d, ",j+1);
    }
    return 0;
}
