#include "replicator.h"
#include "common.h"

void replicator_config(uint32_t *replicator)
{
	replicator_unlock(replicator);
}

void replicator_unlock(uint32_t *replicator)
{
	// lock access
	volatile uint32_t *reg = get_register_addr(replicator, 0xFB0);
	*reg = 0xC5ACCE55;
}
