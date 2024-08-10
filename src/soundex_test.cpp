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
  // "Vowel-ish" letters = a,e,i,o,u + w,h,y
  ASSERT_THAT(soundex.encode("Baeiouwhycdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateAdjacentEncodings) {
  ASSERT_THAT(soundex.getDigit('b'), Eq(soundex.getDigit('f')));
  ASSERT_THAT(soundex.getDigit('c'), Eq(soundex.getDigit('g')));
  ASSERT_THAT(soundex.getDigit('d'), Eq(soundex.getDigit('t')));
  ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, DropsSecondLetterEncodingIfSameAsFirstLetter) {
  ASSERT_THAT(soundex.encode("Bbcd"), Eq("B230"));
}

TEST_F(SoundexEncoding, CapitalizesHead) {
  ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoresTailCase) {
  ASSERT_THAT(soundex.encode("Abcd"), Eq(soundex.encode("ABCD")));
}

TEST_F(SoundexEncoding, DuplicatesAdjacentEncodingsWhenSeparatedByVowels) {
  // "Vowel" letters = a,e,i,o,u + y (excludes w,h)
  ASSERT_THAT(soundex.encode("Jbob"), Eq("J110"));
}
