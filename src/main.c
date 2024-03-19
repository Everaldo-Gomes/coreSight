#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "config.h"
#include "buffer.h"
#include "zcu.h"
#include "etm.h"
#include "tmc.h"


uint32_t test(uint32_t val)
{	
	for(uint32_t i = 0; i < 5; i++)
        val++;
    
	return val;
}

int main(int argc, char* argv[])
{
	clear_buffer(OCM_BASE, BUFFER_SIZE);
	config_components();

	printf("Test val: %d\n", test(10));
	

	etm_disable(etm_0);
	/* tmc_disable(tmc_1); */
	/* tmc_disable(tmc_2); */
	/* tmc_disable(tmc_3); */
	
	dump_buffer(OCM_BASE, BUFFER_SIZE);
   
	printf("\n\n");
	return 0;
}
