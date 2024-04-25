#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string>

class Soundex {
public:
  std::string encode(const std::string& word) const {
    return zeroPad(getHead(word) + getDigits(getTail(word)));
  }
private:
  static constexpr size_t maxCodeLength = 4;

  std::string getHead(const std::string& word) const {
    return word.substr(0, 1);
  }
  std::string getTail(const std::string& word) const {
    return word.substr(1);
  }
  std::string getDigits(const std::string& word) const {
    std::string encoding;
    for (auto letter : word) {
      encoding += getDigit(letter);
    }
    return encoding;
  }
  std::string getDigit(char letter) const {
    const std::unordered_map<char, std::string> encodings {
      {'b', "1"},
      {'f', "1"},
      {'p', "1"},
      {'v', "1"},
      {'c', "2"},
      {'g', "2"},
      {'j', "2"},
      {'k', "2"},
      {'q', "2"},
      {'s', "2"},
      {'x', "2"},
      {'z', "2"},
      {'d', "3"},
      {'t', "3"},
      {'l', "4"},
      {'m', "5"},
      {'n', "5"},
      {'r', "6"}
    };
    auto it = encodings.find(letter);
    return it == encodings.end() ? "" : it->second;
  }
  std::string zeroPad(const std::string& word) const {
    auto zeroCount = maxCodeLength - word.length();
    return word + std::string(zeroCount, '0');
  }
};

#endif
