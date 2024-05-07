#include <cstdlib>
#include <fstream>
#include <functional>
#include <stdexcept>
#include "cmd_line_params.hxx"
#include "modules/module_executor.hxx"

int main(int argc, char* argv[]) {
  try {
    auto& params = cmd_line_params::parse(argc, argv);

    // params dont work, figure out why

    module_executor::work(params.work_module.getValue(), params);

  } catch (std::exception& e) {
    std::cerr << e.what() << '\n';
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
