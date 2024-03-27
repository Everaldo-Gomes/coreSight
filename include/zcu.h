#ifndef ZCU_H
#define ZCU_H

#include <stdint.h>


#define CS_BASE    0xFE800000
#define ETM_0      0x440000     // embedded trace macrocell V4.0
#define ETM_1      0x540000     // embedded trace macrocell V4.0
#define ETM_2      0x640000     // embedded trace macrocell V4.0
#define ETM_3      0x740000     // embedded trace macrocell V4.0
#define FUNNEL_1   0x00120000   // coreSight trace funnel
#define FUNNEL_2   0x00130000   // ATB funnel
#define TMC_1      0x140000     // trace memory controller -> ETF1 - embedded trace buffer FIFO1
#define TMC_2      0x150000     // trace memory controller -> ETF  - embedded trace buffer FIFO
#define TMC_3      0x170000     // trace memory controller -> ETR  - embedded trace router
#define REPLICATOR 0x160000
#define TPIU       0x00180000
#define OCM_BASE   0x00FFFC0000 // on chip memeory

#define BUFFER_SIZE 256 //(1024 * 4)  // 4kB

enum component {
	etm_0_comp,
	etm_1_comp,
	etm_2_comp,
	etm_3_comp,
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
