#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t x = 255;
    x = x + 1;
    printf("%u\n", x);  
    uint8_t b = 0;
    b = b - 1;
    printf("%u\n", b);  
    int8_t y = 127;
    y = y + 1;
    printf("%u\n", y); 
    return 0;
}