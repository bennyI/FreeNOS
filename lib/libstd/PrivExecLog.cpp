/**
 * Logging utilities and definitions.
 *
 * @author Niek Linnenbank
 * @date 5 march 2015
 */

#include <FreeNOS/API.h>
#include "PrivExecLog.h"

PrivExecLog::PrivExecLog() : Log()
{
}

void PrivExecLog::write(const char *str)
{
    PrivExec(WriteConsole, (Address) str);
}
