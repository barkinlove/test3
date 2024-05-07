#pragma once
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include "cmd_line_params.hxx"
#include "modules/i_module.hxx"

class module_executor final {
 private:
  module_executor() = default;
  ~module_executor() = default;
  module_executor(const module_executor&) = delete;
  module_executor& operator=(const module_executor&) = delete;

 private:
  std::unordered_map<std::string, std::unique_ptr<i_module>> m_modules;

 public:
  static const module_executor& create();
  static void work(const std::string& module_name,
                   const cmd_line_params& params);
};
