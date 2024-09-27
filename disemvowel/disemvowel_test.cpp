#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleNoVowels) {
  char* result = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", result);
  free(result);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* result = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", result);
  free(result);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* result = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", result);
  free(result);
}

TEST(Disemvowel, HandlePunctuation) {
  char* result = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", result);
  free(result);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (int i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char* result = disemvowel(str);
  ASSERT_STREQ("xyz", result);

  free(result);  // Free the result of disemvowel()
  free(str);     // Free the original string
}


int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
