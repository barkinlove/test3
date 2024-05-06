#include <tclap/CmdLine.h>
#include <tclap/ValueArg.h>
#include <cstdlib>

class cmd final {
 public:
  cmd(const std::string& desc, char delimeter, const std::string& version)
      : m_instance{desc, delimeter, version} {
    setup_options();
  }

  void parse(int argc, char* argv[]) { m_instance.parse(argc, argv); }

 private:
  void setup_options() {
    TCLAP::ValueArg<std::string> input_file{"f",  "file", "input file",
                                            true, "",     "string"};
    m_instance.add(input_file);

    TCLAP::ValueArg<std::string> work_module{
        "m", "module", "module to execute", true, "", "string"};
    m_instance.add(work_module);
  }

 private:
  TCLAP::CmdLine m_instance;
};

void setup_cmd_options() {}

int main(int argc, char* argv[]) {
  try {
    cmd cmd_instance{"How are you doing?", ' ', "v0.0.1"};
    cmd_instance.parse(argc, argv);

  } catch (std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return EXIT_SUCCESS;
}
