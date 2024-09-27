#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
    char *line = NULL;
    size_t size = 100;

    // Allocate initial memory for the line
    line = (char*) malloc(size + 1);

    if (line == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Read each line from stdin and process it
    while (getline(&line, &size, stdin) > 0) {
        char *disemvoweled = disemvowel(line);
        if (disemvoweled != NULL) {
            printf("%s\n", disemvoweled);
            free(disemvoweled); // Free the disemvoweled string after printing
        }
    }

    free(line); // Free the original line buffer
    return 0;
}

