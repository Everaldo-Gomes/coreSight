#include <stdio.h>
#include <unistd.h>

#include "common.h"
#include "config.h"
#include "buffer.h"
#include "zcu.h"
#include "etm.h"
#include "tmc.h"


int main(int argc, char* argv[])
{
	clear_buffer(OCM_BASE, BUFFER_SIZE);
	config_components();


	//---------------------------------------------
	uint32_t val = 0, a = 0;
	uint32_t *p = &a;
	
	for (uint32_t i = 0; i < 10; i++)
	{
		a += 2;
		val+= *p;
	}

	printf("Val: %d\n", val);
	//---------------------------------------------


	dump_buffer(OCM_BASE, BUFFER_SIZE);
	return 0;
}
