#include "monty.h"

/* Function to push an element onto the stack */
void push(stack_t **stack, int line_number, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;

    if (*stack == NULL)
    {
        new_node->next = NULL;
        *stack = new_node;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}

/* Function to print all elements in the stack */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
