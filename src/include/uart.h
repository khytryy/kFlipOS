#pragma once

#include <stdint.h>

#define UARTBase 0x09000000UL

// Offsets
static const uint32_t DROffset      = 0x000;
static const uint32_t FROffset      = 0x018;
static const uint32_t IBRDOffset    = 0x024;
static const uint32_t FBRDOffset    = 0x028;
static const uint32_t LCROffset     = 0x02c;
static const uint32_t CROffset      = 0x030;
static const uint32_t IMSCOffset    = 0x038;
static const uint32_t DMACROffset   = 0x048;

#define UARTDR ((volatile uint32_t*)(UARTBase + DROffset))
#define UARTFR ((volatile uint32_t*)(UARTBase + FROffset))

uint32_t *GetUARTRegValue(uint64_t BaseAddress, uint32_t Offset);
void WaitTXFIFONotFull();

void UARTPutC(char C);
void UARTPutS(const char* S);

void WaitUARTDone();