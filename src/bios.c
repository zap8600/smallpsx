#include <stdint.h>
#include "../includes/bios.h"

uint32_t bios_load_8(BIOS* bios, uint32_t addr){
    return (uint32_t) bios->data[addr - BIOS_BASE];
}
uint32_t bios_load_16(BIOS* bios, uint32_t addr){
    return (uint32_t) bios->data[addr - BIOS_BASE]
        |  (uint32_t) bios->data[addr - BIOS_BASE + 1] << 8;
}
uint32_t bios_load_32(BIOS* bios, uint32_t addr){
    return (uint32_t) bios->data[addr - BIOS_BASE]
        |  (uint32_t) bios->data[addr - BIOS_BASE + 1] << 8
        |  (uint32_t) bios->data[addr - BIOS_BASE + 2] << 16 
        |  (uint32_t) bios->data[addr - BIOS_BASE + 3] << 24;
}

uint32_t bios_load(BIOS* bios, uint32_t addr, uint32_t size) {
    switch(size) {
        case 8: return bios_load_8(bios, addr);  break;
        case 16: return bios_load_16(bios, addr); break;
        case 32: return bios_load_32(bios, addr); break;
    }
}