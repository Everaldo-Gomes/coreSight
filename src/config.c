#include "config.h"
#include "zcu.h"
#include "funnel.h"
#include "tmc.h"
#include "replicator.h"
#include "etm.h"

void config_components()
{
	etm_0      = register_component(etm_0_comp);
	funnel_1   = register_component(funnel_1_comp);
	funnel_2   = register_component(funnel_2_comp);
	tmc_1      = register_component(tmc_1_comp);
	tmc_2      = register_component(tmc_2_comp);
	tmc_3      = register_component(tmc_3_comp);
	replicator = register_component(replicator_comp);
	tpiu       = register_component(tpiu_comp);

	uint32_t *funnel[] = {NULL, funnel_1, funnel_2};
	funnel_config(funnel);

	uint32_t *tmc[] = {tmc_1, tmc_2, tmc_3};
	tmc_config(tmc);
	
	uint32_t *etm[] = {etm_0};
	etm_config(etm);
}
