#include "etm.h"
#include "zcu.h"
#include "tmc.h"
#include "common.h"

#include "stdio.h"
#include <sys/mman.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void etm_config(uint32_t *etm[])
{
	for (uint32_t i = 0; i < 1; i++)
	{
		etm_unlock(etm[i]);
		etm_disable(etm[i]);
	
		// reset
		etm_trace_config(etm[i]);
		etm_event_control_0(etm[i]);
		etm_event_control_1(etm[i]);
		etm_stall(etm[i]);
		etm_sync_period(etm[i], 0b10100);
		etm_set_id(etm[i], i+1);
		etm_global_timestamp_control(etm[i]);
		etm_view_isnt_main_control(etm[i]);
		etm_view_inst_include_exclude_control(etm[i]);
		etm_view_inst_start_stop_control(etm[i]);
		etm_external_input_select(etm[i]);
		etm_resource_selection_control(etm[i]);
		etm_address_comparator_value(etm[i]);
		etm_context_id_comparator_value(etm[i]);
		etm_context_id_tracing(etm[i]);
		etm_set_stall(etm[i], 0x0);
		etm_enable(etm[i]);
	}
}

void etm_unlock(uint32_t *etm)
{
	// software lock access
	volatile uint32_t *reg = get_register_addr(etm, 0xFB0);
	*reg = 0xc5acce55;

	// OS lock access
	reg = get_register_addr(etm, 0x300);
	*reg = 0x0;
}

void etm_enable(uint32_t *etm)
{
	// control
	volatile uint32_t *reg = get_register_addr(etm, 0x004);
	*reg = 0x1;
}

void etm_disable(uint32_t *etm)
{
	// control
	volatile uint32_t *reg = get_register_addr(etm, 0x004);
	*reg = 0x0;

	etm_is_ready(etm);
}

void etm_is_ready(uint32_t *etm)
{
	// status
	volatile uint32_t *reg = get_register_addr(etm, 0x00C);
	while(*reg == 0);
}

void etm_trace_config(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x010);
	*reg = 0x0;
}

void etm_event_control_0(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x020);
	*reg = 0x0;	
}

void etm_event_control_1(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x024);
	*reg = 0x0;
}

void etm_stall(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x02C);
	*reg = 0x0;
}

void etm_set_stall(uint32_t *etm, uint32_t level)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x02C);

	if (level)
	{
		*reg |= 0x1 << 8;
		*reg |= 0x1 << 13;
		*reg |= (level & 0xF);
	}
	else
	{
		*reg &= ~(0x1 << 8);
		*reg &= ~(0x1 << 13);
	}
}



void etm_global_timestamp_control(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x030);
	*reg = 0x0;
}

void etm_sync_period(uint32_t *etm, uint32_t period)
{	
	volatile uint32_t *reg = get_register_addr(etm, 0x034);
	*reg = period;
}

void etm_set_id(uint32_t *etm, uint32_t id)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x040);
	*reg = id;
}

void etm_view_isnt_main_control(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x080);
	*reg = 0x201;
}

void etm_view_inst_include_exclude_control(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x084);
	*reg = 0x0;
}

void etm_view_inst_start_stop_control(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x088);
	*reg = 0x0;	
}

void etm_external_input_select(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x120);
	*reg = 0x0;
}

void etm_resource_selection_control(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x208);
	*reg &= 0x0000;
}

void etm_address_comparator_value(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x400);
	*reg &= 0x0000;
}

void etm_context_id_comparator_value(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x600);
	*reg &= 0x0000;

	reg = get_register_addr(etm, 0x640);
	*reg &= 0x0000;
}

void etm_context_id_tracing(uint32_t *etm)
{
	volatile uint32_t *reg = get_register_addr(etm, 0x010);
	*reg |= 0x1 << 6;
}

	
