// Author: Isaac Worcester
//Program prints all elements in a stack
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print(const char *stack, const int size) {
    
    if (size == 0) return;

    printf("current stack elements: ");
    for (int i = 0; i < size; i++) {
        printf("%c ", *(stack+i));
    }
    
    printf("\n");
    
}

void shiftright(char *stack, int size) {
    
    for (int i = (size-1); i > 0; i--) {
        *(stack + i) = *(stack + i - 1);
    }
    
}


void shiftleft(char *stack, int size) {
    
    for (int i = 0; i < size; i++) {
        *(stack + i) = *(stack + i + 1);
    }
    
}


char pop(char **stack, int *size) {
    
    if (*size == 0) {
        printf("Error: The stack is empty.\n");
        return '_';
    }
    //if it is the last element, free  memory
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
    
    return 0;L
    
}

void push(char n, char **stack, int *size) {
    
    if (*size == 0) {
        ++*size; // increment size by 1
        *stack = (char *) malloc(*size); // allocate new memory
        **stack = n;
    }
    else if (*size >= 1) {
        ++*size; 
        *stack = realloc(*stack, *size);
        shiftright(*stack, *size);
        
        **stack = n;
    }
    
    
    return;
}

int main() {
    
    char buffer[100];
    
    int size = 0;
    
    char* stack;
    
    printf("Enter a phrase: ");
    
    fgets(buffer, 100, stdin);
    int input = strlen(buffer) - 1;
    
    for (int i = 0; i < input; i++)
        push(buffer[i], &stack, &size);
    
    printf("Reversed output is \"");
    
    for (int i = 0; i < input; i++)
	 printf("%c", pop(&stack, &size));

    printf("\"\n");
    
    return 0;
    
}
