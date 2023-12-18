#include "monty.h"
/**
 * pop - Removes the top element of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 *
 * Description: This function removes the top element of the stack.
 * If the stack is empty, it prints an error message and exits with EXIT_FAILURE.
 */
void pop(stack_t **stack, unsigned int line_number) {
    stack_t *temp;

    if (*stack == NULL) {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = temp->next;

    if (*stack != NULL) {
        (*stack)->prev = NULL;
    }

    free(temp);
}
