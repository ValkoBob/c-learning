#include <stdio.h>
#include <stdint.h>

typedef struct {
    float   temperature;
    uint8_t ready;
    uint8_t error;
    uint8_t mode;
} sensor_data_t;

// Повертає 1, якщо пакет цілий, і 0, якщо контрольна сума не збіглась
int parse_packet(const uint8_t packet[4], sensor_data_t *out) {
    if (packet[3] != (packet[0] ^ packet[1] ^ packet[2])) {
        return 0;
    }
    // 1. Контрольна сума: packet[3] має дорівнювати packet[0] ^ packet[1] ^ packet[2]
    // TODO: якщо не збігається — return 0;

    uint8_t status = packet[0];

    // 2. Прапорці зі статусу
    out->ready = (status >> 0) & 1U;  // TODO: біт 0
    out->error = (status >> 1) & 1U;  // TODO: біт 1
    out->mode  = (status >> 4) & 0x03;  // TODO: біти 4–5

    // 3. Температура: склеїти packet[1] (молодший) і packet[2] (старший)
    int16_t raw = (int16_t)(packet[1] | (packet[2] << 8)); // TODO
    out->temperature = raw / 10.0f; // TODO: raw поділити на 10

    return 1;
}

int main(void) {
    uint8_t pkt[4] = { 0x21, 0xEB, 0x00, 0xCA }; //0xCB
    sensor_data_t data;

    printf("%04X\n", (uint16_t)-50);

    if (parse_packet(pkt, &data)) {
        printf("ready = %u, error = %u, mode = %u, temp = %.1f\n",
               data.ready, data.error, data.mode, data.temperature);
    } else {
        printf("checksum error\n");
    }
    return 0;
}