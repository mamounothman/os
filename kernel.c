int kmain() {
  /**
   * This is the kernel main function, all it does is write a single 
   * character, vidmem[0], to the video text memory and display it with 
   * the configured color, vidmem[1], value.
   * 
   * While in protected mode and not using the BIOS like in this kernel 
   * starter code, The vidmem variable is a pointer to physical memory 
   * address for the text screen video. 
   * 
   * text screen video memory address for colour monitors starts at 0xB8000 
   * 
   * references https://wiki.osdev.org/Printing_To_Screen
   **/
  char* vidmem = (char*)0xB8000;
  /**
   * char type is 2 bytes long, the first byte holds the value of the character
   * and the second one is for the color.
   * */
  vidmem[0] = 'D';
  vidmem[1] = 0x1F;
}