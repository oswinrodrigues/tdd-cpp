#include <gtest/gtest.h>

class Soundex {};

TEST(SoundexEncoding, KeepsOnlyLetterOfSingleLetterWord) {
  Soundex soundex;
  auto encoded = soundex.encode("A");
}
