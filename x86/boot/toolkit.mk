AS := nasm
ASFLAGS := -f elf32

CC := i686-elf-gcc
CFLAGS := -std=gnu17 \
          -ffreestanding

LD := i686-elf-ld
LDFLAGS := -nostdlib