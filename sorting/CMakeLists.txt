add_library(
  sorting STATIC
  sorting.h
  sorting.cc
)
add_executable(sorting_test sorting_test.cc)
target_link_libraries(sorting_test sorting gmock_main)
add_test(NAME test COMMAND sorting_test)