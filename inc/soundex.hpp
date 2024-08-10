#ifndef SOUNDEX_HPP
#define SOUNDEX_HPP

#include <string>

class Soundex {
public:
  std::string encode(const std::string& word) const {
    auto capitalHead = capitalizeLetter(getHead(word));
    auto encodedTail = getTail(getDigits(word));
    return zeroPad(capitalHead + encodedTail);
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
    auto sanitizedLetter = std::tolower(letter);
    auto it = encodings.find(sanitizedLetter);
    return it == encodings.end() ? notADigit : it->second;
  }
private:
  static constexpr size_t maxCodeLength = 4;
  static constexpr std::string notADigit = "*";

  char getHead(const std::string& word) const {
    return word.front();
  }

  std::string getTail(const std::string& word) const {
    return word.substr(1);
  }

  std::string capitalizeLetter(char letter) const {
    return std::string(1, std::toupper(letter));
  }

  std::string getDigits(const std::string& word) const {
    std::string encoding;
    encodeHead(word, encoding);
    encodeTail(word, encoding);
    return encoding;
  }

  void encodeHead(const std::string& word, std::string& encoding) const {
    encoding += getDigit(getHead(word));
  }

  void encodeTail(const std::string& word, std::string& encoding) const {
    for (auto i = 1u ; i < word.length(); i++) {
      if (isMaxLength(encoding)) { break; }
      encodeTailLetter(word[i], word[i-1], encoding);
    }
  }

  void encodeTailLetter(char letter, char lastLetter, std::string& encoding) const {
      auto newDigit = getDigit(letter);
      if (newDigit == notADigit) { return; }
      if (newDigit == getLastDigit(encoding) && !isVowel(lastLetter)) { return; }
      encoding += newDigit;
  }

  std::string getLastDigit(const std::string& encoding) const {
    if (encoding.empty()) { return notADigit; }
    return std::string(1, encoding.back());
  }

  bool isVowel(char letter) const {
    auto setOfVowels = std::string("aeiouy");
    auto sanitizedLetter = std::tolower(letter);
    auto findResult = setOfVowels.find(sanitizedLetter);
    return findResult != std::string::npos;
  }

  std::string zeroPad(const std::string& encoding) const {
    auto zeroCount = maxCodeLength - encoding.length();
    return encoding + std::string(zeroCount, '0');
  }

  bool isMaxLength(const std::string& encoding) const {
    return encoding.length() == maxCodeLength;
  }
};

#endif
