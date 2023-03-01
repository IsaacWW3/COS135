#include<stdio.h>
/*
 *Student: Isaac Worcester
 *Description: A short program designed to take 3 numbers and check if one of the numbers is repeated
 */
int main()
{
	// delcaring variables for inputs
	int f_input; // First input var
	int s_input; // Second input var
	int t_input; // Third input var

	// prints enter enter number and uses scanf to take the user's input for an integer
	printf("Enter first number: \n");
	scanf(" %i", & f_input); // First number input
	printf("Enter second number: \n");
	scanf(" %i", &s_input); // Second number input
	printf("Enter third number: \n");
	scanf(" %i", &t_input); // Third number input
	
	if(f_input == s_input) // If first input is equal to second input print value = first input
	{
		printf("Value: %d\n", f_input);
	} else if (f_input == t_input) // If first input is equal to third input print value = first input
	{
		printf("Value: %d\n", f_input);
	} else if (s_input == t_input) // If second input is equal to third input print value = second input
	{
		printf("Value %d\n", s_input);
	} else // If none of the above is true it will print Value: Error
	{
		printf("Value: Error\n");
	}

	return 0;
}
