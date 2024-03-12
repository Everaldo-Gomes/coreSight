#ifndef COMMON_H
#define COMMON_H

#include <stdint.h>


uint32_t* get_register_addr(uint32_t *component, uint32_t register_offset);
void print_register_info(volatile uint32_t *reg);
//int write_mem(unsigned long physical_address, uint32_t data);

#endif
