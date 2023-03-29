#include <stdio.h>

int main()
{
	// Declaring variables 
	int num;
	int term1 = 0, term2 = 1;

	// Taking user input
	printf("Enter a number: \n");
	scanf("%d", &num);

	// Verify the user input is positive number
	if (num >= 1) 
	{
		// Print statement for initial values
		printf("Fibonacci series: %d, %d, ", term1, term2);

		// Declring next term value
		int nextTerm = term1 + term2;

		// While loop iterates until nextTerm equals the user entered value
		while (nextTerm <= num)
		{
			printf("%d, ", nextTerm);
			term1 = term2;
			term2 = nextTerm;
			nextTerm = term1 + term2;

		}
		printf("\n"); // Makes sure there is a indent after the loop
	} else //  This else says enter a valid input if the user does not enter a value above one
		printf("Enter a valid input\n"); 




	return 0;
}
