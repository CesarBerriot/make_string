#include "make_string.h"
#include <windows.h>
#include <hard_assert.h>
#include <stdio.h>
#include <stdarg.h>

#define LIBRARY_NAME "make_string"

#ifndef thread_local
	#ifdef _MSC_VER
		#define thread_local __declspec(thread)
	#else
		#define thread_local _Thread_local
	#endif
#endif

static thread_local char * buffer = NULL;

static void cleanup(void);

char * make_string(char format[], ...)
{	va_list arguments;
	va_start(arguments, format);
	make_string_variadic(format, arguments);
	va_end(arguments);
	return buffer;
}

char * make_string_variadic(char format[], va_list arguments)
{	char * previous_buffer = buffer;
	int buffer_size = vsnprintf(NULL, 0, format, arguments) + 1;
	ha_assert(buffer_size > 0, LIBRARY_NAME, "buffer size computation failure");
	buffer = malloc(buffer_size);
	ha_assert(buffer, LIBRARY_NAME, "buffer allocation failure");
	ha_assert(vsprintf(buffer, format, arguments) == (buffer_size - 1), LIBRARY_NAME, "buffer initialization failure");
	free(previous_buffer);
	return buffer;
}
