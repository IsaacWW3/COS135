/**
 * Implementation of FIFO queue - Assignment 9 - a
 * The code demonstrates push, print, and quit functions and dynamically allocates array elements in the beginning.
 *
 * @note This is only one way of doing it and it is not a must to use this example in your program.
 *
 * @author Nimesha Ranasinghe (r.ranasinghe@maine.edu)
 *
 *
 * Compile:
 *  gcc -g -Wall A9_a_fifo.c -o fifo
 *
 * Run:
 *  ./fifo
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief  print all the elements in the queue
 * @note
 * @param  *arr: reference to the queue
 * @param  size: current length of the queue (size > 0)
 * @retval None
 */
void print_queue(int *arr, int size)
{
    for(int i=0; i < size; i++)
        printf("%d, ", *(arr+i));
    printf("\b\b  \n");  // delete the last ,
}

/**
 * @brief  shift all the elements in the queue to right
 * @note
 * @param  *arr: reference to the queue
 * @param  size: current length of the queue (size > 0)
 * @retval None
 */
void shift_right(int *arr, int size)
{
    for(int i = size-1; i > 0; i--)
        *(arr+i) = *(arr+i-1);
}

int main(int argc, char *argv[])
{
	char cmd[6] = " ";
	int n = 0, size = 0, n_elements = 0;
	int* arr = NULL;
    
    if( argc == 2 ) {
        size = atoi(argv[1]); // convert to int from char array
        arr = (int*) malloc(size * sizeof(int)); // allocate memory
    }
    else {
        printf("Expect queue size as a program argument (e.g., ./fifo  5)");
        return 0;
    }

	while(strcmp(cmd, "quit")) // exit from the program when user enters a #
	{
		printf("Enter command (push, print, or quit): ");
		scanf("%s", cmd);
        
        if(!strcmp(cmd, "push")) {
            if(scanf("%d", &n) == 1) { // read a number
                if (n_elements == size) // handle overflow
                    printf("Overflow: %d\n", *(arr+n_elements-1));
                n_elements++;
                // shift all the elements to right
                shift_right(arr, size);
                // apend the new element in the beginning
                *arr = n;
            }
        }
        else if(!strcmp(cmd, "print")) {
            print_queue(arr, size);
        }
        else
            if(strcmp(cmd, "quit"))
                printf("Only accept \"push\", \"print\", or \"quit\" commands\n");

	}
	return 0;
}
