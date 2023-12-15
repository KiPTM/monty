#include "monty.h"

/* Function to remove the top element of the stack */
void f_pop(stack_t **head, unsigned int number) {
    if (*head == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", number);
        exit(EXIT_FAILURE);
    }
    stack_t *temp = *head;
    *head = (*head)->next;
    free(temp);
}
