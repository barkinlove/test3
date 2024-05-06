#include <tclap/CmdLine.h>
#include <tclap/ValueArg.h>
#include <cstdlib>

class command_module {
  virtual void execute() = 0;
};

class words_module final : public command_module {
  void execute() override {}
};

class checksum_module final : public command_module {
  void execute() override {}
};

int main(int argc, char* argv[]) {
  try {
    TCLAP::ValueArg<std::string> input_file{"f",  "file", "input file",
                                            true, "",     "string"};
    TCLAP::CmdLine commandline{"how do you do?", ' ', "0.0.1"};
    commandline.add(input_file);
    commandline.parse(argc, argv);

    auto value = input_file.getValue();
    std::cout << value << '\n';
  } catch (std::exception& e) {
    std::cerr << e.what() << '\n';
  }
  return EXIT_SUCCESS;
}
