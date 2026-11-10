#include <stdio.h>
#include <stdint.h>

void print_binary(uint8_t value){
    for (int i = 7; i >= 0; i--) {
        if(value & (1U << i)) {
            printf("1");
        } else {
            printf("0");
        }
        if (i == 4) {
            putchar(' ');
        }
    }
    putchar('\n');
}

// увімкнути біт n
void set_bit(uint8_t *value, int n) { // |= (1 << n)
    *value |= (1U << n);
}
// вимкнути біт n
void clear_bit(uint8_t *value, int n) { // &= ~(1 << n)
    *value &= ~(1U << n);
}
// перемкнути біт n
void toggle_bit(uint8_t *value, int n){ // ^= (1 << n)
    *value ^= (1U << n);
}
// повернути 1, якщо біт увімкнений, інакше 0
int check_bit(uint8_t value, int n){ // & (1 << n)
    return (value >> n) & 1U;
}

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