#include <stdio.h>
#include "config.h"
#include "buffer.h"
#include "zcu.h"
#include "common.h"

extern uint32_t *tmc_1, *tmc_2, *tmc_3;
volatile uint32_t *reg;

void debug_inf()
{
	uint32_t *tmc = tmc_3;
	
	// write
	reg = get_register_addr(tmc, 0x010);
	print_register_info(reg);

	// read
	reg = get_register_addr(tmc, 0x014);
	print_register_info(reg);

	// status
	reg = get_register_addr(tmc, 0x00C);
	print_register_info(reg);
}

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


	
	// control disable
	reg = get_register_addr(tmc_1, 0x20);
	*reg = 0x0;
	reg = get_register_addr(tmc_2, 0x20);
	*reg = 0x0;

	// status
	reg = get_register_addr(tmc_3, 0x00C);	
	while((*reg & (1 << 2)) != 0);

	// control disable
	reg = get_register_addr(tmc_3, 0x20);
	*reg = 0x0;

	
	
	dump_buffer(OCM_BASE, BUFFER_SIZE);
	debug_inf();
   
	printf("\n\n");
	return 0;
}
