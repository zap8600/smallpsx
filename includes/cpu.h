#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct CPU {
    uint32_t pc;
} CPU;

void cpu_init(CPU *cpu);

#endif
