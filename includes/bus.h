#ifndef BUS_H
#define BUS_H

#include "../includes/bios.h"

typedef struct BUS {
    BIOS bios;
} BUS;

uint32_t bus_load(BUS* bus, uint32_t addr, uint32_t size);

#endif