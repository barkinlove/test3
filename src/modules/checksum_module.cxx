#include "modules/checksum_module.hxx"
#include <filesystem>
#include <format>
#include <fstream>
#include <string>
#include "algorithm/checksum/bit32.hxx"
#include "cmd_line_params.hxx"

void checksum_module::execute(const cmd_line_params& params) {
  if (!std::filesystem::exists(params.file_input.getValue())) {
    throw std::runtime_error("error: specified file does not exist");
  }

  auto filepath = std::filesystem::path{params.file_input.getValue()};

  std::ostringstream ss;
  std::ifstream file{filepath};
  ss << file.rdbuf();

  uint32_t checksum = algorithm::checksum::bit32(ss.str());
  std::cout << std::format("Checksum: {}", checksum) << '\n';
}
