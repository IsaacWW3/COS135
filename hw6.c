#include <stdio.h>
#include <ctype.h>

int main()
{	
	//Declaring important variables at the top
	int num;
	int sum = 0;
	
	//Print for taking user input
	printf("Enter a number larger than 1: \n");
	
	if (scanf("%d", &num)) // This if statement is formatted like this so it has to take a int as an input
       	{
		for (int i = 1; i <= num; i++) // For loop to iterate through every number between i and num
		{
			if (i%2 == 0) // checks if i is even
			{
				sum = sum + i; // Calculates total sum by adding i to sum
			}
		}
		printf("The total is %d\n", sum); // Prints the sum of every even number
	} else
		printf("Error: Incorrect input"); // This prints if the user inputs a character

	return 0;
}
