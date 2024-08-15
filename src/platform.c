#include "platform.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


void sleep_msec(const unsigned msec)
{
#ifdef _WIN32
    Sleep(msec);
#else
    usleep(msec * 1000);
#endif
}
