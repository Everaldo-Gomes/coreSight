#include "common.h"
#include <stdlib.h>
#include <stdio.h>
//#include <unistd.h>
/* #include <fcntl.h> */
/* #include <sys/mman.h> */


uint32_t* get_register_addr(uint32_t *component, uint32_t register_offset)
{
	return (uint32_t*)((char*)component + register_offset);
}


void print_register_info(volatile uint32_t *reg)
{
	printf("Address: %p\n", reg);
	printf("Hex val: 0x%X\n", *reg);

	// binary
	printf("\t ");
	for (int i = 31; i >= 0; i--)
		printf("%2d |", i);


	printf("\nBin val: ");
	for (int i = 31; i >= 0; i--)
		printf("%s|", (*reg & (1 << i) ? " 1 " : " 0 "));
	
	printf("\n\n");
}

/*
int write_mem(unsigned long physical_address, uint32_t data)
{

    int mem_fd = open("/dev/mem", O_RDWR | O_SYNC);
    if (mem_fd == -1) {
        perror("Failed to open /dev/mem");
        return 1;
    }

    size_t pagesize = sysconf(_SC_PAGESIZE);
    unsigned long page_base = physical_address & ~(pagesize-1);
    unsigned long page_offset = physical_address - page_base;

    // Map the physical memory address
    char *mapped_base = (char* ) mmap(0, pagesize, PROT_READ | PROT_WRITE, MAP_SHARED, mem_fd, page_base);
    if (mapped_base == MAP_FAILED) {
        perror("Failed to map memory");
        close(mem_fd);
        return 1;
    }

    // Adjust the pointer to the desired address
    uint32_t *mapped_ptr = (uint32_t *) (mapped_base + page_offset);
    *mapped_ptr = data;

    close(mem_fd);
    munmap(mapped_base, pagesize);

    return 0;
}
*/
