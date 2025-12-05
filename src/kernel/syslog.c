#include <syslog.h>

void SysLogStart() {
    UARTPutS("\e[35m--[SYSLOG START]--\n\e[97m"); 
}

void SysLogEnd() {
    UARTPutS("\e[35m--[SYSLOG END]--\n\e[97m"); 
}

void SysLogPrintln(const char *Text) {
    UARTPutS(Text);
    WaitUARTDone();
    UARTPutS("\n");
}

void SysLogPrint(const char *Text) {
    UARTPutS(Text);
}

void SysLogPutc(char C) {
    UARTPutC(C);
}

void SysLogFlush() {
    WaitUARTDone();
}