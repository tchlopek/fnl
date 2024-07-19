#pragma once

#include <tsi/iter.hpp>
#include <tsi/range/view_range.hpp>
#include <vector>

namespace fnl {

template<typename val_t, typename alloc_t = std::allocator<val_t>>
class vec : private std::vector<val_t, alloc_t> {

  using base_t = std::vector<val_t, alloc_t>;

public:
  using value_type = typename base_t::value_type;
  using allocator_type = typename base_t::allocator_type;
  using size_type = typename base_t::size_type;
  using difference_type = typename base_t::difference_type;
  using reference = typename base_t::reference;
  using const_reference = typename base_t::const_reference;
  using pointer = typename base_t::pointer;
  using const_pointer = typename base_t::const_pointer;
  using iterator = typename base_t::iterator;
  using const_iterator = typename base_t::const_iterator;
  using reverse_iterator = typename base_t::reverse_iterator;
  using const_reverse_iterator = typename base_t::const_reverse_iterator;

  using base_t::vector;
  using base_t::operator=;
  using base_t::assign;
  using base_t::get_allocator;

  using base_t::at;
  using base_t::operator[];
  using base_t::front;
  using base_t::back;
  using base_t::data;

  using base_t::begin;
  using base_t::cbegin;
  using base_t::end;
  using base_t::cend;
  using base_t::rbegin;
  using base_t::crbegin;
  using base_t::rend;
  using base_t::crend;

  using base_t::empty;
  using base_t::size;
  using base_t::max_size;
  using base_t::reserve;
  using base_t::capacity;

  using base_t::clear;
  using base_t::insert;
  using base_t::emplace;
  using base_t::erase;
  using base_t::push_back;
  using base_t::emplace_back;
  using base_t::pop_back;
  using base_t::resize;
  using base_t::swap;

  vec(std::initializer_list<val_t> ilist, const alloc_t& a = alloc_t())
    : base_t(ilist, a)
  {}

  friend bool operator==(const vec& lhs, const vec& rhs) {
    return lhs == rhs;
  }

  friend bool operator!=(const vec& lhs, const vec& rhs) {
    return lhs != rhs;
  }

  friend bool operator<(const vec& lhs, const vec& rhs) {
    return lhs < rhs;
  }

  friend bool operator<=(const vec& lhs, const vec& rhs) {
    return lhs <= rhs;
  }

  friend bool operator>(const vec& lhs, const vec& rhs) {
    return lhs > rhs;
  }

  friend bool operator>=(const vec& lhs, const vec& rhs) {
    return lhs >= rhs;
  }

  friend void swap(vec& lhs, vec& rhs) noexcept(noexcept(lhs.swap(rhs))) {
    lhs.swap(rhs);
  }

  auto iter() & {
    return tsi::iter(tsi::rng::view_range{ begin(), end() });
  }

  auto iter() const& {
    return tsi::iter(tsi::rng::view_range{ cbegin(), cend() });
  }

  auto iter() && {
    return tsi::iter(std::move(*this));
  }

private:
};

template<
  typename iter_t,
  typename alloc_t = std::allocator<
    typename std::iterator_traits<iter_t>::value_type
  >
>
vec(iter_t, iter_t, alloc_t = alloc_t()) -> vec<
  typename std::iterator_traits<iter_t>::value_type,
  alloc_t
>;

template<typename val_t, typename alloc_t = std::allocator<val_t>>
vec(std::initializer_list<val_t>, alloc_t = alloc_t()) -> vec<val_t, alloc_t>;

}
