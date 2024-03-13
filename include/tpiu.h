#ifndef TPIU_H
#define TPIU_H

#include <stdint.h>


void tpiu_config(uint32_t *tpiu);
void tpiu_unlock(uint32_t *tpiu);

#endif
