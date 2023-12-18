#include "monty.h"

int execute_file(const char *file_path) {
    FILE *file;
    stack_t *stack = NULL;
    char *opcode, *arg;
    int value, line_number;
    char line[100];

    file = fopen(file_path, "r");
    if (!file) {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        return EXIT_FAILURE;
    }

    line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;

        opcode = strtok(line, " \t\n");
        if (!opcode || *opcode == '#')
            continue;

        if (strcmp(opcode, "push") == 0) {
            arg = strtok(NULL, " \t\n");
            if (!arg) {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                fclose(file);
                return EXIT_FAILURE;
            }
            value = atoi(arg);
            push(&stack, value, line_number);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack, line_number);
        } else {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            return EXIT_FAILURE;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    return execute_file(argv[1]);
}
