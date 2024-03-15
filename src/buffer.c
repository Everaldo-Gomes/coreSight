#include <stdio.h>
#include <sys/mman.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

uint32_t *get_buffer_ptr(uint64_t buffer_addr, uint32_t buffer_size)
{
    int fd = open("/dev/mem", O_RDWR);
	
    if (fd < 0)
	{
        perror("Cannot open /dev/mem\n");
        exit(1);
    }
	
    uint32_t *ptr = mmap(NULL, buffer_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, buffer_addr);
	
    if (ptr == MAP_FAILED)
		fprintf(stderr,"mmap to bufferfer failed!\n");
	
	close(fd);
    return ptr;
}

void clear_buffer(uint64_t buffer_addr, uint32_t buffer_size)
{
    uint32_t *buffer_ptr = get_buffer_ptr(buffer_addr, buffer_size);
	uint32_t *buffer_base_ptr = buffer_ptr;

    for(uint32_t i = 0; i < buffer_size / 4; i++)
	    *buffer_ptr++ = 0;

    munmap(buffer_base_ptr, buffer_size);
}

void dump_buffer(uint64_t buffer_addr, uint32_t buffer_size)
{
	FILE *trace_file     = fopen("./output/trace_file.out", "w+");
	FILE *trace_file_dat = fopen("./output/trace.dat", "w+");

	if (trace_file == NULL)
		perror("Can't open trace_file.out\n");

	if (trace_file_dat == NULL)
		perror("Can't open trace_file_dat\n");
	
	uint32_t *buffer_ptr = get_buffer_ptr(buffer_addr, buffer_size);
	uint32_t *buffer_base_ptr = buffer_ptr;

	int frame = 1;
    for(uint32_t i = 0; i < buffer_size / 4; i++)
	{
		fprintf(trace_file, "0x%08X\t", *buffer_ptr);
		fprintf(trace_file, "0x%08X\n",  buffer_ptr);
		fwrite((void *)buffer_ptr, sizeof(uint32_t), 1, trace_file_dat);
		buffer_ptr++;

		if (frame == 4)
		{
			fprintf(trace_file, "\n");
			frame = 0;
		}
		
		frame++;
	}
	
    fclose(trace_file);
	fclose(trace_file_dat);
    munmap(buffer_base_ptr, buffer_size);
}
