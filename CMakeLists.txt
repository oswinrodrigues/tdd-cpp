cmake_minimum_required(VERSION 3.25)
project(cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
  dummy_test
  dummy_test.cpp
)

find_package(GTest
  CONFIG
  REQUIRED
)

find_package(CppUTest
  CONFIG
  REQUIRED
)

find_package(jsoncpp
  CONFIG
  REQUIRED
)

set(Boost_NO_WARN_NEW_VERSIONS 1)
find_package(Boost
  REQUIRED
  COMPONENTS
  date_time
  filesystem
  # 'algorithm' and 'assign' are header-only and already included within Boost
)

target_link_libraries(
  dummy_test
  PRIVATE
  GTest::gtest
  GTest::gtest_main
  GTest::gmock
  GTest::gmock_main
  CppUTest
  CppUTestExt
  JsonCpp::JsonCpp
  Boost::boost
  Boost::date_time
  Boost::filesystem
  # 'algorithm' and 'assign' are header-only and already included within Boost::boost
)

enable_testing()

add_test(
  HelloTest
  dummy_test
)
