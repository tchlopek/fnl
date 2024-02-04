project(
  'fnl',
  'cpp',
  default_options: [
    'cpp_std=c++17',
    'warning_level=3'
  ])

inc = include_directories('include')
tsi_dep = subproject('tsi').get_variable('tsi_dep')
fnl_dep = declare_dependency(include_directories: inc, dependencies: tsi_dep)

if get_option('build_utest')
  subdir('test')
endif
