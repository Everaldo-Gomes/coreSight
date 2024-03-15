#include "funnel.h"
#include "common.h"
#include <stdint.h>
#include <stdio.h>

void funnel_config(uint32_t *funnel[])
{
	funnel_unlock(funnel[1]);
	funnel_config_port(funnel[1], 0xFF, 0x0);

	funnel_unlock(funnel[2]);
	funnel_config_port(funnel[2], 0xFF, 0x0);
}

void funnel_unlock(uint32_t *funnel)
{
	// lock access
	volatile uint32_t *reg = get_register_addr(funnel, 0xFB0);
	*reg = 0xc5acce55;
}

void funnel_config_port(uint32_t *funnel, uint32_t port, uint32_t hold_time)
{
	// control
	volatile uint32_t *reg = get_register_addr(funnel, 0x000);
	*reg = 0x0;
	*reg |= (port & 0xFF);

	if (hold_time <= 0xE)
		*reg |= hold_time << 8;
	else
		printf("WARNING: invalid hold time, choose from 0x0 to 0xE. Auto set to 0x0\n");
}
