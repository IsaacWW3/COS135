#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int find_lowest(int numbers[])
{
	int lowest_index = 0;
	for (int i = 0;i<200;i++)
	{
		if(numbers[i] < numbers[lowest_index])
			lowest_index = i;

	}
	return lowest_index;
}

int find_highest(int numbers[])
{
	int highest_index = 0;
	for (int i = 0;i<200;i++)
	{
		if(numbers[i] > numbers[highest_index])
			highest_index = i;
	}
	return highest_index;
}
int main()
{
	int numbers[200];
	srand(time(0));	
	for (int i = 0; i < 200; i++)
	{
		numbers[i] = (rand() % (999-1));
	}
	int a = find_lowest(numbers);
	int b = find_highest(numbers);
	
	printf("Lowest number is %d at index %d\n", numbers[a], a);
	printf("Highest number is %d at index %d\n", numbers[b], b);
	return 0;
}
