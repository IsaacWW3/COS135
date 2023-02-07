#include<stdio.h>

int main()
{
	//Alpha
	printf("%-10s %-10s %-10s\n", "Country", "Region", "Population (M)");
	printf("----------------------------------- \n");
	printf("%-10s %-10s %-10s\n", "USA", "America", "332");
	printf("%-10s %-10s %-10s\n", "Japan", "Asia", "126");
	printf("%-10s %-10s %-10s\n", "France", "Europe", "68");
        printf("%-10s %-10s %-10s\n\n", "China", "Asia", "33");
	//Bravo
	char chr = 78;
	printf("Character having ASCII value 78 is %c\n\n", chr);
	//Charlie
	int i_number = 12;
	float f_number = 3.125;
	double d_number = 7.5345345;
	char character = 'T';
	char text[] = "COS 135";
	printf("%d %f %f %c %s\n\n", i_number, f_number, d_number, character, text);

	return 0;
}
