#include <gmock/gmock.h>
using testing::Eq;

class Soundex {
public:
  std::string encode(const std::string& word) const {
    return zeroPad(word);
  }
private:
  std::string zeroPad(const std::string& word) const {
    return word + "000";
  }
};

class SoundexEncoding: public testing::Test {
public:
  Soundex soundex;
};

TEST_F(SoundexEncoding, KeepsOnlyLetterOfSingleLetterWord) {
  ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZeroesTillThreeDigits) {
  ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}
