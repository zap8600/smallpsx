#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "./includes/cpu.h"

void read_bios(CPU* cpu, char *filename)
{
    FILE *file;
    uint8_t *buffer;
    unsigned long fileLen;

    file = fopen(filename, "rb");
    if (!file)
    {
        fprintf(stderr, "Unable to open file %s", filename);
    }

    fseek(file, 0, SEEK_END);
    fileLen=ftell(file);
    fseek(file, 0, SEEK_SET);

    buffer = (uint8_t *)malloc(fileLen);
    if (!buffer)
    {
        fprintf(stderr, "Memory error!");
        fclose(file);
    }

    fread(buffer, fileLen, 1, file);
    fclose(file);

    memcpy(cpu->bus.bios.data, buffer, fileLen);
    free(buffer);
}

CPU cpu;

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s <BIOS ROM>\n", argv[0]);
        return 1;
    }

    cpu_init(&cpu);
    read_bios(&cpu, argv[1]);
}