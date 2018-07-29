INC = $(shell find include/*.c)
OBJ = ${INC:.c=.o}

COM = gcc -m32
GCCFLAGS = -ffreestanding

build: kernel $(OBJ)
	ld -m elf_i386 -T link.ld $^ kasm.o -o ./os/boot/kernel

kernel: asm
	$(COM) $(GCCFLAGS) -c kernel.c -o kernel 

%.o: %.c
	$(COM) $(GCCFLAGS) -c $< -o $@

asm:
	nasm -f elf32 kernel.asm -o kasm.o

dist:
	grub-mkrescue -o ./iso/os.iso os/

clean:
	rm *.o include/*.o ./os/boot/kernel iso/*

.PHONY: clean