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