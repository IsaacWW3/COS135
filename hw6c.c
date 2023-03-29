#include <stdio.h>

int nat_up(int n)
{
	printf("\nAll natrual numbers from 1 to %d are: ", n);
	for (int i=0;i<n;i++) // Print all numbers from 1 to n
	{
		printf("%d ", i);
	}
}

int nat_down(int n)
{
	printf("\nAll natural numbers from %d to 1 are: ", n);
	for (int i=n;i>=1;i--) // prints all natural numbers in reverse
	{
		printf("%d ", i); 
	}
}

int all_even(int n)
{
	printf("\nAll even numbers from 1 to %d are: ", n);
	for (int i=1;i<=n;i++)
	{
		if (i%2==0) // checks if it is even
			printf("%d ", i);
	}
}

int all_odd(int n)
{
	printf("\n All odd number from 1 to %d are: ", n);

	for (int i=1;i<=n;i++) // iterates through 
	{
		if (i%2==1) // checks if it is odd
			printf("%d ", i);
	}
}

int calc_sum(int n)
{
	printf("\n The sum of all natural numbers between 1 and %d: ", n);
	int sum=0;
	for(int i =1;i<n;i++)
	{
		sum = sum + i; // calculates sum
	}
	printf("%d\n", sum); // prints sum
}


int main()
{
	int user_num; // declare variable
	int i;
	int func1, func2, func3, func4, func5;
	// Takes a number user input (number > 10)
	printf("Enter any number greater than 10: \n"); 
	scanf("%d", &user_num); 

	if (user_num > 10)
	{
		// This is where all the functions are called
		func1 = nat_up(user_num);
		func2 = nat_down(user_num);
		func3 = all_even(user_num);
		func4 = all_odd(user_num);
		func5 = calc_sum(user_num);
	} else
		printf("Enter a number greater than 10\n");




	return 0;
}


