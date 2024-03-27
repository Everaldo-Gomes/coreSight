#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

uint32_t *etm_0;
uint32_t *funnel_1;
uint32_t *funnel_2;
uint32_t *tmc_1;
uint32_t *tmc_2;
uint32_t *tmc_3;
uint32_t *replicator;
uint32_t *tpiu;

void register_components();
void config_components();

#endif
