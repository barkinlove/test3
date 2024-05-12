#include "modules/words_module.hxx"
#include <filesystem>
#include <format>
#include <fstream>
#include <stdexcept>
#include <string>
#include "cmd_line_params.hxx"

#include "algorithm/word_count.hxx"

void words_module::execute(const cmd_line_params& params) {
  if (params.search_word.getValue().empty()) {
    throw std::runtime_error("no search word provided");
  }

  auto filepath = std::filesystem::path{params.file_input.getValue()};
  std::string_view word = params.search_word.getValue();

  size_t count = 0;

  std::ifstream file{filepath};
  std::string data{};
  while (std::getline(file, data)) {
    count += algorithm::count_word(data, word);
  }
  std::cout << std::format("The number of \"{}\" if file \"{}\" is {}", word,
                           filepath.filename().string(), count)
            << '\n';
}
