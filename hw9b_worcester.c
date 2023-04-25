/**
 * Implementation of stack commands.
 * The code demonstrates push, pop, and print functions and dynamically allocates array elements when requires. 
 *
 * @note This is only one way of doing it and it is not a must to use this example in your program.
 *
 * @author Nimesha Ranasinghe (r.ranasinghe@maine.edu)
 *
 *
 * Compile:
 *  gcc -g -Wall A9_b_stack.c -o stack_demo
 *
 * Run:
 *  ./stack_demo
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * @brief  print all the elements in the stach
 * @note   passing the pointer to stack as a read-only by using const char *stack (same for size)
 * @param  *stack: Reference to the stack
 * @param  size: current length of the stack (size > 0)
 * @retval None
 */
void printstack(const char *stack, const int size) {
    
    if (size == 0) return; //nothing to print

    //printf("current stack elements: ");
    for (int i = 0; i < size; i++) {
        printf("%c\n", *(stack+i));
    }
    
}

/**
 * @brief  shift all the stack elements to right before push a new element
 * @note
 * @param  *stack: Reference to the stack
 * @param  size: current length of the stack (size > 0)
 * @retval None
 */
void shiftright(char *stack, int size) {
    
    for (int i = (size-1); i > 0; i--) {
        *(stack + i) = *(stack + i - 1);
    }
    
}

/**
 * @brief  shift all the stack elements to left after pop
 * @note
 * @param  *stack: Reference to the stack
 * @param  size: current length of the stack (size > 0)
 * @retval None
 */
void shiftleft(char *stack, int size) {
    
    for (int i = 0; i < size; i++) {
        *(stack + i) = *(stack + i + 1);
    }
    
}

/**
 * @brief  pop the top element from the stack (from beginning)
 * @note   if the stack is empty, returns a '_'
 * @param  **stack: Reference to the stack (double pointer)
 * @param  *size: pointer to the size variable defined in main() function
 * @retval character popped from the stack (first element)
 */
char pop(char **stack, int *size) {
    
    if (*size == 0) {
        printf("Error: The stack is empty.\n");
        return '_';
    }
    //if it is the last element, pop it and free the memory
    else if (*size == 1) {
        char ch = **stack;
        free(*stack);
        *stack = NULL;
        --*size; // reduce size by 1
        return ch;
        
    }
    //pop the first element, shift all to the left, remove one element
    else if (*size > 1) {
        char ch = **stack;
        shiftleft(*stack, *size);
        --*size; // reduce size by 1
        *stack = realloc(*stack, *size);
        return ch;
    }
    
    // this return will reach if only there is an unexpected error
    // you may handle this in the main function
    return 0; // return NULL
    
}

/**
 * @brief  insert/push a new element to the top of the stack (from beginning)
 * @note   if the stack is empty, create a new memory; else add more memory
 * @param  **stack: Reference to the stack (double pointer)
 * @param  *size: pointer to the size variable defined in main() function
 * @retval None
 */
void push(char new_value, char **stack, int *size) {
    
    if (*size == 0) {
        ++*size; // increment size by 1
        *stack = (char *) malloc(*size); // allocate new memory
        **stack = new_value;
    }
    // increase the size of memory, shift everything to the right,
    // assign the new value to the first element
    else if (*size >= 1) {
        ++*size; // increment size by 1
        *stack = realloc(*stack, *size);
        shiftright(*stack, *size);
        
        **stack = new_value;
    }
    
    printf("pushed: %c\n", new_value);
    
    return;
}

/**
 * @brief  COS135 assignment 9 stack  example
 * @note   This is only a demonstration of basic functions of a stack
 * @retval 0 if the program terminates without errors
 */
int main() {
    
    char buffer[100];
    
    int size = 0; // maintain the size of the stack
    
    // create a reference to the char stack (no memory is allocated yet)
    // dynamic memory will be allocated in the push() function when required
    char* stack;
    
    printf("Enter command (push, pop, print, or quit): ");
    
    // read one line at a time and process
    while (fgets(buffer, 100, stdin)) {

        //remove newline character at the end of each line
        char *newbuf = strtok(buffer, "\n");
        
        // split data using comma separator
        char* value = strtok(newbuf, " ");
        
        if (!strcmp(value, "push")) {
            value = strtok(NULL, " ");
            
            if( ((value[0] >= 'A') && (value[0] <= 'Z')) || ((value[0] >= 'a') && (value[0] <= 'z')) )
                push(value[0], &stack, &size);
            else {
                printf("Accepting only alphabetical characters.\n");
            }
                
        }
        if (!strcmp(value, "pop")) {
            printf("popped: %c\n", pop(&stack, &size));
        }
        if (!strcmp(value, "print")) {
            printstack(stack, size);
        }
        if (!strcmp(value, "quit")) {
            printf("Bye\n");
            exit(0);
        }

        printf("Enter command (push, pop, print, or quit): ");
    }
    
    return 0;
    
}
