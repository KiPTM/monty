#include "monty.h"

/* Function to execute the opcode operations */
int execute(char *content, stack_t **head, unsigned int counter, FILE *file) {
    char *opcode = strtok(content, " \n");

    if (opcode == NULL || opcode[0] == '#') {
        return EXIT_SUCCESS; // Ignore comments or empty lines
    }

    if (strcmp(opcode, "push") == 0) {
        char *arg = strtok(NULL, " \n");
        if (!arg || !isdigit(*arg)) {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            return EXIT_FAILURE;
        }
        int argument = atoi(arg);
        f_push(head, argument);
    } else if (strcmp(opcode, "pall") == 0) {
        f_pall(head, counter);
    } else if (strcmp(opcode, "pint") == 0) {
        f_pint(head, counter);
    } else if (strcmp(opcode, "pop") == 0) {
        f_pop(head, counter);
    } else if (strcmp(opcode, "swap") == 0) {
        f_swap(head, counter);
    } else if (strcmp(opcode, "add") == 0) {
        f_add(head, counter);
    } else if (strcmp(opcode, "nop") == 0) {
        f_nop(head, counter);
    } // Implement other opcodes similarly
    else {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
