#ifndef __KERNEL_SCREEN__
#define __KERNEL_SCREEN__

#include "types.h"
#include "system.h"
#include "string.h"

void clear_line(uint8 from,uint8 to);
void update_cursor();
void clear_screen();
void scroll_up(uint8 line_number);
void new_line_check();
void printch(char c);
void print (string ch);

#endif /* __KERNEL_SCREEN__ */