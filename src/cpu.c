#include <stdint.h>
#include "../includes/cpu.h"

void cpu_init(CPU* cpu) {
    cpu->pc = 0xbfc00000;
}