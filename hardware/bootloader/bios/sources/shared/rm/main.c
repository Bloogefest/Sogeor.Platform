#include "main.h"

asm(".code16gcc");

__attribute__((unused, section(".main")))
extern void __main_dap_process(u16_t sectors, u16_t buf_off, u16_t buf_seg, u32_t lba_low)
{
    asm volatile("call __boot_dap_process" : : "a"(sectors), "b"(buf_off), "c"(buf_seg), "d"(lba_low));
}

__attribute__((unused, section(".main")))
void __main_launch()
{
    __pm_enter();
    asm(".code32");
    __lifecycle();
    __pm_leave();
    asm(".code16gcc");
}

__attribute__((unused, section(".main")))
extern void __main_print(const char *s)
{
    asm volatile("call __boot_print" : : "S"(s));
}

__attribute__((unused, section(".main")))
extern void __main_println(const char *s)
{
    asm volatile("call __boot_println" : : "S"(s));
}