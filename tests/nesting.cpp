#include <gtest/gtest.h>
#include <make_string.hpp>
#include <cstring>

TEST(make_string, nesting)
{	char * float_string = strdup(make_string("float : %.2f", 65.287));
	ASSERT_STREQ(float_string, "float : 65.29");

	char * char_string = make_string("char : %c", 'a');
	ASSERT_STREQ(char_string, "char : a");

	char * result_string = make_string("%s\n%s\n", float_string, char_string);
	ASSERT_STREQ(result_string, "float : 65.29\nchar : a\n");

	free(float_string);
}
