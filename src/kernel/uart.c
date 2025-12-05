#include <uart.h>

uint32_t *GetUARTRegValue(uint64_t BaseAddress, uint32_t Offset) {
    const uint64_t Address = BaseAddress + Offset;

    return (uint32_t *)(Address + Offset);
}

void WaitTXFIFONotFull() {
    while (*UARTFR & (1 << 5)) {
    }
}

void UARTPutC(char C) {
    WaitTXFIFONotFull();
    *UARTDR = (uint32_t)C;
}

void UARTPutS(const char* S) {
    while (*S)
        UARTPutC(*S++);
}
