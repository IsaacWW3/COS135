#include<stdio.h>
/*
 * Student: Isaac Worcester
 * Description: Takes a user input for name, number of chocolate and number of toffee and calculates if discounts are needed and provides an output with the total cost for the user
 */

int main()
{
	// Declaring all important variables to start 
	char f_name[30]; //First name variable
	double bag_choc_cost = 15.50; // Constant cost of bag of chocolate cost
	double bag_toff_cost = 6.90; // Constant cost of bag of toffee
	int num_of_choc; // number of bags of chocolate
	int num_of_toff; // number of bags of toffee

	printf("Enter customer name: \n"); // Customer name input
	scanf("%s", f_name);

	printf("Enter amount of chocolate bags: \n"); // Num of choc bags input
	scanf(" %d", &num_of_choc);

	printf("Enter amount of toffee bags: \n"); // Num of toffee bags input
	scanf(" %d", &num_of_toff);

	
	double choc_tot_cost = num_of_choc * bag_choc_cost; // Total chocolate cost before discount
	double toff_tot_cost = num_of_toff * bag_toff_cost; // total toff cost before discount
	
	double discount_choc = choc_tot_cost - (choc_tot_cost * .1); // Discount for choc
	double discount_toff = toff_tot_cost - (toff_tot_cost * .1); // Discount for Toff

	// giant if check for all values and proper outputs
	if (num_of_choc >=5 && num_of_toff >= 2) {
		double grand_tot = discount_toff + discount_choc;
		if (grand_tot > 100) {
			double discount_grand_tot = grand_tot - (grand_tot * .1);	
		}
	} else if (num_of_choc >= 5 && num_of_toff < 2) {
		double grand_tot = toff_tot_cost + discount_choc;
		if (grand_tot > 100) {
			double discount_grand_tot = grand_tot - (grand_tot * .1);		
		}
	} else if (num_of_choc < 5 && num_of_toff >= 2) {
		double grand_tot = discount_toff + choc_tot_cost;
		if (grand_tot > 100) {
			double discount_grand_tot = grand_tot - (grand_tot * .1);
		}
	} else {
		double grand_tot = choc_tot_cost + toff_tot_cost;
		if (grand_tot > 100) {
			double discount_grand_tot = grand_tot - (grand_tot * .1);
	}
	}

	printf("%20s %s\n","Hello,", f_name);
	printf("%-20s x%-10d $%.2lf\n", "Chocolates", num_of_choc, choc_tot_cost);
	printf("%20s %19.2lf\n\n", "After discount", discount_choc);
	printf("%-20s x%-10d $%.2lf\n", "Toffies", num_of_toff, toff_tot_cost);
	printf("%20s %19.2lf\n\n", "After discount", discount_toff);
	printf("%20s %10.2lf\n", "Total", grand_tot);
	printf("%20s %10.2lf\n\n", "After discount", discount_grand_total);
	printf("%20s %10.2lf\n", "You owe", discount_grand_total);
	printf("%20s\n", "Thank you!");




	return 0;
}
