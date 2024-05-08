#include "cmd_line_params.hxx"
#include <tclap/CmdLine.h>
#include <tclap/ValueArg.h>

cmd_line_params::cmd_line_params()
    : m_instance{"How are you doing?", ' ', "v0.0.1"},
      file_input{"f", "file", "input file", true, "", "string", m_instance},
      work_module{"m",       "module", "module to execute (words|checksum)",
                  true,      "",       "string",
                  m_instance},
      search_word{
          "v",       "word", "specify a word to search with \"words\" module",
          false,     "",     "string",
          m_instance} {}

const cmd_line_params& cmd_line_params::parse(int argc, char* argv[]) {
  static cmd_line_params params;

  if (params.m_instance.getProgramName() != "not_set_yet")
    return params;

  params.m_instance.parse(argc, argv);
  return params;
}
