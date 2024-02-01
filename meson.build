project(
    'fnl',
    'cpp',
    default_options: [
        'cpp_std=c++17',
        'warning_level=3'
    ])

inc = include_directories('include')
cppiter_dep = subproject('cppiter').get_variable('cppiter_dep')
fnl_dep = declare_dependency(
  include_directories: inc,
  dependencies: cppiter_dep
)

