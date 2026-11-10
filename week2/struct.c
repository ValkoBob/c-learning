#include <stdio.h>
#include <stdint.h>

typedef struct {
    float temperature;
    uint16_t id;
    uint8_t humidity;
} sensor_reading_t;

void print_reading(const sensor_reading_t *r) {
    printf("id = %u, temperature = %.1f, humidity = %u\n", r->id, r->temperature, r->humidity);
}

void update_reading(sensor_reading_t *r, float t, uint8_t h) {
    r->temperature = t;
    r->humidity = h;
}

int main(void) {
    sensor_reading_t r = {
        .id = 7,
        .temperature = 23.5f,
        .humidity = 41,
    };

    printf("r = %zu\n", sizeof(r));
    printf("sizeof = %zu\n", sizeof(sensor_reading_t));
    print_reading(&r);
    update_reading(&r, 25.1f, 42);
    print_reading(&r);
    return 0;
}