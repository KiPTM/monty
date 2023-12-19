#include "monty.h"

/**
 * pall - Prints all the values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file (unused parameter)
 *
 * Description: This function prints all the values on the stack,
 * starting from the top of the stack.
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current;
	(void) line_number;
	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
