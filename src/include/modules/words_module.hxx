#pragma once
#include "modules/i_module.hxx"

class cmd_line_params;

class words_module : public i_module {
 public:
  static constexpr std::string_view k_name = "words";

 public:
  void execute(const cmd_line_params& params) override;
};
