#include <stdio.h>
#include "config.h"
#include "buffer.h"
#include "zcu.h"
#include "common.h"


uint32_t test(uint32_t val)
{
	uint32_t i;
	
	for(i = 0; i < 5; i++)
        val++;
    
	return val;
}

int main(int argc, char* argv[])
{
	clear_buffer(OCM_BASE, BUFFER_SIZE);
	config_components();
	
	printf("Test val: %d\n", test(10));
	dump_buffer(OCM_BASE, BUFFER_SIZE);
	

	
    // ================== debug only ==========================
	extern uint32_t *tmc_1;
	extern uint32_t *tmc_2;
	extern uint32_t *tmc_3;
	uint32_t *tmc = tmc_1;
	uint32_t *reg;
	
	// write
	reg = get_register_addr(tmc, 0x010);
	print_register_info(reg);

	// read
	reg = get_register_addr(tmc, 0x014);
	print_register_info(reg);

	// status
	reg = get_register_addr(tmc, 0x00C);
	print_register_info(reg);
	//=======================================================

	
	printf("\n\n");
	return 0;
}
