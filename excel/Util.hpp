#ifndef UTIL_HPP
#define UTIL_HPP

#ifdef PHP_WIN32
#define     WIN32_LEAN_AND_MEAN
#include    <Windows.h>
#endif

typedef wchar_t* (*stringToWideConvertor)(const char*, size_t);
typedef char*    (*stringToNarrowConvertor)(const wchar_t*, size_t);
stringToWideConvertor getStringToWideConvertorByCharset(const char* charset);

#ifdef  PHP_WIN23
char*   strncpy(char* dest, char* src, size_t n);
#endif

#endif // UTIL_HPP
