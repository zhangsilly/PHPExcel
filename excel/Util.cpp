#include "Util.hpp"

#ifdef  PHP_WIN32

#include <errno.h>
#include <string.h>

char*   strncpy(char* dest, char* src, size_t n)
{
    errno_t ret = strncpy_s(dest, n, src, n);
    if (ret != EINVAL)
    {
        return dest;
    }
    return NULL;
}

#endif
