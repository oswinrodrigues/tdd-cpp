#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string>

class Soundex {
public:
  std::string encode(const std::string& word) const {
    return zeroPad(getCapitalHead(word) + getDigits(getTail(word)));
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
private:
  static constexpr size_t maxCodeLength = 4;

  std::string getCapitalHead(const std::string& word) const {
    return std::string(1, std::toupper(word.front()));
  }

  std::string getTail(const std::string& word) const {
    return word.substr(1);
  }

  std::string getDigits(const std::string& word) const {
    std::string encoding;
    for (auto letter : word) {
      if (isMaxLength(encoding)) { break; }

      auto lowerCaseLetter = std::tolower(letter);
      auto newDigit = getDigit(lowerCaseLetter);
      if (newDigit == getLastDigit(encoding)) { continue; }

      encoding += newDigit;
    }
    return encoding;
  }

  std::string getLastDigit(const std::string& encoding) const {
    if (encoding.empty()) { return ""; }
    return std::string(1, encoding.back());
  }

  std::string zeroPad(const std::string& encoding) const {
    auto zeroCount = maxCodeLength - encoding.length();
    return encoding + std::string(zeroCount, '0');
  }

  bool isMaxLength(const std::string& encoding) const {
    return encoding.length() == maxCodeLength - 1;
  }
};

#endif
