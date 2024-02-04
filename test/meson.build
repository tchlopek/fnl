gtest_sub = subproject('gtest')

ut_deps = [
  gtest_sub.get_variable('gtest_dep'),
  gtest_sub.get_variable('gmock_dep'),
  fnl_dep
]

src_test = [
  'main.cpp',
  'hashmap_test.cpp',
  'option_iter_test.cpp'
]

ut_bin = executable('ut-fnl', src_test, dependencies: ut_deps)

test('Function Extension Library tests', ut_bin)