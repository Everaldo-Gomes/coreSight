#ifndef TMC_H
#define TMC_H

#include <stdio.h>
#include <stdint.h>


enum tmc_mode {circular, sofware, hardware};

void tmc_config(uint32_t *tmc[]);
void tmc_unlock(uint32_t *tmc);
void tmc_enable(uint32_t *tmc);
void tmc_disable(uint32_t *tmc);
void tmc_is_ready(uint32_t *tmc);
void tmc_set_mode(uint32_t *tmc, uint32_t mode);
void tmc_formatter_flush_control(uint32_t *tmc, uint32_t value);
void tmc_buffer_level_water_mark(uint32_t *tmc, uint32_t value);
void tmc_set_axi(uint32_t *tmc, int burst_len);
void tmc_ram_set_size(uint32_t *tmc, uint32_t ram_size);
void tmc_set_data_buffer(uint32_t *tmc, uint64_t addr);
void tmc_set_ram_read_ptr(uint32_t *tmc, uint64_t addr);
void tmc_set_ram_write_ptr(uint32_t *tmc, uint64_t addr);


#endif
