TARGET  = php_excel
TEMPLATE = lib
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

PHP_SOURCE_DIR  = ../../../

INCLUDEPATH += $${PHP_SOURCE_DIR}           \
               $${PHP_SOURCE_DIR}\\TSRM     \
               $${PHP_SOURCE_DIR}\\win32    \
               $${PHP_SOURCE_DIR}\\Zend     \
               $${PHP_SOURCE_DIR}\\main

PHP_BINARY_DIR  = "D:\\Program Files (x86)\\php"

CONFIG(release) {
    DESTDIR         = $${PHP_SOURCE_DIR}\\Release_TS
} else {
    DESTDIR         = $${PHP_SOURCE_DIR}\\Debug_TS
}

LIBS    +=  -L$${PHP_BINARY_DIR}\dev    \
            -lphp5ts

QMAKE_CXXFLAGS_DEBUG    += /D "ZEND_WIN32"              \
                           /D "PHP_WIN32"               \
                           /D "HAVE"                    \
                           /D "WIN32"                   \
                           /D "NDEBUG"                  \
                           /D "_WINDOWS"                \
                           /D "_MBCS"                   \
                           /D "_USRDLL"                 \
                           /D "COMPILE_DL_EXCEL"        \
                           /D ZTS=1                     \
                           /D ZEND_DEBUG=0              \
                           /D "EXCEL_EXPORTS"           \
                           /D "COMPILE_DL_EXCEL"        \
                           /D HAVE_EXCEL=1              \
                           /D "ZEND_WIN32_FORCE_INLINE"

SOURCES += \
    ../PHPExcelSheet.cpp \
    ../PHPExcel.cpp \
    ../ExcelFormat.cpp \
    ../excel.cpp \
    ../BasicExcel.cpp \
    ../PHPExcelFormat.cpp \
    ../PHPExcelFont.cpp

HEADERS += \
    ../PHPExcelSheet.hpp \
    ../PHPExcelFormat.hpp \
    ../PHPExcel.hpp \
    ../php_excel.h \
    ../ExcelFormat.hpp \
    ../BasicExcel.hpp \
    ../PHPExcelFont.hpp
