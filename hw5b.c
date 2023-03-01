#include<stdio.h>
/*
 * Student: Isaac Worcester
 * Description: A short program designed to take multiple inputs from the user including first name, last name,
 * birth year and preffered salary and print a sentence with all this information back to the user
 */

int main()
{

	// All variables that are taken as user inputs declared
	char f_name[30]; // First name variable
	char l_name[30]; // Last name variable
	int year; // Birth year Variable
	float salary; // Salary variable

	// All inputs are taken here
	printf("New applicants first name: \n");
	scanf(" %s", f_name); // First name input
	printf("New applicants last name: \n");
	scanf(" %s", l_name); // Last name input
	printf("Applicants birth year: \n");
	scanf(" %d", &year); // Birth year input
	printf("Applicants preffered monthly salary: \n");
	scanf(" %f", &salary); // Salary input

	int age = 2023-year; // The age variable here calculates someones age based soley off the year

	// This print f statement prints the user inputs back to the user in a short summery fashion 
	printf("%s %s is %d years old and requests a monthly salary of $%.2f\n",  f_name, l_name, age, salary);


	return 0;
}
