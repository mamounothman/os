#ifndef __KERNEL_SYSTEM__
#define __KERNEL_SYSTEM__

#include "types.h"

uint8 inportb(uint16 _port);

void outportb(uint16 _port, uint8 _data);

#endif /* __KERNEL_SYSTEM__ */