#include "tmc.h"
#include "zcu.h"
#include "common.h"

void tmc_config(uint32_t *tmc[])
{
	tmc_unlock(tmc[0]);
	tmc_unlock(tmc[1]);
	tmc_unlock(tmc[2]);

	tmc_disable(tmc[0]);
	tmc_disable(tmc[1]);
	tmc_disable(tmc[2]);

	tmc_set_mode(tmc[0], hardware);
	tmc_set_mode(tmc[1], hardware);
	tmc_set_mode(tmc[2], circular);

	tmc_set_axi(tmc[2], 0xF); 
	tmc_ram_set_size(tmc[2], BUFFER_SIZE);
	tmc_set_data_buffer(tmc[2], OCM_BASE);  
	tmc_set_ram_read_ptr(tmc[2], OCM_BASE);
	tmc_set_ram_write_ptr(tmc[2], OCM_BASE); 
	
	tmc_enable(tmc[0]);
	tmc_enable(tmc[1]);
	tmc_enable(tmc[2]);
}

void tmc_unlock(uint32_t *tmc)
{
	// lock access
	volatile uint32_t *reg = get_register_addr(tmc, 0xFB0);
	*reg = 0xc5acce55;
}

void tmc_enable(uint32_t *tmc)
{
	// control
	volatile uint32_t *reg = get_register_addr(tmc, 0x20);
	*reg = 0x1;
}

void tmc_disable(uint32_t *tmc)
{
	// control
	volatile uint32_t *reg = get_register_addr(tmc, 0x20);
	*reg = 0x0;

	tmc_is_ready(tmc);
}

void tmc_is_ready(uint32_t *tmc)
{
	// status
	volatile uint32_t *reg = get_register_addr(tmc, 0x00C);
	uint32_t ready = 0;

	while(!ready)
		ready = *reg & (1 << 2) ? 1 : 0;
}

void tmc_set_mode(uint32_t *tmc, uint32_t mode)
{
	// mode
	volatile uint32_t *reg = get_register_addr(tmc, 0x028);
	*reg = 0x0;
	*reg |= mode;
}

void tmc_set_axi(uint32_t *tmc, int burst_len)
{
	// AXI control
	volatile uint32_t *reg = get_register_addr(tmc, 0x110);
	*reg = 0;
	*reg |= burst_len << 8;
	*reg &= ~(1 << 7);
}

void tmc_ram_set_size(uint32_t *tmc, uint32_t ram_size)
{
    if (ram_size > (1024 * 8))
	{
		printf("WARNING: TMC RAM set size is greater than 8KB\n");		
	}

	// RAM size
	volatile uint32_t *reg = get_register_addr(tmc, 0x004);
	*reg = 0;
    *reg = ram_size / 4;
}

void tmc_set_data_buffer(uint32_t *tmc, uint64_t addr)
{
	volatile uint32_t *reg;
	
	// address low
	reg = get_register_addr(tmc, 0x118);
    *reg = addr;
	
	// address high
	reg = get_register_addr(tmc, 0x11C);
    *reg = (uint32_t)(addr >> 32);
}

void tmc_set_ram_read_ptr(uint32_t *tmc, uint64_t addr)
{
	volatile uint32_t *reg;
	
	// RAM read ptr
	reg = get_register_addr(tmc, 0x14);
    *reg = addr;
	
	// RAM read ptr high
	reg = get_register_addr(tmc, 0x38);
    *reg = (uint32_t)(addr >> 32);
}

void tmc_set_ram_write_ptr(uint32_t *tmc, uint64_t addr)
{
	volatile uint32_t *reg;
	
	// RAM write ptr
	reg = get_register_addr(tmc, 0x18);
    *reg = addr;
	
	// RAM write ptr high
	reg = get_register_addr(tmc, 0x3C);
    *reg = (uint32_t)(addr >> 32);
}
