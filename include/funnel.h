#ifndef FUNNEL_H
#define FUNNEL_H

#include <stdint.h>

void funnel_config(uint32_t *funnel[]);
void funnel_unlock(uint32_t *funnel);
void funnel_config_port(uint32_t *funnel, uint32_t port, uint32_t hold_time);

#endif
