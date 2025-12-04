#pragma once

#include <stdint.h>

void *UARTBase = (void*)0x09000000;

// Offsets
static const uint32_t DROffset      = 0x000;
static const uint32_t FROffset      = 0x018;
static const uint32_t IBRDOffset    = 0x024;
static const uint32_t FBRDOffset    = 0x028;
static const uint32_t LCROffset     = 0x02c;
static const uint32_t CROffset      = 0x030;
static const uint32_t IMSCOffset    = 0x038;
static const uint32_t DMACROffset   = 0x048;

uint32_t GetRegValue() {
    
}