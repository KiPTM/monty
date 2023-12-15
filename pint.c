#include "monty.h"

/* Function to print the top element in the stack */
void f_pint(stack_t **head, unsigned int number) {
    if (*head == NULL) {
        fprintf(stderr, "L%d: cannot pint, stack empty\n", number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}
