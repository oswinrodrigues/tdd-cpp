#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string>

class Soundex {
public:
  std::string encode(const std::string& word) const {
    return zeroPad(getHead(word) + getDigits(word));
  }
private:
  std::string getHead(const std::string& word) const {
    return word.substr(0, 1);
  }
  std::string getDigits(const std::string& word) const {
    if (word.length() > 1) { return "1"; }
    return "";
  }
  std::string zeroPad(const std::string& word) const {
    auto zeroCount = 4 - word.length();
    return word + std::string(zeroCount, '0');
  }
};

#endif
