#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

int main(int argc, char *argv[]) {
  char *line;
  int size = 100;
  
  // Allocate memory for 'line'
  line = (char*) calloc(size + 1, sizeof(char));
  if (line == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  // Read input in a loop
  while (fgets(line, size, stdin) != NULL) {
    line[strcspn(line, "\n")] = '\0'; // Remove newline character
    
    // Capture the result of palindrome
    char *result = palindrome(line);
    
    // Print result
    printf("Is the string <%s> a palindrome? %s\n", line, result);
    
    // Free the memory allocated by palindrome()
    free(result);
  }

  // Free the memory allocated for 'line'
  free(line);

  return 0;
}

