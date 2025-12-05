#include <kFipOS.h>
#include <syslog.h>

void KfoMain() {
    SysLogPrintln("Kraba!");
    SysLogPrintln("Kraba!");

    KfoHalt();
}