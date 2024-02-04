#pragma once

#include <optional>
#include <iterator>

namespace fnl::util {

template<typename iter_t>
class option_iter : public std::iterator_traits<iter_t> {
public:
  option_iter() = default;
  explicit option_iter(iter_t&& it)
    : m_it{ std::move(it) }
  {}

  decltype(auto) operator*() const {
    return base().operator*();
  }

  decltype(auto) operator->() const {
    return base().operator->();
  }

  option_iter& operator++() {
    ++base_mut();
    return *this;
  }

  option_iter operator++(int) {
    auto tmp = *this;
    base_mut()++;
    return tmp;
  }

  bool operator==(const option_iter& other) const {
    return *this && other && base() == other.base();
  }

  bool operator!=(const option_iter& other) const {
    return !(*this == other);
  }

  explicit operator bool() const {
    return m_it.has_value();
  }

  const iter_t& base() const {
    return m_it.value();
  }

private:
  iter_t& base_mut() {
    return m_it.value();
  }

  std::optional<iter_t> m_it;
};

}
