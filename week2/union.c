#include <stdio.h>
#include <stdint.h>

typedef union {
    uint32_t value;
    uint8_t  bytes[4];
} word_t;

int is_little_endian(void) {
    word_t w;
    w.value = 1;
    return w.bytes[0] == 1;
}

int main(void) {
    word_t w;
    w.value = 0x12345678;

    printf("%02X %02X %02X %02X\n", w.bytes[0], w.bytes[1], w.bytes[2], w.bytes[3]);

    w.bytes[0] = 0xEF;
    w.bytes[1] = 0xBE;
    w.bytes[2] = 0xAD;
    w.bytes[3] = 0xDE;
    printf("%08X\n", w.value);
    printf("%zu\n", sizeof(word_t));

    printf("little-endian: %d\n", is_little_endian());

    return 0;
}