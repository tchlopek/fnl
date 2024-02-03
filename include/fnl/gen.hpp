#pragma once

#include <tsi/gen.hpp>

namespace fnl {

template<typename val_t>
auto gen(const val_t& v) {
  return tsi::gen(v);
}

}
