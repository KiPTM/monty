#include "monty.h"
#include <stdio.h>

/**
 * swap - Swaps the top two elements of the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 *
 * Description: This function swaps the positions of the top two elements
 * of the stack.
 */
void swap(stack_t **stack, unsigned int line_number) {
    stack_t *top = *stack;
    
    if (top == NULL || top->next == NULL) {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    *stack = top->next;
    top->prev = top->next;
    top->next = (*stack)->next;

    if ((*stack)->next != NULL) {
        (*stack)->next->prev = top;
    }

    (*stack)->next = top;
    top->prev = NULL;
}
