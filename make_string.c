#include <windows.h>
#include <hard_assert.h>
#include <stdio.h>
#include <stdarg.h>

#define LIBRARY_NAME "make_string"

static char * buffer = NULL;

static void cleanup(void);

char * ms_make(char format[], ...)
{	if(!buffer)
		atexit(cleanup);
	cleanup();
	va_list arguments;
	va_start(arguments, format);
	int buffer_size = vsnprintf(NULL, 0, format, arguments) + 1;
	ha_assert(buffer_size > 0, LIBRARY_NAME, "buffer size computation failure");
	buffer = malloc(buffer_size);
	ha_assert(buffer, LIBRARY_NAME, "buffer allocation failure");
	ha_assert(vsprintf(buffer, format, arguments) == (buffer_size - 1), LIBRARY_NAME, "buffer initialization failure");
	va_end(arguments);
	return buffer;
}

static void cleanup(void)
{	if(buffer)
		free(buffer);
}
