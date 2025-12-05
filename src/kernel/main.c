#include <kFipOS.h>
#include <uart.h>

void _putchar(char character) {
    UARTPutC(character);
}

void KfoMain() {
    UARTPutS("\x1b[32mKraba!\n\x1b[37m");
    KfoHalt();
}