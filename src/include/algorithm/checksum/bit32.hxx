#pragma once
#include <cstdint>
#include <string_view>

namespace algorithm {

namespace checksum {

uint32_t bit32(std::string_view data);

}

}  // namespace algorithm
