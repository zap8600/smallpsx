#ifndef CPU_H
#define CPU_H

#include <stdint.h>
#include "../includes/bus.h"

typedef struct CPU {
    BUS bus;
    uint32_t pc;
} CPU;

void cpu_init(CPU *cpu);

#endif
