#include <algorithm>

#include "util/option_iter.hpp"

namespace fnl {

template<typename range_t, typename pred_t>
auto find(const range_t& range, pred_t&& pred) {
  auto it = std::find_if(
    std::begin(range),
    std::end(range),
    std::forward<pred_t>(pred)
  );

  return it != std::end(range) ? util::option_iter{ std::move(it) } : util::none;
}

}