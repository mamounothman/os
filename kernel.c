int kmain() {
  char* vidmem = (char*)0x8000;

  vidmem[0] = 's';
  vidmem[1] = 0x02;
}