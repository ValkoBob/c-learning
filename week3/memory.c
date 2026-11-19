#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int *make_array(size_t n) {
    int *p = malloc(n * sizeof(int));
    if (p == NULL) {
        return NULL;
    }

    for(size_t i = 0; i < n; i++) {
        p[i] = i;
    }

    return p;
}

int main(void) {
    size_t n = 5;
    int *arr = make_array(n);
    if (arr == NULL) {
        printf("out of memory\n");
        return 1;
    }
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = NULL;
    return 0;
}