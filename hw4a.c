#include <stdio.h>

//hw4a is a program that will be taking a user input for tempature 
//and then converting it celcious

//Programmed by: Isaac Worcester

int main()
{
	float fahren;
	printf("Enter the tempature in Fahrenheit: ");

	scanf("%f", &fahren);
	
	float cel = (fahren - 32) / 1.8;
	
	printf("The tempature in Celsius %.3f C \n", cel); 
	
	return 0;
}
