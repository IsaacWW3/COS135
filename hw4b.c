#include <stdio.h>

int main()
{
	// This section is where most varaibles are delcared
	char f_name[30];
	char l_name[30];
	int s_grade0;
	int s_grade1;
	int s_grade2;
	int s_grade3;
	char s_code0;
	char s_code1;
	char s_code2;
	char s_code3;

	// This prints and takes an input for the user's first name
	printf("Enter the students name: \n");

	scanf("%s", f_name);

	//This prints and takes an input for the user's last name
	printf("\nEnter the students last name: \n");

	scanf("%s", l_name);

	// This prints and takes user input for the class code and class grade
	printf("\nEnter class code 1 and then class grade: ");
	
	scanf(" %c %d", &s_code0, &s_grade0); 

	printf("\nEnter class code 2 and then class grade: ");

	scanf(" %c %d", &s_code1, &s_grade1);

	printf("\nEnter class code 3 and then enter class grade: ");

	scanf(" %c %d", &s_code2, &s_grade2);

	printf("\nEnter class code 4 and then enter class grade: ");

	scanf(" %c %d", &s_code3, &s_grade3);

	// Prints the final grades for the user's first name variable
	printf("\nFinal grades for %s, %s", f_name, l_name);
	
	// This calculates the total grade number
	int s_tot_grade = s_grade0 + s_grade1 + s_grade2 + s_grade3;
	// This prints the 4 characters from the user input for the class code with the total grade calculated
	printf("\nTotal for %c%c%c%c: %d\n",s_code0, s_code1, s_code2, s_code3, s_tot_grade);
	
	// This calculates average grade from total grade variable
	float avg = s_tot_grade / 4;
	// This prints the average with two numbers after two decimals
	printf("\nAverage: %.2f", avg);

	// This runs a check to see if the average matches a number grade and then prints the respective grade
	if (avg >= 90)
	{
		printf("\nGrade: A\n");
	} else if (avg >= 80 && avg < 90) {
		printf("\nGrade: B\n");
	} else if (avg >= 70 && avg < 80) {
		printf("\nGrade: C\n");
	} else {
		printf("\nGrade: F\n");
	}

	return 0;
}
