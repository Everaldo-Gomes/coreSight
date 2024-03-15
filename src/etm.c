#include "etm.h"
#include "common.h"


void etm_config(uint32_t *etm[])
{
	etm_unlock(etm[0]);
	etm_disable(etm[0]);
	etm_trace_config(etm[0]);
	etm_auxiliary_control(etm[0]);
	etm_event_control_0(etm[0]);
	etm_event_control_1(etm[0]);
	etm_stall(etm[0]);
	etm_global_timestamp_control(etm[0]);
	etm_sync_period(etm[0], 0x0);
	etm_set_id(etm[0], 0x7);
	etm_view_isnt_main_control(etm[0]);
	etm_view_inst_include_exclude_control(etm[0]);	
	etm_view_inst_start_stop_control(etm[0]);
	etm_external_input_select(etm[0]);
	etm_resource_selection_control(etm[0]);
	etm_address_comparator_value(etm[0]);
	etm_context_id_comparator_value(etm[0]);
	etm_context_id_comparator_control(etm[0]);
	etm_enable(etm[0]);
}

void etm_unlock(uint32_t *etm)
{
	// lock access
	volatile uint32_t *reg = get_register_addr(etm, 0xFB0);
	*reg = 0xc5acce55;
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
	while((*reg & (1 << 1)) == 0);
}

void etm_trace_config(uint32_t *etm)
{
	// Trace Configuration Register
	volatile uint32_t *reg = get_register_addr(etm, 0x010);
	*reg |= 1 << 3;
	*reg |= 1 << 4;
	*reg |= 1 << 6;
	*reg |= 1 << 7;
	*reg |= 1 << 11;
	*reg |= 1 << 12;	
}

void etm_auxiliary_control(uint32_t *etm)
{
	// Auxiliary Control Register
	volatile uint32_t *reg = get_register_addr(etm, 0x018);
	*reg |= 1 << 2;
	*reg |= 1 << 4;
}

void etm_event_control_0(uint32_t *etm)
{
	// event control 0
	volatile uint32_t *reg = get_register_addr(etm, 0x020);
	*reg = 0x0;	
}

void etm_event_control_1(uint32_t *etm)
{
	// event control 1
	volatile uint32_t *reg = get_register_addr(etm, 0x024);
	*reg |= 1 << 0;
	*reg |= 1 << 11;
}

void etm_stall(uint32_t *etm)
{
  	// stall
	volatile uint32_t *reg = get_register_addr(etm, 0x02C);
	*reg = 0x0;
	*reg &= ~(1 << 8);	
}

void etm_global_timestamp_control(uint32_t *etm)
{
	// global timestamp control
	volatile uint32_t *reg = get_register_addr(etm, 0x030);
	*reg = 0x0;
}

void etm_sync_period(uint32_t *etm, uint32_t period)
{	
	// sync period
	volatile uint32_t *reg = get_register_addr(etm, 0x034);
	*reg = period;
}

void etm_set_id(uint32_t *etm, uint32_t id)
{
	// ID
	volatile uint32_t *reg = get_register_addr(etm, 0x040);
	*reg = 0x0;
	*reg |= id << 0;
}

void etm_view_isnt_main_control(uint32_t *etm)
{
	// ViewInst main control
	volatile uint32_t *reg = get_register_addr(etm, 0x080);
	*reg = 0x201;
}

void etm_view_inst_include_exclude_control(uint32_t *etm)
{
	// ViewInst Include-Exclude Control
	volatile uint32_t *reg = get_register_addr(etm, 0x084);
	*reg = 0x0;
}

void etm_view_inst_start_stop_control(uint32_t *etm)
{
	// ViewInst Start-Stop Control
	volatile uint32_t *reg = get_register_addr(etm, 0x088);
	*reg = 0x0;	
}

void etm_external_input_select(uint32_t *etm)
{
	// External Input Select
	volatile uint32_t *reg = get_register_addr(etm, 0x120);
	*reg = 0x0;
}

void etm_resource_selection_control(uint32_t *etm)
{
	// resource selection control
	volatile uint32_t *reg = get_register_addr(etm, 0x208);
	*reg &= 0x0;
}

void etm_address_comparator_value(uint32_t *etm)
{
	// address comparator value
	volatile uint32_t *reg = get_register_addr(etm, 0x400);
	*reg &= 0x0;
}

void etm_context_id_comparator_value(uint32_t *etm)
{
	// Context ID Comparator Value
	volatile uint32_t *reg = get_register_addr(etm, 0x600);
	*reg &= 0x0;
}

void etm_context_id_comparator_control(uint32_t *etm)
{
	// Context ID Comparator Control Register 0
	volatile uint32_t *reg = get_register_addr(etm, 0x680);
	*reg = 0x0;	
}
