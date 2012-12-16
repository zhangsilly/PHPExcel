#ifndef UTIL_HPP
#define UTIL_HPP

#ifdef PHP_WIN32
#define     WIN32_LEAN_AND_MEAN
#include    <Windows.h>
#endif

typedef wchar_t* (*STW_CONVERTOR)(const char*, size_t);
typedef char*    (*WTS_CONVERTOR)(const wchar_t*, size_t);
void    getConvertorByCharset(const char* charset, STW_CONVERTOR* stwCvt, WTS_CONVERTOR* wtsCvt);

#ifdef  PHP_WIN23
char*   strncpy(char* dest, char* src, size_t n);
#endif

#endif // UTIL_HPP
