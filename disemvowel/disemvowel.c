#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char *disemvowel(char *str) {
    if (str == NULL) return NULL; 

    int len = strlen(str);
    int count = 0;

    for (int i = 0; i < len; ++i) {
        char c = str[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            count++;
        }
    }

    char *result = (char *)malloc(count + 1); 
    if (result == NULL) return NULL;


    int j = 0; 
    for (int i = 0; i < len; ++i) {
        char c = str[i];
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' &&
            c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result[j++] = c; 
        }
    }

    result[j] = '\0'; 
    return result;
}
