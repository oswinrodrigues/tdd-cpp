#ifndef STRING_UTIL_HPP
#define STRING_UTIL_HPP

#include <string>

namespace str_util {

static constexpr std::string charToString(char letter) {
    return std::string(1, letter);
}

static constexpr std::string zeroPad(const std::string& string, uint32_t maxLength) {
    auto zeroCount = maxLength - string.length();
    return string + std::string(zeroCount, '0');
}

static constexpr bool isLetterInString(char letter, const std::string& string) {
    auto findResult = string.find(letter);
    return findResult != std::string::npos;
}

static constexpr auto setOfVowels = std::string("aeiouy");
static constexpr bool isVowel(char letter) {
    auto sanitizedLetter = tolower(letter);
    return isLetterInString(sanitizedLetter, setOfVowels);
}

} // namespace

#endif
