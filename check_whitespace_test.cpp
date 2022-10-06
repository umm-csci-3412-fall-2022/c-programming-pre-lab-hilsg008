#include <gtest/gtest.h>

#include "check_whitespace.h"

void test(const char* correct, const char* toBeTested) {
    const char *result = strip(toBeTested);
    ASSERT_STREQ(correct, result);
    free((char*)result);
}

TEST(strip, EmptyString) {
    const char* testStr = strip("");
    ASSERT_STREQ("", testStr);
}

TEST(strip, NoWhitespace) {
    test("frog","frog");
}

TEST(strip, WhitespaceOnFront) {
    test("frog","   frog");
}

TEST(strip, WhitespaceOnBack) {
    test("frog", "frog  ");
}

TEST(strip, WhitespaceOnBothEnds) {
    test("frog", "  frog     ");
}

TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris  "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean(" University of Minnesota Morris"    ));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}