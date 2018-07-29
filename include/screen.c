#include "screen.h"
#include "types.h"
#include "system.h"
#include "string.h"

int cursorX = 0, cursorY = 0;
const uint8 sw = 80,sh = 25,sd = 2;

void clear_line(uint8 from,uint8 to) {

  uint16 i = sw * from * sd;
  string vidmem = (string) 0xb8000;

  for(i; i<= (sw * ( to + 1 ) * sd ); i++) {
    vidmem[i] = 0x0;
  }

}

void update_cursor() {
  unsigned temp;

  temp = cursorY * sw + cursorX; // Position = (y * width) + x

  outportb(0x3D4, 14);        // CRT Control Register: Select Cursor Location
  outportb(0x3D5, temp >> 8); // Send the high byte across the bus
  outportb(0x3D4, 15);        // CRT Control Register: Select Send Low byte
  outportb(0x3D5, temp);      // Send the Low byte of the cursor location

}

void clear_screen() {
  clear_line(0,sh - 1);
  cursorX = 0;
  cursorY = 0;
  update_cursor();
}

void scroll_up(uint8 line_number) {
  string vidmem = (string) 0xb8000;
  uint16 i = 0;
  for (i ; i < sw * (sh - 1) * sd ; i++) {
    vidmem[i] = vidmem[i + sw * sd * line_number];
  }
  clear_line(sh - 1 - line_number, sh - 1);
  if((cursorY - line_number) < 0 ) {
    cursorY = 0;
    cursorX = 0;
  } else {
    cursorY -= line_number;
  }
  update_cursor();
}

void new_line_check() {
  if(cursorY >= sh - 1) {
    scroll_up(1);
  }
}

void printch(char c) {
  string vidmem = (string) 0xb8000;
  switch(c) {
    case (0x08):
      if(cursorX > 0) {
        cursorX--;									
        vidmem[(cursorY * sw + cursorX)*sd]=0x00;	                              
      }
      break;
    case (0x09):
      cursorX = (cursorX + 8) & ~(8 - 1);
      break;
    case ('\r'):
      cursorX = 0;
      break;
    case ('\n'):
      cursorX = 0;
      cursorY++;
      break;
    default :
      vidmem [((cursorY * sw + cursorX)) * sd] = c;
      vidmem [((cursorY * sw + cursorX)) * sd + 1] = 0x0F;
      cursorX++; 
      break;
  }
  if(cursorX >= sw) {
    cursorX = 0;                                                                
    cursorY++;                                                                    
  }
  new_line_check();
  update_cursor();
}

void print (string ch) {
  uint16 i = 0;
  uint16 len = strlength(ch);
  for(i ; i < len ; i++) {
    printch(ch[i]);
  }
}