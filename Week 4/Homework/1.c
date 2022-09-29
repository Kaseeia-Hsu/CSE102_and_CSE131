//Dev environment: Dev-C++ 5.11

#include <stdio.h>

int main()
{
	float x, y;
	printf("Please enter X cordinate:");
	scanf("%f",&x);
	printf("Please enter Y cordinate:");
	scanf("%f",&y);
	
	//First quadrant(x>0, y>0)
	if(x>0 && y>0)
	printf("point(%f,%f) is in the first quadrant",x, y);
	
	//Second quadrant(x<0, y>0)
	else if(x<0 && y>0)
	printf("point(%f,%f) is in the second quadrant",x, y);
	
	//Third quadrant(x<0, y<0)
	else if(x<0 && y<0)
	printf("point(%f,%f) is in the third quadrant",x, y);
	
	//Fourth quadrant(x>0, y<0)
	else if(x>0 && y<0)
	printf("point(%f,%f) is in the fourth quadrant",x, y);
	
	//Once if x, or y = zero occurs
	else
	printf("point(%f,%f) is not in any quadrant",x, y);
	
	return 0;
}
