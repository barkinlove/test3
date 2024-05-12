#include "algorithm/checksum/bit32.hxx"

namespace algorithm {

namespace checksum {

uint32_t bit32(std::string_view data) {
  uint32_t checksum = 0, shift = 0;

  for (uint32_t ch : data) {
    checksum += (ch << shift);
    shift = shift == 32 ? 0 : shift + 8;
  }

  return checksum;
}

}  // namespace checksum

}  // namespace algorithm
