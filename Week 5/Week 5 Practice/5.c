#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int width, length, l, w;
	srand(time(NULL));
	width = rand() % 10+1;
	length = rand() % 10+1;
	
	printf("ªø:%d ¼e:%d\n", length, width);
	for(l=1; l<= length; l++)
	{
	
	for(w=1; w <= width; w++)
		printf("*");
		printf("\n");
}

return 0;
}
