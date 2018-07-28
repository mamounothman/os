build: kernel
	ld -m elf_i386 -T link.ld -o kernel kasm.o kc.o

kernel: asm
	gcc -m32 -c kernel.c -o kc.o

asm:
	nasm -f elf32 kernel.asm -o kasm.o

run:
	qemu-system-i386 -kernel kernel

clean:
	rm *.o kernel