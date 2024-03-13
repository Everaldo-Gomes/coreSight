#include "tpiu.h"
#include "common.h"

void tpiu_config(uint32_t *tpiu)
{
	tpiu_unlock(tpiu);
}

void tpiu_unlock(uint32_t *tpiu)
{
	// lock access
	volatile uint32_t *reg = get_register_addr(tpiu, 0xFB0);
	*reg = 0xc5acce55;
}
