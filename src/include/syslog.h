#pragma once

#include <uart.h>

void SysLogStart();
void SysLogEnd();

void SysLogPrintln(const char *Text);
void SysLogPrint(const char *Text);
void SysLogPutc(char C);

void SysLogFlush();