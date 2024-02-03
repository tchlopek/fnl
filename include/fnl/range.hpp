#pragma once

#include <utility>

#include <tsi/range.hpp>

namespace fnl {

template<typename first_t, typename last_t>
auto range(first_t&& f, last_t&& l) {
  return tsi::range(std::forward<first_t>(f), std::forward<last_t>(l));
}

}
