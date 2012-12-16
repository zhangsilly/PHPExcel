#include "Util.hpp"

extern "C" {
#include "php.h"
}

#ifdef  PHP_WIN32

char*   strncpy(char* dest, char* src, size_t n)
{
    errno_t ret = strncpy_s(dest, n, src, n);
    if (ret != EINVAL)
    {
        return dest;
    }
    return NULL;
}

wchar_t* utf8ToWide(const char* str, size_t strLen)
{
    DWORD dwLen = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    wchar_t* buffer = (wchar_t*) emalloc(sizeof(wchar_t) * dwLen);
    MultiByteToWideChar(CP_UTF8, 0, str, -1, buffer, dwLen);
    return buffer;
}

wchar_t* gbkToWide(const char* str, size_t strLen)
{
    DWORD dwLen = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    wchar_t* buffer = (wchar_t*) emalloc(sizeof(wchar_t) * dwLen);
    MultiByteToWideChar(CP_ACP, 0, str, -1, buffer, dwLen);
    return buffer;
}

stringToWideConvertor getStringToWideConvertorByCharset(const char* charset)
{
    if (strnicmp("UTF-8", charset, sizeof("UTF-8") - 1) == 0)
    {
        return utf8ToWide;
    }
    return gbkToWide;
}

#endif
