#include "monty.h"

/* Function to print all elements in the stack */
void f_pall(stack_t **head, unsigned int number) {
    (void)number; /* Unused variable */
    while (*head != NULL) {
        printf("%d\n", (*head)->n);
        *head = (*head)->next;
    }
}
