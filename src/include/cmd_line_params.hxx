#pragma once

#include <tclap/CmdLine.h>
#include <cstdlib>
#include <memory>

class cmd_line_params final {
 private:
  cmd_line_params();
  ~cmd_line_params() = default;
  cmd_line_params(const cmd_line_params&) = delete;
  cmd_line_params& operator=(const cmd_line_params&) = delete;

 private:
  TCLAP::CmdLine m_instance;

 public:
  static const cmd_line_params& parse(int argc, char* argv[]);

 public:
  TCLAP::ValueArg<std::string> file_input;
  TCLAP::ValueArg<std::string> work_module;
  TCLAP::ValueArg<std::string> search_word;
};
