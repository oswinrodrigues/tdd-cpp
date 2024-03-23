cmake_minimum_required(VERSION 3.25)
project(tdd-cpp)

# define required C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# define required C++ libraries
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
set(Boost_NO_WARN_NEW_VERSIONS 1) # suppresses version warnings (optional)
find_package(Boost
  REQUIRED
  COMPONENTS
  date_time
  filesystem
  # 'algorithm' and 'assign' are header-only and already included within Boost
)

# map source and link libraries to executable
add_executable(
  dummy_test
  dummy_test.cpp
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

# setup testing functionality
enable_testing()
add_test(
  HelloTest
  dummy_test
)
