// shpargalka 2.0 (cheatsheet 2.0) for language C
// * - pointer
// & - address of
// -> - pointer to struct
// . - struct member 
// [] - array
// () - function call
// {} - block
// & - and
// | - or
// ^ - xor
// ~ - not
// << >> bit-shifts
// void before function - function does not return anything
// void in () - function does not take any arguments
// unsigned char - 1 byte
// unsigned short - 2 bytes
// unsigned int - 4 bytes
// ; - end of statement
// != - not equal
// == - equal
// make
// cp kernel iso/boot/kernel
// grub-mkrescue -o my_kernel.iso iso
// qemu-system-x86_64 -cdrom my_kernel.iso
volatile unsigned short* video = (unsigned short*)0xB8000;

int cursor = 0;
unsigned char color = 0x0F;

void print(const char* message);
void clear_screen(void);

void kernel_main(void)
{
    clear_screen();

    color = 0x0F;
    print("MY KERNEL\n");

    color = 0x0A;
    print("Screen cleared!\n");

    while (1)
    {
        __asm__ volatile ("hlt");
    }
}

void print(const char* message)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        if (message[i] == '\n')
        {
            cursor = (cursor / 80 + 1) * 80;
            continue;
        }

        video[cursor] = ((unsigned short)color << 8) | message[i];
        cursor++;
    }
}

void clear_screen(void)
{
    for (int i = 0; i < 80 * 25; i++)
    {
        video[i] = (0x0F << 8) | ' ';
    }

    cursor = 0;
}