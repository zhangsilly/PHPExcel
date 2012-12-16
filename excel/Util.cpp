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

char*   wideToUtf8(const wchar_t* str, size_t strLen)
{
    DWORD  dwLen    = WideCharToMultiByte(CP_UTF8, 0, str, -1, NULL, 0, NULL, NULL);
    char*   buffer  = (char*) emalloc(sizeof(char) * dwLen);
    WideCharToMultiByte(CP_UTF8, 0, str, -1, buffer, dwLen, NULL, NULL);
    return buffer;
}

wchar_t* gbkToWide(const char* str, size_t strLen)
{
    DWORD dwLen = MultiByteToWideChar(CP_ACP, 0, str, -1, NULL, 0);
    wchar_t* buffer = (wchar_t*) emalloc(sizeof(wchar_t) * dwLen);
    MultiByteToWideChar(CP_ACP, 0, str, -1, buffer, dwLen);
    return buffer;
}

char*  wideToGbk(const wchar_t* str, size_t strLen)
{
    DWORD dwLen     = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);
    char*   buffer  = (char*) emalloc(sizeof(char) * dwLen);
    WideCharToMultiByte(CP_ACP, 0, str, -1, buffer, dwLen, NULL, NULL);
    return buffer;
}

void    getConvertorByCharset(const char* charset, STW_CONVERTOR* stwCvt, WTS_CONVERTOR* wtsCvt)
{
    if (strnicmp("UTF-8", charset, sizeof("UTF-8") - 1) == 0
            || strnicmp("UTF8", charset, sizeof("UTF8") - 1) == 0)
    {
        *stwCvt = utf8ToWide;
        *wtsCvt = wideToUtf8;
    } else {
        *stwCvt = gbkToWide;
        *wtsCvt = wideToGbk;
    }
}
STW_CONVERTOR getStringToWideConvertorByCharset(const char* charset)
{
    if (strnicmp("UTF-8", charset, sizeof("UTF-8") - 1) == 0)
    {
        return utf8ToWide;
    }
    return gbkToWide;
}

#endif
