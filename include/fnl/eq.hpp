#pragma once

#include <utility>

namespace fnl {

template<typename capture_t>
auto eq(capture_t&& cap) {
  return [cap = std::forward<capture_t>(cap)](auto&& arg) {
    return std::forward<decltype(arg)>(arg) == cap;
  };
}

}
