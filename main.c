#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        return EXIT_FAILURE;
    }

    bus.file = fopen(argv[1], "r");
    if (bus.file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;

    while (getline(&line, &len, bus.file) != -1) {
        line_number++;
        bus.content = clean_line(line);

        if (bus.content[0] == '\0') {
            free(bus.content);
            continue;
        }

        if (execute(bus.content, &stack, line_number, bus.file) == EXIT_FAILURE) {
            free(bus.content);
            free_stack(stack);
            fclose(bus.file);
            free(line);
            return EXIT_FAILURE;
        }

        free(bus.content);
    }

    free(line);
    fclose(bus.file);
    free_stack(stack);
    return EXIT_SUCCESS;
}
