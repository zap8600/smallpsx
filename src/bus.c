#include "../includes/bus.h"
#include <stdio.h>

const uint32_t region_mask[8] = {0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x7fffffff, 0x1fffffff, 0xffffffff, 0xffffffff};

uint32_t bus_load(BUS* bus, uint32_t addr, uint32_t size) {
    addr &= region_mask[addr >> 29];
    if(BIOS_BASE <= addr && addr < (BIOS_BASE + BIOS_SIZE)) {
        return bios_load(&(bus->bios), addr, size);
    }
}