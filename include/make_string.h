#pragma once

#include <stdarg.h>

char * make_string(char format[], ...);
char * make_string_variadic(char format[], va_list);
