#include <stdio.h>

int main(void){
    int arr[5] = {10, 20, 30, 40, 50};
    size_t len = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }

    int *p = arr;
    for (size_t i = 0; i < len; i++) {
        printf("arr[%zu] = %d, addr = %p\n", i, *(p + i), (void *)&arr[i]);
    }
    printf("sizeof(arr) = %zu\n", sizeof(arr));
    printf("sizeof(p)   = %zu\n", sizeof(p));

    printf("arr = %p, &arr[0] = %p, p = %p\n", (void *)arr, (void *)&arr[0], (void *)p);
    return 0;
}