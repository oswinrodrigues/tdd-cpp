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

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
  ASSERT_THAT(soundex.encode("A$"), Eq("A000"));
}

TEST_F(SoundexEncoding, ConvertsMultipleConsonantsToCorrectDigits) {
  ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
  ASSERT_THAT(soundex.encode("Pqrstabcd").length(), Eq(4));
}

TEST_F(SoundexEncoding, DropsVowelishLetters) {
  ASSERT_THAT(soundex.encode("Baeiouwhycdl"), Eq("B234"));
}
