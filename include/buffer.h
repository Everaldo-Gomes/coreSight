#ifndef BUFFER_H
#define BUFFER_H

#include <stdint.h>

uint32_t *get_buffer_ptr(uint64_t buffer_addr, uint32_t buffer_size);
void clear_buffer(uint64_t buffer_addr, uint32_t buffer_size);
void dump_buffer(uint64_t buffer_addr, uint32_t buffer_size);


#endif
