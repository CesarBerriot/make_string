#pragma once

#include <stdarg.h>

char * make_string(char const format[], ...);
char * make_string_variadic(char const format[], va_list);
