/*
 * @author Isaac Worcester isaac.worcester@maine.edu
 * @explination  This code sorts items in the file and stores in an array whic then prints out the first and last item in that array
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 100
struct car {
    char make[MAX_LINE_SIZE];
    int model;
    float mpg;
    int cylinders;
    float horsepower;
    float weight;
    char origin[MAX_LINE_SIZE];
};

int compare_cars(const void *a, const void *b) {
    struct car **pa = (struct car **)a;
    struct car **pb = (struct car **)b;

    return (*pa)->mpg - (*pb)->mpg;
}

int main() {
    FILE *fp;
    char line[MAX_LINE_SIZE];
    char *token;
    int num_cars = 0;

    // Open the file for reading
    fp = fopen("cars.csv", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Ignore the header
    fgets(line, MAX_LINE_SIZE, fp);

    // Allocate memory for the first car
    struct car *cars = (struct car *)malloc(sizeof(struct car));
    if (cars == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Read in the data
    while (fgets(line, MAX_LINE_SIZE, fp)) {
        // Expand the array
        num_cars++;
        cars = (struct car *)realloc(cars, num_cars * sizeof(struct car));
        if (cars == NULL) {
            printf("Error allocating memory\n");
            exit(1);
        }

        token = strtok(line, ",");
        strcpy(cars[num_cars - 1].make, token);

	token = strtok(NULL, ",");
        cars[num_cars - 1].mpg = atof(token);

        token = strtok(NULL, ",");
        cars[num_cars - 1].cylinders = atoi(token);

        token = strtok(NULL, ",");
        cars[num_cars - 1].horsepower = atof(token);
        
	token = strtok(NULL, ",");
        cars[num_cars - 1].weight = atof(token);

	token = strtok(NULL, ",");
        cars[num_cars - 1].model = atoi(token);
        
        token = strtok(NULL, ",");
        strcpy(cars[num_cars - 1].origin, token);
    }

    // Close the file
    fclose(fp);

    // Allocate an array of pointers to cars
    struct car **car_ptrs = (struct car **)malloc(num_cars * sizeof(struct car *));
    if (car_ptrs == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    // Initialize the array of pointers
    for (int i = 0; i < num_cars; i++) {
        car_ptrs[i] = &cars[i];
    }

    // Sort the array of pointers by MPG
    qsort(car_ptrs, num_cars, sizeof(struct car *), compare_cars);

    // Print the most and least efficient cars
    printf("Most efficient car: %s\nModel:  %d MPG: %.2f Cylanders: %d Horsepower: %.2f Weight: %.2f Origin: %s\n", 
		    car_ptrs[num_cars - 1]->make, car_ptrs[num_cars - 1]->model, car_ptrs[num_cars - 1]->mpg, 
		    car_ptrs[num_cars - 1]->cylinders, car_ptrs[num_cars - 1]->horsepower,
		    car_ptrs[num_cars - 1]->weight, car_ptrs[num_cars - 1]->origin);
   
    printf("Least efficient car: %s\nModel: %d MPG: %.2f Cylanders: %d Horsepower: %.2f Weight: %.2f Origin: %s\n", 
		    car_ptrs[1]->make, car_ptrs[1]->model, car_ptrs[1]->mpg, car_ptrs[1]->cylinders, car_ptrs[1]->horsepower,
		    car_ptrs[1]->weight, car_ptrs[1]->origin);
   
   }
