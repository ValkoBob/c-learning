#ifndef BITS_H
#define BITS_H

#include <stdint.h>

void set_bit(uint8_t *value, int n);
void clear_bit(uint8_t *value, int n);
void toggle_bit(uint8_t *value, int n);
int  check_bit(uint8_t value, int n);
void print_binary(uint8_t value);

#endif