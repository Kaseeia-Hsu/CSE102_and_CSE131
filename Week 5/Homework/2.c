//Dev environment: Dev-C++ 5.11
//B101020021 ®}¤l¸s 

#include <stdio.h>

int main()
{
	int sweet;
	char size;
	printf("Please enter size:");
	scanf("%c", &size);
	printf("Please enter sweetness:");
	scanf("%d", &sweet);
	
	switch(size){
	case 'L': case 'l': case 'E': case 'e': case 'M': case 'm': case 'S': case 's':
		
	//The code block below only runs when the size is under correct value
	
		{
	if(sweet >= 85 && sweet <=100){
		switch(size){
			case 'L': case 'l': case 'E': case 'e':
				printf("The fruit is Premium class");
				break;
			case 'M': case 'm':
				printf("The fruit is Gifted class");
				break;
			case 'S': case 's':
				printf("The fruit is Regular class");
				break;
		}
	}
	else if(sweet >= 60 && sweet < 85){
		switch(size){
			case 'L': case 'l': case 'E': case 'e': case 'M': case 'm':
				printf("The fruit is Gifted class");
				break;
				case 'S': case 's':
				printf("The fruit is Regular class");
				break;	
		}
	}
	else if(sweet >= 40 && sweet < 60)
	printf("The fruit is Regular class");
	
	else if(sweet >= 1 && sweet < 40)
	printf("The fruit is Inferior class");
	
	//The size is correct, but the value for sweetness' not in range
	 
	else
	printf("Wrong Value for Sweetness!");
		}
		break;
	
	//If the size of fruit is wrong, then tells the users that it's not a value in range 
	
	default:
	printf("Wrong Fruit Size!");
	}
return 0;
}
