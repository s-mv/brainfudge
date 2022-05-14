#ifndef smv_bf_impl_memory_h
#define smv_bf_impl_memory_h

#include "common.h"
#include "errors.h"

// initialise/re-initialise memory length
void InitMem();
// expand memory to twice the size
void ExpandMem();
// free memory
void DestroyMem();
// get certain byte from memory
u8 Mem(u16 pointer);
// set certain byte of memory
void SetMem(u16 pointer, u8 data);

u16 MemLength();

#endif