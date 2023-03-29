#include <stdio.h>
#include <stdlib.h>
// Isaac Worcester
// Purpose: To take an input as a password and check if it is valid or not according to certain criteria

int pass_leng(char password[]) // This function checks the length of the password and makes sure its longer than 8 characters
{
	int length;
	for (length = 0; password[length] != '\0';length++)
		if (length > 8)
			return 1;
	return 0;	
}

int pass_upper_lower(char password[]) // This password makes sure there is at least one uppercase and one lowercase var
{
	int boolean1, boolean2; // These are just booleans to check if the password has a capital and lowercase
	for (int i = 0; password[i] != '\0';i++)
	{
		if (password[i] >= 'a' && password[i] <= 'z')
			boolean1 = 1;
		else if (password[i] >= 'A' && password[i] <=  'Z')
			boolean2 = 1;
		if (boolean1 && boolean2)
			return 1;
	}
	return 0;
}


int pass_digit(char password[]) //Checks if the password has a number in it
{
	for (int i = 0; password[i] != '\0';i++)
	{
		if (password[i] >= '0' && password[i] <= '9')
			return 1;
	}
	return 0;
}
int pass_special_char(char password[]) // Checks if the special characters are in the password
{
	for (int i = 0; password[i] != '\0';i++)
	{
		switch(password[i])
		{
			case '@': return 1;
			case '!': return 1;
			case '#': return 1;
			case '$': return 1;
		}
	}
	return 0;
}

void encryption(char password[])
{
	for (int i = 0; password[i] != '\0';i++)
	{
		if ((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9'))
			password[i] += 1;
		else if (password[i] == '@' || password[i] == '#' || password[i] == '!' || password[i] == '$')
			password[i] -= 1;

	}
	//return 0;

}


int main()
{
	char password[128];
	printf("Enter your password: ");
	scanf("%s", password);

	if (pass_leng(password) && pass_upper_lower(password) && pass_digit(password) && pass_special_char(password))
	{
		printf("Valid input\n");
	} else {
		printf("Invalid Password\n");
	}
	encryption(password);

	printf("%s\n", password);
	return 0;
}

