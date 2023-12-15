#include "monty.h"

/* Function to swap the top two elements of the stack */
void f_swap(stack_t **head, unsigned int number) {
    if (*head == NULL || (*head)->next == NULL) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", number);
        exit(EXIT_FAILURE);
    }
    int temp = (*head)->n;
    (*head)->n = (*head)->next->n;
    (*head)->next->n = temp;
}
