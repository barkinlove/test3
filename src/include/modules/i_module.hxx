#pragma once
#include "cmd_line_params.hxx"

struct i_module {
  virtual void execute(const cmd_line_params& params) = 0;
};
