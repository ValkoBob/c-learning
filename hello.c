#include <stdio.h>

int main(void) {
    int x = 42;
    int *p = &x;
    printf("x = %d, address = %p, via pointer = %d\n", x, (void*)p, *p);
    return 0;
}