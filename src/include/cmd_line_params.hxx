#pragma once

#include <tclap/CmdLine.h>
#include <cstdlib>
#include <memory>

// Actually, it'd be better to create a cmd line (or cmd params) interface to
// be able to switch the internal argument parsing library without much effort.
// Don't have much time to design it thoroughly. Seems not so trivial at the
// first glance.

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
