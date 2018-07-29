#include "types.h"

uint16 strlength (string str) {
  uint16 i = 1;
  while(str[i++]);
  return --i;
}