#include "zcu.h"
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/mman.h>
#include <fcntl.h>


uint32_t* register_component(enum component comp)
{
    int fd = open("/dev/mem", O_RDWR | O_SYNC);
	
    if (fd < 0)
	{
        perror("Cannot open /dev/mem\n");
		return NULL;
    }
	

	uint32_t *ptr = NULL;
   
	switch(comp)
	{
	case etm_0_comp:
		ptr = mmap(NULL, 0xD0000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + ETM_0);
		break;
	case etm_1_comp:
		ptr = mmap(NULL, 0xD0000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + ETM_1);
		break;
	case etm_2_comp:
		ptr = mmap(NULL, 0xD0000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + ETM_2);
		break;
	case etm_3_comp:
		ptr = mmap(NULL, 0xD0000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + ETM_3);
		break;
	case funnel_1_comp:
		ptr = mmap(NULL, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + FUNNEL_1);
		break;
	case funnel_2_comp:
		ptr = mmap(NULL, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + FUNNEL_2);
		break;
	case tmc_1_comp:
		ptr = mmap(NULL, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + TMC_1);
		break;
	case tmc_2_comp:
		ptr = mmap(NULL, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + TMC_2);
		break;
	case tmc_3_comp:
		ptr = mmap(NULL, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + TMC_3);
		break;
	case replicator_comp:
		ptr = mmap(NULL, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + REPLICATOR);
		break;
	case tpiu_comp:
		ptr = mmap(NULL, 0x10000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, CS_BASE + TPIU);
		break;
	default:
		printf("Failed to register component %d\n", comp);
	}

	close(fd);
	return ptr;
}
