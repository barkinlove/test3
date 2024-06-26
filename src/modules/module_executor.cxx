#include "modules/module_executor.hxx"
#include <sys/types.h>
#include <format>
#include <memory>
#include <ranges>
#include <stdexcept>
#include <unordered_map>
#include "cmd_line_params.hxx"
#include "modules/checksum_module.hxx"
#include "modules/i_module.hxx"
#include "modules/words_module.hxx"

namespace {

std::unordered_map<std::string, std::unique_ptr<i_module>> create_modules() {
  std::unordered_map<std::string, std::unique_ptr<i_module>> modules;
  modules[words_module::k_name.data()] = std::make_unique<words_module>();
  modules[checksum_module::k_name.data()] = std::make_unique<checksum_module>();
  return modules;
}

}  // namespace

const module_executor& module_executor::create() {
  static module_executor instance;

  if (!instance.m_modules.empty())
    return instance;

  instance.m_modules = create_modules();
  return instance;
}

void module_executor::work(const std::string& module_name,
                           const cmd_line_params& params) {
  const auto& instance = create();
  auto it = instance.m_modules.find(module_name);
  if (it == instance.m_modules.end())
    throw std::runtime_error(
        std::format("Unknown module \"{}\"", params.work_module.getValue()));
  auto* program_module = it->second.get();
  program_module->execute(params);
}
