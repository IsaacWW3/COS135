#include<stdio.h>
/*
 *Student: Isaac Worcester
 *Description: A short program that takes one charater as an input and outputs whether it is a constant or vowel
 *
 */
int main()
{

	char ch; // Declare variable c as character
	
	while (ch != '#'){ // While loop takes input over and over until # is entered

	printf("Enter a letter: \n");
	scanf(" %c", &ch); // Takes the input for character

	if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I'
		|| ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U') // checks if it is a vowel
	{
		printf("%c is a vowel\n", ch); // prints character is a vowel 
	} else if (ch == '#') {
		printf("Goodbye!\n");
		break;
	} else	
	{
		printf("%c is a constant\n", ch); // prints character is a constant
	}
	}


	return 0;
}
