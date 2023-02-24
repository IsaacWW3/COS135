#include <stdio.h>

int main()
{
	// This is delcaring all main variables
	float mnth_exp_goal;
	float rent;
	float uts;
	float transpo;
	float food_cost;
	float car_payment = 581.99;

	// This section is accepting inputs from the user for the costs
	printf("Enter monthly expense goal (USD): \n");
	scanf("%f", & mnth_exp_goal);

	printf("Enter rent (USD): \n");
	scanf("%f", &rent);

	printf("Enter utilities (USD): \n");
	scanf("%f", &uts);

	printf("Enter transportation (USD): \n");
	scanf("%f", &transpo);

	printf("Enter food costs (USD): \n");
	scanf("%f", &food_cost);

	
	// This part of the code is calculating the amount left over in the budget
	float month_leftover = mnth_exp_goal - rent - uts - transpo - food_cost - car_payment;
	
	// This part calculates the monthly total cost
	float month_tot = rent + uts + transpo + food_cost + car_payment;
	
	// This calculates the percentage of cost for each section
	float p_rent = (rent / month_tot) *  100;
	float p_uts = (uts / month_tot) * 100;
	float p_transpo = ( transpo / month_tot) * 100;
	float p_food_cost = (food_cost / month_tot) * 100;
	float p_car_payment = (car_payment / month_tot) * 100;

	printf("Budget chart for COS135\n");
	printf("%-20s %-20s %-20s\n", "Expense", "Amount $", "Percent %");
	printf("%-20s %-20.2f %-20.2f\n", "Car Payment", car_payment, p_car_payment);
	printf("%-20s %-20.2f %-20.2f\n", "Rent", rent, p_rent);
	printf("%-20s %-20.2f %-20.2f\n", "Utilities", uts, p_uts);
	printf("%-20s %-20.2f %-20.2f\n", "Transportation", transpo, p_transpo);
	printf("%-20s %-20.2f %-20.2f\n", "Food", food_cost, p_food_cost);
	printf("%-20s %-20.2f\n", "Expense Goal", mnth_exp_goal);
	printf("%-20s %-20.2f\n", "Total Expenses", month_tot);
	printf("%-20s %-20.2f\n", "Leftover Amount", month_leftover);

	if (month_leftover > (mnth_exp_goal * .2)) {
		printf("Good job! You are saving enough\n");
	} else {
		printf("Try to save more\n");
	}


	return 0;
}
