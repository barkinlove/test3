#include "algorithm/word_count.hxx"
#include <string>

namespace algorithm {

size_t count_word(std::string_view data, std::string_view word) {
  size_t count = 0, offset = 0;

  while (true) {
    size_t match_beginning = data.find(word, offset);

    if (match_beginning == std::string::npos)
      break;

    offset = match_beginning + word.size();

    size_t match_end = match_beginning + word.size();

    if (match_end < data.size() && data[match_end] != ' ') {
      continue;
    }

    if (match_beginning > 0 && data[match_beginning - 1] != ' ') {
      continue;
    }

    ++count;
  }

  return count;
}

}  // namespace algorithm
