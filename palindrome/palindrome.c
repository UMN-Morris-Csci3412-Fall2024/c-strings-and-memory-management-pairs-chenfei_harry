#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "palindrome.h"

// Helper function to reverse the input string
char *str_reverse(char const *str) {
    int len = strlen(str);
    char *result = (char*) calloc(len + 1, sizeof(char));  // Allocate memory for reversed string

    if (result == NULL) {  // Check if memory allocation failed
        return NULL;
    }

    // Reverse the string
    for (int i = 0; i < len; ++i) {
        result[i] = str[len - i - 1];
    }
    result[len] = '\0';  // Null-terminate the reversed string

    return result;  // Caller must free this memory
}

// Function to check if a string is a palindrome
char *palindrome(char const *str) {
    char *rev = str_reverse(str);  // Reverse the input string
    if (rev == NULL) {  // Check if memory allocation failed
        return NULL;
    }

    bool result = true;
    int i = 0;

    // Check if the original string matches the reversed string
    while (result && str[i]) {
        if (str[i] != rev[i]) {
            result = false;
        }
        ++i;
    }

    free(rev);  // Free the memory allocated by str_reverse()

    // Allocate memory for the result ("Yes" or "No")
    char *answer;
    if (result) {
        answer = (char*) calloc(4, sizeof(char));  // "Yes" requires 4 bytes including the null terminator
        if (answer == NULL) {  // Check if memory allocation failed
            return NULL;
        }
        strcpy(answer, "Yes");
    } else {
        answer = (char*) calloc(3, sizeof(char));  // "No" requires 3 bytes including the null terminator
        if (answer == NULL) {  // Check if memory allocation failed
            return NULL;
        }
        strcpy(answer, "No");
    }

    return answer;  // Caller must free this memory
}


