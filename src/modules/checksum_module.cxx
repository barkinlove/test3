#include "modules/checksum_module.hxx"
#include <filesystem>
#include <fstream>
#include <string>
#include "algorithm/checksum/bit32.hxx"
#include "cmd_line_params.hxx"

void checksum_module::execute(const cmd_line_params& params) {
  auto filepath = std::filesystem::path{params.file_input.getValue()};

  std::ostringstream ss;
  std::ifstream file{filepath};
  ss << file.rdbuf();

  uint32_t checksum = algorithm::checksum::bit32(ss.str());
  std::cout << checksum << '\n';
}
