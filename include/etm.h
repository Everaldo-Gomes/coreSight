#ifndef ETM_H
#define ETM_H

#include <stdint.h>


void etm_config(uint32_t *etm[]);
void etm_unlock(uint32_t *etm);
void etm_enable(uint32_t *etm);
void etm_disable(uint32_t *etm);
void etm_is_ready(uint32_t *etm);
void etm_trace_config(uint32_t *etm, uint32_t value);
void etm_event_control_0(uint32_t *etm);
void etm_event_control_1(uint32_t *etm);
void etm_stall_control(uint32_t *etm, uint32_t value);
void etm_set_stall(uint32_t *etm, uint32_t level);
void etm_global_timestamp_control(uint32_t *etm, uint32_t value);
void etm_sync_period(uint32_t *etm, uint32_t period);
void etm_set_id(uint32_t *etm, uint32_t id);
void etm_view_isnt_main_control(uint32_t *etm, uint32_t value);
void etm_view_inst_include_exclude_control(uint32_t *etm, uint32_t value);
void etm_view_inst_start_stop_control(uint32_t *etm, uint32_t value);
void etm_external_input_select(uint32_t *etm, uint32_t value);
void etm_resource_selection_control(uint32_t *etm, uint32_t value);
void etm_address_comparator_value(uint32_t *etm, uint32_t value);
void etm_context_id_comparator_value(uint32_t *etm);
void etm_context_id_tracing(uint32_t *etm);
void view_data_main_control(uint32_t *etm, uint32_t value);
void view_data_include_exclude_single_address_comparator_control(uint32_t *etm, uint32_t value);
void view_data_include_exclude_range_comparator_control(uint32_t *etm, uint32_t value);
	

#endif
