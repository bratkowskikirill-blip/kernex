all:
	nasm -f elf32 boot.asm -o boot.o
	gcc -m32 -ffreestanding -c kernel.c -o kernel.o
	ld -m elf_i386 -T linker.ld -o kernel boot.o kernel.o
	mkdir -p iso/boot/grub
	cp kernel iso/boot/kernel/kernel
	grub-mkrescue -o kernex.iso iso