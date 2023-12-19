#include "monty.h"
/**
 * nop - Doesn't do anything
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 *
 * Description: This function does nothing.
 * It's used as an opcode that doesn't perform any operation.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
