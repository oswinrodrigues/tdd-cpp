#include <gmock/gmock.h>
#include <soundex.hpp>

using namespace testing;

class SoundexEncoding: public Test {
public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, KeepsOnlyLetterOfSingleLetterWord) {
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZeroesTillThreeDigits) {
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ConvertsConsonantsToCorrectDigits) {
  ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}
