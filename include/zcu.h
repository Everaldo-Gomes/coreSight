#ifndef ZCU_H
#define ZCU_H

#include <stdint.h>


#define CS_BASE    0xFE800000
#define ETM_0      0x440000     // embedded trace macrocell
#define FUNNEL_1   0x00120000   // coreSight trace funnel
#define FUNNEL_2   0x00130000   // ATB funnel
#define TMC_1      0x140000     // trace memory controller -> ETF1 - embedded trace buffer fifo1
#define TMC_2      0x150000     // trace memory controller -> ETF  - embedded trace buffer fifo
#define TMC_3      0x170000     // trace memory controller -> ETR  - embedded trace router
#define REPLICATOR 0x160000
#define TPIU       0x00180000
#define OCM_BASE   0x00FFFC0000 // on chip memeory

//const uint32_t BUFFER_SIZE = 1024 * 8;  // 8kB
#define BUFFER_SIZE (1024 * 8)

enum component {

	etm_0_comp,
	funnel_1_comp,
	funnel_2_comp,
	tmc_1_comp,
	tmc_2_comp,
	tmc_3_comp,
	replicator_comp,
	tpiu_comp,
};


uint32_t* register_component(enum component);

#endif
