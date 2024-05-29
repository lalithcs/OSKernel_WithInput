#ifndef IO_H
#define IO_H

/* These functions are defined in assembly because they use
   instructions (inb and outb) that are not available in C. */

/* Read a byte from the specified port */
static inline char inb(int port) {
    char ret;
    asm volatile ("inb %%dx, %%al" : "=a"(ret) : "d"(port));
    return ret;
}

/* Write a byte to the specified port */
static inline void outb(int port, char val) {
    asm volatile ("outb %%al, %%dx" : : "a"(val), "d"(port));
}

#endif /* IO_H */