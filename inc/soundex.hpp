#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string>

class Soundex {
public:
  std::string encode(const std::string& word) const {
    return zeroPad(getHead(word) + getDigits(word));
  }
private:
  static constexpr size_t maxCodeLength = 4;

  std::string getHead(const std::string& word) const {
    return word.substr(0, 1);
  }
  std::string getDigits(const std::string& word) const {
    if (word.length() > 1) { return getDigit(word[1]); }
    return "";
  }
  std::string getDigit(char letter) const {
    const std::unordered_map<char, std::string> encodings {
      {'b', "1"},
      {'c', "2"},
      {'d', "3"}
    };
    return encodings.find(letter)->second;
  }
  std::string zeroPad(const std::string& word) const {
    auto zeroCount = maxCodeLength - word.length();
    return word + std::string(zeroCount, '0');
  }
};

#endif
