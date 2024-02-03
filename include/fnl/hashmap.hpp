#pragma once

#include <tsi/iter.hpp>
#include <tsi/range/view_range.hpp>
#include <unordered_map>

namespace fnl {

template<
  typename key_t,
  typename val_t,
  typename hash_t = std::hash<key_t>,
  typename eq_t = std::equal_to<key_t>,
  typename alloc_t = std::allocator<std::pair<const key_t, val_t>>>
class hashmap : private std::unordered_map<key_t, val_t, hash_t, eq_t, alloc_t> {

  using base_t = std::unordered_map<key_t, val_t, hash_t, eq_t, alloc_t>;

public:
  using key_type = typename base_t::key_type;
  using mapped_type = typename base_t::mapped_type;
  using hasher = typename base_t::hasher;
  using key_equal = typename base_t::key_equal;
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
  using local_iterator = typename base_t::local_iterator;
  using const_local_iterator = typename base_t::const_local_iterator;
  using node_type = typename base_t::node_type;
  using insert_return_type = typename base_t::insert_return_type;

  using base_t::unordered_map;
  using base_t::operator=;
  using base_t::get_allocator;

  using base_t::begin;
  using base_t::cbegin;
  using base_t::end;
  using base_t::cend;

  using base_t::empty;
  using base_t::size;
  using base_t::max_size;

  using base_t::clear;
  using base_t::insert;
  using base_t::insert_or_assign;
  using base_t::emplace;
  using base_t::emplace_hint;
  using base_t::try_emplace;
  using base_t::erase;
  using base_t::swap;
  using base_t::extract;
  using base_t::merge;

  using base_t::at;
  using base_t::operator[];
  using base_t::count;
  using base_t::equal_range;

  using base_t::bucket_count;
  using base_t::max_bucket_count;
  using base_t::bucket_size;
  using base_t::bucket;

  using base_t::load_factor;
  using base_t::max_load_factor;
  using base_t::rehash;
  using base_t::reserve;

  using base_t::hash_function;
  using base_t::key_eq;

  bool contains(const key_t& key) const {
    return count(key) == 1;
  }

  friend bool operator==(const hashmap& lhs, const hashmap& rhs) {
    return lhs == rhs;
  }

  friend bool operator!=(const hashmap& lhs, const hashmap& rhs) {
    return lhs != rhs;
  }

  friend void swap(hashmap& lhs, hashmap& rhs) noexcept(noexcept(lhs.swap(rhs))) {
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

}
