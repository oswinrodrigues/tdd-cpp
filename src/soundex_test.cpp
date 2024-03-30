#include <gmock/gmock.h>
using testing::Eq;

class Soundex {
public:
  std::string encode(const std::string& word) const{
    return word + "000";
  }
};

TEST(SoundexEncoding, KeepsOnlyLetterOfSingleLetterWord) {
  Soundex soundex;
  auto encoded = soundex.encode("A");
  ASSERT_THAT(encoded, Eq("A"));
}

TEST(SoundexEncoding, PadsWithZeroesTillThreeDigits) {
  Soundex soundex;
  auto encoded = soundex.encode("I");
  ASSERT_THAT(encoded, Eq("I000"));
}
