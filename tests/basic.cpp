#include <gtest/gtest.h>
#include <make_string.hpp>

TEST(make_string, basic)
{	EXPECT_STREQ(make_string("%i%c", 1, 'a'), "1a");
}
