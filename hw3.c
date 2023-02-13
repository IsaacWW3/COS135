#include <stdio.h>

int main()
{
	char store_var[] = "Z store";
	float item1 = 21.45;
	float item2 = 10.00;
	float item3 = 14.90;
	float item4 = 33.50;
	float item_tot = (item1*2) + (item2*2) + (item3*2) + (item4*2);
	float tax = item_tot * 0.1;
	printf("Welcome to the %s\n", store_var);
	printf("Item 1 %.2f x2 %.2f\n", item1, item1*2);
	printf("Item 2 %.2f x2 %.2f\n", item2, item2*2);
	printf("Item 3 %.2f x2 %.2f\n", item3, item3*2);
	printf("Item 4 %.2f x2 %.2f\n", item4, item4*2);
	printf("\n\nItem total: %.2f", item_tot );
	printf("\nGST: %.2f", tax);
	printf("\nTotal: %.2f\n", item_tot+tax);
		


	return 0;
}
