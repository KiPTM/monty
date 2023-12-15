#include "monty.h"

/* Function to add the top two elements of the stack */
void f_add(stack_t **head, unsigned int number) {
    if (*head == NULL || (*head)->next == NULL) {
        fprintf(stderr, "L%d: can't add, stack too short\n", number);
        exit(EXIT_FAILURE);
    }
    (*head)->next->n += (*head)->n;
    f_pop(head, number);
}
