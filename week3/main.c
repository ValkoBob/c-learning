#include <stdio.h>
#include <stdint.h>
#include "bits.h"

int main(void) {
    uint8_t num = 5;
    print_binary(num);    // 0000 0101
    print_binary(0x0F);   // 0000 1111
    print_binary(0x80);   // 1000 0000
    print_binary(0xA5);   // 1010 0101
    print_binary(255);    // 1111 1111

    uint8_t x = 0;
    print_binary(x);       // 0000 0000

    set_bit(&x, 0);
    set_bit(&x, 3);
    print_binary(x);       // 0000 1001

    toggle_bit(&x, 7);
    print_binary(x);       // 1000 1001

    clear_bit(&x, 0);
    print_binary(x);       // 1000 1000

    printf("bit 3: %d\n", check_bit(x, 3));   // 1
    printf("bit 1: %d\n", check_bit(x, 1));   // 0
    return 0;
}