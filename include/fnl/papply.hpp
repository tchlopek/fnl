#pragma once

#include <tuple>
#include <utility>

namespace fnl {

namespace _detail {
template<typename... ts>
auto tuple_refs(const std::tuple<ts...>& t) {
  return std::apply([](auto&&... args){
    return std::forward_as_tuple(args...);
  }, t);
}
}

template<typename fn_t, typename... cap_t>
auto papply(fn_t&& fn, cap_t&&... caps) {
  return [
    fn = std::forward<fn_t>(fn),
    caps = std::tuple{ std::forward<cap_t>(caps)... }
  ] (auto&&... args) {
    return std::apply(fn, std::tuple_cat(
      _detail::tuple_refs(caps),
      std::forward_as_tuple(std::forward<decltype(args)>(args)...)
    ));
  };
}

}

