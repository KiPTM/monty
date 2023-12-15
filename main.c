#include "monty.h"

/* Function prototypes */
int execute(FILE *file);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    int exit_status = execute(file);

    fclose(file);
    return exit_status;
}

int execute(FILE *file) {
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1) {
        line_number++;
        char *opcode = strtok(line, " \n");
        
        if (opcode == NULL || opcode[0] == '#') {
            continue; /* Ignore comments or empty lines */
        }

        /* Find the function pointer associated with the opcode */
        int found = 0;
        for (int i = 0; i < num_opcodes; i++) {
            if (strcmp(opcode, opcodes[i].opcode) == 0) {
                opcodes[i].f(&stack, line_number);
                found = 1;
                break;
            }
        }

        if (!found) {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            free(line);
            free_stack(stack);
            return EXIT_FAILURE;
        }
    }

    free(line);
    free_stack(stack);
    return EXIT_SUCCESS;
}
