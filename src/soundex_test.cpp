#include <gtest/gtest.h>

class Soundex {
public:
  std::string encode(const std::string& word) const{
    return "";
  }
};

TEST(SoundexEncoding, KeepsOnlyLetterOfSingleLetterWord) {
  Soundex soundex;
  auto encoded = soundex.encode("A");
}
