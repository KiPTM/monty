/* monty.h */
#ifndef MONTY_H
#define MONTY_H

/* Structs */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void push(stack_t **stack, int value, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
/* Other function prototypes for opcodes */

#endif /* MONTY_H */
