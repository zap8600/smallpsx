#ifndef BIOS_H
#define BIOS_H

#define BIOS_SIZE 512 * 1024
#define BIOS_BASE 0x1fc00000

typedef struct BIOS {
    uint8_t data[BIOS_SIZE]; // Shouldn't cause a seg fault
} BIOS;

uint32_t bios_load(bios* bios, uint32_t addr, uint32_t size);