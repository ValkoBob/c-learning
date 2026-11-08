#include <stdio.h>

size_t my_strlen(const char *s) {
    size_t len = 0;
    while (*s){
        s++;
        len++;
    }
    return len;
}

int main(void) {
    printf("%zu\n", my_strlen("hello"));   // має бути 5
    printf("%zu\n", my_strlen(""));        // має бути 0
    printf("%zu\n", my_strlen("embedded"));// має бути 8
    return 0;
}