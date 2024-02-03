#pragma once

#include <utility>

#include <tsi/zip.hpp>

namespace fnl {

template<typename... range_ts>
auto zip(range_ts&&... rs) {
  return tsi::zip(std::forward<range_ts>(rs)...);
}

}
