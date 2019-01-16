#include "aligned_buffer.h"

using TU8 = uint8_t;

bool Compare(size_t from, const void* buf_ptr, size_t length) {
  const TU8* comp_ptr = static_cast<const TU8*>(buf_ptr);
  return false;
}
