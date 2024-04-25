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
  EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
  EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
  EXPECT_THAT(soundex.encode("Ad"), Eq("A300"));
}
